#pragma once
#include <string>
#include <Interpreter/Defs.h>
#include <Interpreter/Function.h>
#include <StepLang/StepLangParser.h>
#include <StepLang/StepLangLexer.h>
#include <StepLang/StepLangBaseVisitor.h>

class Interpreter: StepLangBaseVisitor{
public:
    Interpreter();

private:
    antlrcpp::Any visitProgram(StepLangParser::ProgramContext *ctx) override;

    antlrcpp::Any visitMain(StepLangParser::MainContext *ctx) override;

    antlrcpp::Any visitFunction(StepLangParser::FunctionContext *ctx) override;

    antlrcpp::Any visitHeader(StepLangParser::HeaderContext *ctx) override;

    antlrcpp::Any visitBody(StepLangParser::BodyContext *ctx) override;

    antlrcpp::Any visitStatement(StepLangParser::StatementContext *ctx) override;

    antlrcpp::Any visitVariable_list(StepLangParser::Variable_listContext *ctx) override;

    antlrcpp::Any visitInvocation(StepLangParser::InvocationContext *ctx) override;

    antlrcpp::Any visitExpression_list(StepLangParser::Expression_listContext *ctx) override;

    antlrcpp::Any visitLoop(StepLangParser::LoopContext *ctx) override;

    antlrcpp::Any visitExpression(StepLangParser::ExpressionContext *ctx) override;

public:
    Program parse(const std::string& code);

};



