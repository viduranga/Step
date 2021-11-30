
// Generated from StepLang.g4 by ANTLR 4.9.3


#include "StepLangListener.h"
#include "StepLangVisitor.h"

#include "StepLangParser.h"


using namespace antlrcpp;
using namespace antlr4;

StepLangParser::StepLangParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

StepLangParser::~StepLangParser() {
  delete _interpreter;
}

std::string StepLangParser::getGrammarFileName() const {
  return "StepLang.g4";
}

const std::vector<std::string>& StepLangParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& StepLangParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

StepLangParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StepLangParser::MainContext* StepLangParser::ProgramContext::main() {
  return getRuleContext<StepLangParser::MainContext>(0);
}

std::vector<StepLangParser::FunctionContext *> StepLangParser::ProgramContext::function() {
  return getRuleContexts<StepLangParser::FunctionContext>();
}

StepLangParser::FunctionContext* StepLangParser::ProgramContext::function(size_t i) {
  return getRuleContext<StepLangParser::FunctionContext>(i);
}


size_t StepLangParser::ProgramContext::getRuleIndex() const {
  return StepLangParser::RuleProgram;
}

void StepLangParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void StepLangParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any StepLangParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StepLangVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

StepLangParser::ProgramContext* StepLangParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, StepLangParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(25);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(22);
        function(); 
      }
      setState(27);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(28);
    main();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainContext ------------------------------------------------------------------

StepLangParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StepLangParser::BodyContext* StepLangParser::MainContext::body() {
  return getRuleContext<StepLangParser::BodyContext>(0);
}


size_t StepLangParser::MainContext::getRuleIndex() const {
  return StepLangParser::RuleMain;
}

void StepLangParser::MainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMain(this);
}

void StepLangParser::MainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMain(this);
}


antlrcpp::Any StepLangParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StepLangVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

StepLangParser::MainContext* StepLangParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 2, StepLangParser::RuleMain);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    body();
    setState(32);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == StepLangParser::T__0) {
      setState(31);
      match(StepLangParser::T__0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

StepLangParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StepLangParser::HeaderContext* StepLangParser::FunctionContext::header() {
  return getRuleContext<StepLangParser::HeaderContext>(0);
}

StepLangParser::BodyContext* StepLangParser::FunctionContext::body() {
  return getRuleContext<StepLangParser::BodyContext>(0);
}


size_t StepLangParser::FunctionContext::getRuleIndex() const {
  return StepLangParser::RuleFunction;
}

void StepLangParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void StepLangParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}


antlrcpp::Any StepLangParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StepLangVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

StepLangParser::FunctionContext* StepLangParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 4, StepLangParser::RuleFunction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34);
    header();
    setState(35);
    match(StepLangParser::T__1);
    setState(36);
    body();
    setState(37);
    match(StepLangParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HeaderContext ------------------------------------------------------------------

StepLangParser::HeaderContext::HeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StepLangParser::HeaderContext::IDENTIFIER() {
  return getToken(StepLangParser::IDENTIFIER, 0);
}

StepLangParser::Variable_listContext* StepLangParser::HeaderContext::variable_list() {
  return getRuleContext<StepLangParser::Variable_listContext>(0);
}


size_t StepLangParser::HeaderContext::getRuleIndex() const {
  return StepLangParser::RuleHeader;
}

void StepLangParser::HeaderContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHeader(this);
}

void StepLangParser::HeaderContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHeader(this);
}


antlrcpp::Any StepLangParser::HeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StepLangVisitor*>(visitor))
    return parserVisitor->visitHeader(this);
  else
    return visitor->visitChildren(this);
}

StepLangParser::HeaderContext* StepLangParser::header() {
  HeaderContext *_localctx = _tracker.createInstance<HeaderContext>(_ctx, getState());
  enterRule(_localctx, 6, StepLangParser::RuleHeader);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(39);
    match(StepLangParser::IDENTIFIER);
    setState(44);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == StepLangParser::T__2) {
      setState(40);
      match(StepLangParser::T__2);
      setState(41);
      variable_list();
      setState(42);
      match(StepLangParser::T__3);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BodyContext ------------------------------------------------------------------

StepLangParser::BodyContext::BodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<StepLangParser::StatementContext *> StepLangParser::BodyContext::statement() {
  return getRuleContexts<StepLangParser::StatementContext>();
}

StepLangParser::StatementContext* StepLangParser::BodyContext::statement(size_t i) {
  return getRuleContext<StepLangParser::StatementContext>(i);
}


size_t StepLangParser::BodyContext::getRuleIndex() const {
  return StepLangParser::RuleBody;
}

void StepLangParser::BodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBody(this);
}

