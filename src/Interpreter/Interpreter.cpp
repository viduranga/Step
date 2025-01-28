#include <Interpreter/Interpreter.h>
#include <Interpreter/Function.h>
#include <Interpreter/Loop.h>
#include <StepLang/StepLangVisitor.h>

Interpreter::Interpreter() = default;

Program Interpreter::parse(const std::string &code)
{
  antlr4::ANTLRInputStream input_stream{ code };
  StepLangLexer lexer{ &input_stream };
  antlr4::CommonTokenStream tokens{ &lexer };
  StepLangParser parser{ &tokens };
  auto *program_tree = parser.program();

  return std::any_cast<Program>(visitProgram(program_tree));
}

std::any Interpreter::visitProgram(StepLangParser::ProgramContext *ctx)
{
  Program program;

  for (auto *function_context : ctx->function()) {
    auto function = std::any_cast<DebugWrap<Function>>(visitFunction(function_context));
    program[(*function).name] = function;
  }
  program[FUNC_MAIN] = std::any_cast<DebugWrap<Function>>(visitMain(ctx->main()));

  return program;
}

std::any Interpreter::visitMain(StepLangParser::MainContext *ctx)
{
  Function function;
  function.name = FUNC_MAIN;
  function.statements = std::any_cast<Body>(visitBody(ctx->body()));

  return DebugWrap<Function>{ function, { 0, 0 } };
}

std::any Interpreter::visitFunction(StepLangParser::FunctionContext *ctx)
{
  Function function;

  auto header = std::any_cast<std::tuple<char, std::vector<char>>>(visitHeader(ctx->header()));
  function.name = std::get<0>(header);
  function.parameters = std::get<1>(header);

  function.statements = std::any_cast<Body>(visitBody(ctx->body()));

  auto *start = ctx->getStart();
  return DebugWrap<Function>{ function, { start->getLine(), start->getCharPositionInLine() } };
}

std::any Interpreter::visitHeader(StepLangParser::HeaderContext *ctx)
{
  char name = ctx->IDENTIFIER()->getText()[0];
  std::vector<char> parameters;

  if (ctx->variable_list()) {
    parameters = std::any_cast<std::vector<char>>(visitVariable_list(ctx->variable_list()));
  }

  return std::tuple<char, std::vector<char>>{ name, parameters };
}

std::any Interpreter::visitBody(StepLangParser::BodyContext *ctx)
{
  Body body;

  auto body_contexts = ctx->statement();

  body.reserve(body_contexts.size());
  for (auto *context : body_contexts) {
    body.push_back(std::any_cast<DebugWrap<Statement>>(visitStatement(context)));
  }
  return body;
}

std::any Interpreter::visitStatement(StepLangParser::StatementContext *ctx)
{
  Statement statement;
  if (ctx->loop()) {
    statement = std::any_cast<Loop>(visitLoop(ctx->loop()));
  } else if (ctx->invocation()) {
    statement = std::any_cast<Invocation>(visitInvocation(ctx->invocation()));
  } else
    statement = static_cast<ACTION>(ctx->ACTION()->getText()[0]);

  auto *start = ctx->getStart();
  return DebugWrap<Statement>{ statement, { start->getLine(), start->getCharPositionInLine() } };
}

std::any Interpreter::visitVariable_list(StepLangParser::Variable_listContext *ctx)
{
  std::vector<char> variable_list;
  auto token_list = ctx->IDENTIFIER();

  variable_list.reserve(token_list.size());
  for (auto *token : token_list) {
    variable_list.push_back(token->getText()[0]);
  }

  return variable_list;
}

std::any Interpreter::visitInvocation(StepLangParser::InvocationContext *ctx)
{
  Invocation invocation;
  invocation.function = ctx->IDENTIFIER()->getText()[0];

  auto *expression_list = ctx->expression_list();
  if (expression_list)
    invocation.arguments = std::any_cast<std::vector<std::string>>(visitExpression_list(expression_list));
  return invocation;
}

std::any Interpreter::visitExpression_list(StepLangParser::Expression_listContext *ctx)
{
  std::vector<std::string> expression_list;

  auto expressions = ctx->expression();

  expression_list.reserve(expressions.size());

  for (auto *expression : expressions) {
    expression_list.push_back(std::any_cast<std::string>(visitExpression(expression)));
  }

  return expression_list;
}

std::any Interpreter::visitLoop(StepLangParser::LoopContext *ctx)
{
  Loop loop;
  loop.condition = std::any_cast<std::string>(visitExpression(ctx->expression()));
  loop.statements = std::any_cast<Body>(visitBody(ctx->body()));
  return loop;
}

std::any Interpreter::visitExpression(StepLangParser::ExpressionContext *ctx)
{
  return ctx->getText();
}
