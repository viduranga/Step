
// Generated from StepLang.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "StepLangVisitor.h"


/**
 * This class provides an empty implementation of StepLangVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  StepLangBaseVisitor : public StepLangVisitor {
public:

  virtual antlrcpp::Any visitProgram(StepLangParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMain(StepLangParser::MainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction(StepLangParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHeader(StepLangParser::HeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBody(StepLangParser::BodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(StepLangParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_list(StepLangParser::Variable_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInvocation(StepLangParser::InvocationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression_list(StepLangParser::Expression_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoop(StepLangParser::LoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(StepLangParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }


};

