
// Generated from StepLang.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "StepLangVisitor.h"


/**
 * This class provides an empty implementation of StepLangVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  StepLangBaseVisitor : public StepLangVisitor {
public:

  virtual std::any visitProgram(StepLangParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMain(StepLangParser::MainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(StepLangParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHeader(StepLangParser::HeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBody(StepLangParser::BodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(StepLangParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable_list(StepLangParser::Variable_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInvocation(StepLangParser::InvocationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_list(StepLangParser::Expression_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoop(StepLangParser::LoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(StepLangParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }


};

