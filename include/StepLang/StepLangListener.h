
// Generated from StepLang.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "StepLangParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by StepLangParser.
 */
class  StepLangListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(StepLangParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(StepLangParser::ProgramContext *ctx) = 0;

  virtual void enterMain(StepLangParser::MainContext *ctx) = 0;
  virtual void exitMain(StepLangParser::MainContext *ctx) = 0;

  virtual void enterFunction(StepLangParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(StepLangParser::FunctionContext *ctx) = 0;

  virtual void enterHeader(StepLangParser::HeaderContext *ctx) = 0;
  virtual void exitHeader(StepLangParser::HeaderContext *ctx) = 0;

  virtual void enterBody(StepLangParser::BodyContext *ctx) = 0;
  virtual void exitBody(StepLangParser::BodyContext *ctx) = 0;

  virtual void enterStatement(StepLangParser::StatementContext *ctx) = 0;
  virtual void exitStatement(StepLangParser::StatementContext *ctx) = 0;

  virtual void enterVariable_list(StepLangParser::Variable_listContext *ctx) = 0;
  virtual void exitVariable_list(StepLangParser::Variable_listContext *ctx) = 0;

  virtual void enterInvocation(StepLangParser::InvocationContext *ctx) = 0;
  virtual void exitInvocation(StepLangParser::InvocationContext *ctx) = 0;

  virtual void enterExpression_list(StepLangParser::Expression_listContext *ctx) = 0;
  virtual void exitExpression_list(StepLangParser::Expression_listContext *ctx) = 0;

  virtual void enterLoop(StepLangParser::LoopContext *ctx) = 0;
  virtual void exitLoop(StepLangParser::LoopContext *ctx) = 0;

  virtual void enterExpression(StepLangParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(StepLangParser::ExpressionContext *ctx) = 0;


};

