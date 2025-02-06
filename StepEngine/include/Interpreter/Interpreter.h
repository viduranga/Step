#pragma once
#include <string>
#include <Interpreter/Defs.h>
#include <Interpreter/Function.h>
#include <StepLang/StepLangParser.h>
#include <StepLang/StepLangLexer.h>
#include <StepLang/StepLangBaseVisitor.h>
#include <any>

class Interpreter : StepLangBaseVisitor
{
  public:
    Interpreter();
    Program parse(const std::string &code);

  private:
    std::any visitProgram(StepLangParser::ProgramContext *ctx) override;

    std::any visitMain(StepLangParser::MainContext *ctx) override;

    std::any visitFunction(StepLangParser::FunctionContext *ctx) override;

    std::any visitHeader(StepLangParser::HeaderContext *ctx) override;

    std::any visitBody(StepLangParser::BodyContext *ctx) override;

    std::any visitStatement(StepLangParser::StatementContext *ctx) override;

    std::any visitVariable_list(StepLangParser::Variable_listContext *ctx) override;

    std::any visitInvocation(StepLangParser::InvocationContext *ctx) override;

    std::any visitExpression_list(StepLangParser::Expression_listContext *ctx) override;

    std::any visitLoop(StepLangParser::LoopContext *ctx) override;

    std::any visitExpression(StepLangParser::ExpressionContext *ctx) override;
};
