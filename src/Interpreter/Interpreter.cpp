#include <Interpreter/Interpreter.h>
#include <Interpreter/Function.h>
#include <Interpreter/Loop.h>
#include <StepLang/StepLangVisitor.h>

Interpreter::Interpreter()
= default;

Program Interpreter::parse(const std::string &code) {
    antlr4::ANTLRInputStream input_stream{code};
    StepLangLexer lexer{&input_stream};
    antlr4::CommonTokenStream tokens{&lexer};
    StepLangParser parser{&tokens};
    auto* program_tree = parser.program();

    return visitProgram(program_tree).as<Program>();
}

antlrcpp::Any Interpreter::visitProgram(StepLangParser::ProgramContext *ctx) {
    Program program;

    for(auto function_context: ctx->function()){
        DebugWrap<Function> function = visitFunction(function_context).as<DebugWrap<Function>>();
        program[(*function).name] = function;
    }
    program[FUNC_MAIN] = visitMain(ctx->main()).as<DebugWrap<Function>>();

    return program;
}

antlrcpp::Any Interpreter::visitMain(StepLangParser::MainContext *ctx) {
    Function function;
    function.name = FUNC_MAIN;
    function.statements = visitBody(ctx->body()).as<Body>();

    return DebugWrap<Function>{function, {0,0}};
}

antlrcpp::Any Interpreter::visitFunction(StepLangParser::FunctionContext *ctx) {
    Function function;

    auto header = visitHeader(ctx->header()).as<std::tuple<char, std::vector<char>>>();
    function.name = std::get<0>(header);
    function.parameters = std::get<1>(header);

    function.statements = visitBody(ctx->body()).as<Body>();

    auto *start = ctx->getStart();
    return DebugWrap<Function>{function, {start->getLine(),start->getCharPositionInLine()}};
}

antlrcpp::Any Interpreter::visitHeader(StepLangParser::HeaderContext *ctx) {
    char name = ctx->IDENTIFIER()->getText()[0];
    std::vector<char> parameters;
    
    if(ctx->variable_list())
        parameters = visitVariable_list(ctx->variable_list()).as<std::vector<char>>();

    return std::tuple<char, std::vector<char>>{name, parameters};
}

antlrcpp::Any Interpreter::visitBody(StepLangParser::BodyContext *ctx) {
    Body body;

    auto body_contexts = ctx->statement();

    body.reserve(body_contexts.size());
    for(auto context: body_contexts){
        body.push_back(visitStatement(context).as<DebugWrap<Statement>>());
    }
    return body;
}

antlrcpp::Any Interpreter::visitStatement(StepLangParser::StatementContext *ctx) {
    Statement statement;
    if(ctx->loop()) {
        statement = visitLoop(ctx->loop()).as<Loop>();
    } else if(ctx->invocation()) {
        statement = visitInvocation(ctx->invocation()).as<Invocation>();
    } else
        statement = static_cast<ACTION>(ctx->ACTION()->getText()[0]);

    auto *start = ctx->getStart();
    return DebugWrap<Statement>{statement, {start->getLine(),start->getCharPositionInLine()}};
}

antlrcpp::Any Interpreter::visitVariable_list(StepLangParser::Variable_listContext *ctx) {
    std::vector<char> variable_list;
    auto token_list = ctx->IDENTIFIER();

    variable_list.reserve(token_list.size());
    for(auto *token: token_list) {
        variable_list.push_back(token->getText()[0]);
    }

    return variable_list;
}

antlrcpp::Any Interpreter::visitInvocation(StepLangParser::InvocationContext *ctx) {
    Invocation invocation;
    invocation.function = ctx->IDENTIFIER()->getText()[0];

    auto expression_list = ctx->expression_list();
    if(expression_list)
        invocation.arguments = visitExpression_list(expression_list).as<std::vector<std::string>>();
    return invocation;
}

antlrcpp::Any Interpreter::visitExpression_list(StepLangParser::Expression_listContext *ctx) {
    std::vector<std::string> expression_list;

    auto expressions = ctx->expression();

    expression_list.reserve(expressions.size());

    for(auto& expression: expressions){
        expression_list.push_back(visitExpression(expression).as<std::string>());
    }

    return expression_list;
}

antlrcpp::Any Interpreter::visitLoop(StepLangParser::LoopContext *ctx) {
    Loop loop;
    loop.condition = visitExpression(ctx->expression()).as<std::string>();
    loop.statements = visitBody(ctx->body()).as<Body>();
    return loop;
}

antlrcpp::Any Interpreter::visitExpression(StepLangParser::ExpressionContext *ctx) {
    return ctx->getText();
}
