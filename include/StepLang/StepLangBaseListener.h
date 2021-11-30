
// Generated from StepLang.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "StepLangListener.h"


/**
 * This class provides an empty implementation of StepLangListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  StepLangBaseListener : public StepLangListener {
public:

  virtual void enterProgram(StepLangParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(StepLangParser::ProgramContext * /*ctx*/) override { }

  virtual void enterMain(StepLangParser::MainContext * /*ctx*/) override { }
  virtual void exitMain(StepLangParser::MainContext * /*ctx*/) override { }

  virtual void enterFunction(StepLangParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(StepLangParser::FunctionContext * /*ctx*/) override { }

  virtual void enterHeader(StepLangParser::HeaderContext * /*ctx*/) override { }
  virtual void exitHeader(StepLangParser::HeaderContext * /*ctx*/) override { }

  virtual void enterBody(StepLangParser::BodyContext * /*ctx*/) override { }
  virtual void exitBody(StepLangParser::BodyContext * /*ctx*/) override { }

  virtual void enterStatement(StepLangParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(StepLangParser::StatementContext * /*ctx*/) override { }

  virtual void enterVariable_list(StepLangParser::Variable_listContext * /*ctx*/) override { }
  virtual void exitVariable_list(StepLangParser::Variable_listContext * /*ctx*/) override { }

  virtual void enterInvocation(StepLangParser::InvocationContext * /*ctx*/) override { }
  virtual void exitInvocation(StepLangParser::InvocationContext * /*ctx*/) override { }

  virtual void enterExpression_list(StepLangParser::Expression_listContext * /*ctx*/) override { }
  virtual void exitExpression_list(StepLangParser::Expression_listContext * /*ctx*/) override { }

  virtual void enterLoop(StepLangParser::LoopContext * /*ctx*/) override { }
  virtual void exitLoop(StepLangParser::LoopContext * /*ctx*/) override { }

  virtual void enterExpression(StepLangParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(StepLangParser::ExpressionContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

