
// Generated from StepLang.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "StepLangParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by StepLangParser.
 */
class  StepLangVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by StepLangParser.
   */
    virtual antlrcpp::Any visitProgram(StepLangParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitMain(StepLangParser::MainContext *context) = 0;

    virtual antlrcpp::Any visitFunction(StepLangParser::FunctionContext *context) = 0;

    virtual antlrcpp::Any visitHeader(StepLangParser::HeaderContext *context) = 0;

    virtual antlrcpp::Any visitBody(StepLangParser::BodyContext *context) = 0;

    virtual antlrcpp::Any visitStatement(StepLangParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitVariable_list(StepLangParser::Variable_listContext *context) = 0;

    virtual antlrcpp::Any visitInvocation(StepLangParser::InvocationContext *context) = 0;

    virtual antlrcpp::Any visitExpression_list(StepLangParser::Expression_listContext *context) = 0;

    virtual antlrcpp::Any visitLoop(StepLangParser::LoopContext *context) = 0;

    virtual antlrcpp::Any visitExpression(StepLangParser::ExpressionContext *context) = 0;


};