void StepLangParser::BodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBody(this);
}


antlrcpp::Any StepLangParser::BodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StepLangVisitor*>(visitor))
    return parserVisitor->visitBody(this);
  else
    return visitor->visitChildren(this);
}

StepLangParser::BodyContext* StepLangParser::body() {
  BodyContext *_localctx = _tracker.createInstance<BodyContext>(_ctx, getState());
  enterRule(_localctx, 8, StepLangParser::RuleBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(47); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(46);
      statement();
      setState(49); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << StepLangParser::T__5)
      | (1ULL << StepLangParser::ACTION)
      | (1ULL << StepLangParser::IDENTIFIER))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

StepLangParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StepLangParser::StatementContext::ACTION() {
  return getToken(StepLangParser::ACTION, 0);
}

StepLangParser::LoopContext* StepLangParser::StatementContext::loop() {
  return getRuleContext<StepLangParser::LoopContext>(0);
}

StepLangParser::InvocationContext* StepLangParser::StatementContext::invocation() {
  return getRuleContext<StepLangParser::InvocationContext>(0);
}


size_t StepLangParser::StatementContext::getRuleIndex() const {
  return StepLangParser::RuleStatement;
}

void StepLangParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void StepLangParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any StepLangParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StepLangVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

StepLangParser::StatementContext* StepLangParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 10, StepLangParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(54);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StepLangParser::ACTION: {
        enterOuterAlt(_localctx, 1);
        setState(51);
        match(StepLangParser::ACTION);
        break;
      }

      case StepLangParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(52);
        loop();
        break;
      }

      case StepLangParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(53);
        invocation();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_listContext ------------------------------------------------------------------

StepLangParser::Variable_listContext::Variable_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> StepLangParser::Variable_listContext::IDENTIFIER() {
  return getTokens(StepLangParser::IDENTIFIER);
}

tree::TerminalNode* StepLangParser::Variable_listContext::IDENTIFIER(size_t i) {
  return getToken(StepLangParser::IDENTIFIER, i);
}


size_t StepLangParser::Variable_listContext::getRuleIndex() const {
  return StepLangParser::RuleVariable_list;
}

void StepLangParser::Variable_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_list(this);
}

void StepLangParser::Variable_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_list(this);
}


antlrcpp::Any StepLangParser::Variable_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StepLangVisitor*>(visitor))
    return parserVisitor->visitVariable_list(this);
  else
    return visitor->visitChildren(this);
}

StepLangParser::Variable_listContext* StepLangParser::variable_list() {
  Variable_listContext *_localctx = _tracker.createInstance<Variable_listContext>(_ctx, getState());
  enterRule(_localctx, 12, StepLangParser::RuleVariable_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(60);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(56);
        match(StepLangParser::IDENTIFIER);
        setState(57);
        match(StepLangParser::T__4); 
      }
      setState(62);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
    setState(63);
    match(StepLangParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InvocationContext ------------------------------------------------------------------

StepLangParser::InvocationContext::InvocationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StepLangParser::InvocationContext::IDENTIFIER() {
  return getToken(StepLangParser::IDENTIFIER, 0);
}

StepLangParser::Expression_listContext* StepLangParser::InvocationContext::expression_list() {
  return getRuleContext<StepLangParser::Expression_listContext>(0);
}


size_t StepLangParser::InvocationContext::getRuleIndex() const {
  return StepLangParser::RuleInvocation;
}

void StepLangParser::InvocationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInvocation(this);
}

void StepLangParser::InvocationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInvocation(this);
}


antlrcpp::Any StepLangParser::InvocationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StepLangVisitor*>(visitor))
    return parserVisitor->visitInvocation(this);
  else
    return visitor->visitChildren(this);
}

