
// Generated from StepLang.g4 by ANTLR 4.13.2

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
    virtual std::any visitProgram(StepLangParser::ProgramContext *context) = 0;

    virtual std::any visitMain(StepLangParser::MainContext *context) = 0;

    virtual std::any visitFunction(StepLangParser::FunctionContext *context) = 0;

    virtual std::any visitHeader(StepLangParser::HeaderContext *context) = 0;

    virtual std::any visitBody(StepLangParser::BodyContext *context) = 0;

    virtual std::any visitStatement(StepLangParser::StatementContext *context) = 0;

    virtual std::any visitVariable_list(StepLangParser::Variable_listContext *context) = 0;

    virtual std::any visitInvocation(StepLangParser::InvocationContext *context) = 0;

    virtual std::any visitExpression_list(StepLangParser::Expression_listContext *context) = 0;

    virtual std::any visitLoop(StepLangParser::LoopContext *context) = 0;

    virtual std::any visitExpression(StepLangParser::ExpressionContext *context) = 0;


};