StepLangParser::InvocationContext* StepLangParser::invocation() {
  InvocationContext *_localctx = _tracker.createInstance<InvocationContext>(_ctx, getState());
  enterRule(_localctx, 14, StepLangParser::RuleInvocation);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
    match(StepLangParser::IDENTIFIER);
    setState(70);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == StepLangParser::T__2) {
      setState(66);
      match(StepLangParser::T__2);
      setState(67);
      expression_list();
      setState(68);
      match(StepLangParser::T__3);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_listContext ------------------------------------------------------------------

StepLangParser::Expression_listContext::Expression_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<StepLangParser::ExpressionContext *> StepLangParser::Expression_listContext::expression() {
  return getRuleContexts<StepLangParser::ExpressionContext>();
}

StepLangParser::ExpressionContext* StepLangParser::Expression_listContext::expression(size_t i) {
  return getRuleContext<StepLangParser::ExpressionContext>(i);
}


size_t StepLangParser::Expression_listContext::getRuleIndex() const {
  return StepLangParser::RuleExpression_list;
}

void StepLangParser::Expression_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_list(this);
}

void StepLangParser::Expression_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_list(this);
}


antlrcpp::Any StepLangParser::Expression_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StepLangVisitor*>(visitor))
    return parserVisitor->visitExpression_list(this);
  else
    return visitor->visitChildren(this);
}

StepLangParser::Expression_listContext* StepLangParser::expression_list() {
  Expression_listContext *_localctx = _tracker.createInstance<Expression_listContext>(_ctx, getState());
  enterRule(_localctx, 16, StepLangParser::RuleExpression_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(77);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(72);
        expression(0);
        setState(73);
        match(StepLangParser::T__4); 
      }
      setState(79);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
    setState(80);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopContext ------------------------------------------------------------------

StepLangParser::LoopContext::LoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StepLangParser::BodyContext* StepLangParser::LoopContext::body() {
  return getRuleContext<StepLangParser::BodyContext>(0);
}

StepLangParser::ExpressionContext* StepLangParser::LoopContext::expression() {
  return getRuleContext<StepLangParser::ExpressionContext>(0);
}


size_t StepLangParser::LoopContext::getRuleIndex() const {
  return StepLangParser::RuleLoop;
}

void StepLangParser::LoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoop(this);
}

void StepLangParser::LoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoop(this);
}


antlrcpp::Any StepLangParser::LoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StepLangVisitor*>(visitor))
    return parserVisitor->visitLoop(this);
  else
    return visitor->visitChildren(this);
}

StepLangParser::LoopContext* StepLangParser::loop() {
  LoopContext *_localctx = _tracker.createInstance<LoopContext>(_ctx, getState());
  enterRule(_localctx, 18, StepLangParser::RuleLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    match(StepLangParser::T__5);
    setState(83);
    antlrcpp::downCast<LoopContext *>(_localctx)->condition = expression(0);
    setState(84);
    match(StepLangParser::T__6);
    setState(85);
    match(StepLangParser::T__7);
    setState(86);
    body();
    setState(87);
    match(StepLangParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

StepLangParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StepLangParser::ExpressionContext::IDENTIFIER() {
  return getToken(StepLangParser::IDENTIFIER, 0);
}

tree::TerminalNode* StepLangParser::ExpressionContext::NUMBER() {
  return getToken(StepLangParser::NUMBER, 0);
}

std::vector<StepLangParser::ExpressionContext *> StepLangParser::ExpressionContext::expression() {
  return getRuleContexts<StepLangParser::ExpressionContext>();
}

StepLangParser::ExpressionContext* StepLangParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<StepLangParser::ExpressionContext>(i);
}

tree::TerminalNode* StepLangParser::ExpressionContext::OPERATOR() {
  return getToken(StepLangParser::OPERATOR, 0);
}


size_t StepLangParser::ExpressionContext::getRuleIndex() const {
  return StepLangParser::RuleExpression;
}

void StepLangParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void StepLangParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StepLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any StepLangParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StepLangVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


StepLangParser::ExpressionContext* StepLangParser::expression() {
   return expression(0);
}

StepLangParser::ExpressionContext* StepLangParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  StepLangParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  StepLangParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, StepLangParser::RuleExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(96);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StepLangParser::IDENTIFIER: {
        setState(90);
        match(StepLangParser::IDENTIFIER);
        break;
      }

      case StepLangParser::NUMBER: {
        setState(91);
        match(StepLangParser::NUMBER);
        break;
      }

      case StepLangParser::T__2: {
        setState(92);
        match(StepLangParser::T__2);
        setState(93);
        expression(0);
        setState(94);
        match(StepLangParser::T__3);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(103);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(98);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(99);
        match(StepLangParser::OPERATOR);
        setState(100);
        expression(3); 
      }
      setState(105);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool StepLangParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 10: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool StepLangParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> StepLangParser::_decisionToDFA;
atn::PredictionContextCache StepLangParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN StepLangParser::_atn;
std::vector<uint16_t> StepLangParser::_serializedATN;

std::vector<std::string> StepLangParser::_ruleNames = {
  "program", "main", "function", "header", "body", "statement", "variable_list", 
  "invocation", "expression_list", "loop", "expression"
};

std::vector<std::string> StepLangParser::_literalNames = {
  "", "'\n'", "'='", "'('", "')'", "','", "'<'", "'>'", "'['", "']'", "", 
  "", "", "'*'", "'/'", "'+'", "'-'"
};

std::vector<std::string> StepLangParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "ACTION", "IDENTIFIER", "OPERATOR", 
  "MUL", "DIV", "ADD", "SUB", "NUMBER", "WHITESPACE"
};

dfa::Vocabulary StepLangParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> StepLangParser::_tokenNames;

StepLangParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x14, 0x6d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x3, 0x2, 0x7, 0x2, 0x1a, 
       0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x1d, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 
       0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x23, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x5, 0x5, 0x2f, 0xa, 0x5, 0x3, 0x6, 0x6, 0x6, 0x32, 
       0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x33, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
       0x5, 0x7, 0x39, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x3d, 0xa, 
       0x8, 0xc, 0x8, 0xe, 0x8, 0x40, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x49, 0xa, 
       0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x4e, 0xa, 0xa, 0xc, 
       0xa, 0xe, 0xa, 0x51, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
       0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 
       0xc, 0x63, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x68, 
       0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x6b, 0xb, 0xc, 0x3, 0xc, 0x2, 0x3, 
       0x16, 0xd, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
       0x2, 0x2, 0x2, 0x6d, 0x2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x4, 0x20, 0x3, 
       0x2, 0x2, 0x2, 0x6, 0x24, 0x3, 0x2, 0x2, 0x2, 0x8, 0x29, 0x3, 0x2, 
       0x2, 0x2, 0xa, 0x31, 0x3, 0x2, 0x2, 0x2, 0xc, 0x38, 0x3, 0x2, 0x2, 
       0x2, 0xe, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x10, 0x43, 0x3, 0x2, 0x2, 0x2, 
       0x12, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x14, 0x54, 0x3, 0x2, 0x2, 0x2, 0x16, 
       0x62, 0x3, 0x2, 0x2, 0x2, 0x18, 0x1a, 0x5, 0x6, 0x4, 0x2, 0x19, 0x18, 
       0x3, 0x2, 0x2, 0x2, 0x1a, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x19, 0x3, 
       0x2, 0x2, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1e, 0x3, 0x2, 
       0x2, 0x2, 0x1d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x5, 0x4, 0x3, 
       0x2, 0x1f, 0x3, 0x3, 0x2, 0x2, 0x2, 0x20, 0x22, 0x5, 0xa, 0x6, 0x2, 
       0x21, 0x23, 0x7, 0x3, 0x2, 0x2, 0x22, 0x21, 0x3, 0x2, 0x2, 0x2, 0x22, 
       0x23, 0x3, 0x2, 0x2, 0x2, 0x23, 0x5, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 
       0x5, 0x8, 0x5, 0x2, 0x25, 0x26, 0x7, 0x4, 0x2, 0x2, 0x26, 0x27, 0x5, 
       0xa, 0x6, 0x2, 0x27, 0x28, 0x7, 0x3, 0x2, 0x2, 0x28, 0x7, 0x3, 0x2, 
       0x2, 0x2, 0x29, 0x2e, 0x7, 0xd, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0x5, 0x2, 
       0x2, 0x2b, 0x2c, 0x5, 0xe, 0x8, 0x2, 0x2c, 0x2d, 0x7, 0x6, 0x2, 0x2, 
       0x2d, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2e, 
       0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x9, 0x3, 0x2, 0x2, 0x2, 0x30, 0x32, 
       0x5, 0xc, 0x7, 0x2, 0x31, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x3, 
       0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 
       0x2, 0x2, 0x34, 0xb, 0x3, 0x2, 0x2, 0x2, 0x35, 0x39, 0x7, 0xc, 0x2, 
       0x2, 0x36, 0x39, 0x5, 0x14, 0xb, 0x2, 0x37, 0x39, 0x5, 0x10, 0x9, 
       0x2, 0x38, 0x35, 0x3, 0x2, 0x2, 0x2, 0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 
       0x38, 0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 0xd, 0x3, 0x2, 0x2, 0x2, 0x3a, 
       0x3b, 0x7, 0xd, 0x2, 0x2, 0x3b, 0x3d, 0x7, 0x7, 0x2, 0x2, 0x3c, 0x3a, 
       0x3, 0x2, 0x2, 0x2, 0x3d, 0x40, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3c, 0x3, 
       0x2, 0x2, 0x2, 0x3e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x41, 0x3, 0x2, 
       0x2, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0xd, 0x2, 
       0x2, 0x42, 0xf, 0x3, 0x2, 0x2, 0x2, 0x43, 0x48, 0x7, 0xd, 0x2, 0x2, 
       0x44, 0x45, 0x7, 0x5, 0x2, 0x2, 0x45, 0x46, 0x5, 0x12, 0xa, 0x2, 
       0x46, 0x47, 0x7, 0x6, 0x2, 0x2, 0x47, 0x49, 0x3, 0x2, 0x2, 0x2, 0x48, 
       0x44, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 0x2, 0x2, 0x2, 0x49, 0x11, 
       0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x5, 0x16, 0xc, 0x2, 0x4b, 0x4c, 
       0x7, 0x7, 0x2, 0x2, 0x4c, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4a, 0x3, 
       0x2, 0x2, 0x2, 0x4e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 
       0x2, 0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x52, 0x3, 0x2, 0x2, 
       0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x5, 0x16, 0xc, 
       0x2, 0x53, 0x13, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x7, 0x8, 0x2, 0x2, 
       0x55, 0x56, 0x5, 0x16, 0xc, 0x2, 0x56, 0x57, 0x7, 0x9, 0x2, 0x2, 
       0x57, 0x58, 0x7, 0xa, 0x2, 0x2, 0x58, 0x59, 0x5, 0xa, 0x6, 0x2, 0x59, 
       0x5a, 0x7, 0xb, 0x2, 0x2, 0x5a, 0x15, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 
       0x8, 0xc, 0x1, 0x2, 0x5c, 0x63, 0x7, 0xd, 0x2, 0x2, 0x5d, 0x63, 0x7, 
       0x13, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x5, 0x2, 0x2, 0x5f, 0x60, 0x5, 
       0x16, 0xc, 0x2, 0x60, 0x61, 0x7, 0x6, 0x2, 0x2, 0x61, 0x63, 0x3, 
       0x2, 0x2, 0x2, 0x62, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x62, 0x5d, 0x3, 0x2, 
       0x2, 0x2, 0x62, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x63, 0x69, 0x3, 0x2, 0x2, 
       0x2, 0x64, 0x65, 0xc, 0x4, 0x2, 0x2, 0x65, 0x66, 0x7, 0xe, 0x2, 0x2, 
       0x66, 0x68, 0x5, 0x16, 0xc, 0x5, 0x67, 0x64, 0x3, 0x2, 0x2, 0x2, 
       0x68, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 
       0x6a, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x17, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x69, 
       0x3, 0x2, 0x2, 0x2, 0xc, 0x1b, 0x22, 0x2e, 0x33, 0x38, 0x3e, 0x48, 
       0x4f, 0x62, 0x69, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

StepLangParser::Initializer StepLangParser::_init;
