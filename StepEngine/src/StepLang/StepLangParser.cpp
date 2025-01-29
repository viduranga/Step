
// Generated from StepLang.g4 by ANTLR 4.13.2


#include "StepLangListener.h"
#include "StepLangVisitor.h"

#include "StepLangParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct StepLangParserStaticData final {
  StepLangParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  StepLangParserStaticData(const StepLangParserStaticData&) = delete;
  StepLangParserStaticData(StepLangParserStaticData&&) = delete;
  StepLangParserStaticData& operator=(const StepLangParserStaticData&) = delete;
  StepLangParserStaticData& operator=(StepLangParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag steplangParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<StepLangParserStaticData> steplangParserStaticData = nullptr;

void steplangParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (steplangParserStaticData != nullptr) {
    return;
  }
#else
  assert(steplangParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<StepLangParserStaticData>(
    std::vector<std::string>{
      "program", "main", "function", "header", "body", "statement", "variable_list", 
      "invocation", "expression_list", "loop", "expression"
    },
    std::vector<std::string>{
      "", "'\\n'", "'='", "'('", "')'", "','", "'<'", "'>'", "'['", "']'", 
      "", "", "", "'*'", "'/'", "'+'", "'-'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "ACTION", "IDENTIFIER", "OPERATOR", 
      "MUL", "DIV", "ADD", "SUB", "NUMBER", "WHITESPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,18,107,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,1,0,5,0,24,8,0,10,0,12,0,27,9,0,1,0,1,
  	0,1,1,1,1,3,1,33,8,1,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,3,3,45,8,
  	3,1,4,4,4,48,8,4,11,4,12,4,49,1,5,1,5,1,5,3,5,55,8,5,1,6,1,6,5,6,59,8,
  	6,10,6,12,6,62,9,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,3,7,71,8,7,1,8,1,8,1,8,
  	5,8,76,8,8,10,8,12,8,79,9,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,3,10,97,8,10,1,10,1,10,1,10,5,10,102,8,
  	10,10,10,12,10,105,9,10,1,10,0,1,20,11,0,2,4,6,8,10,12,14,16,18,20,0,
  	0,107,0,25,1,0,0,0,2,30,1,0,0,0,4,34,1,0,0,0,6,39,1,0,0,0,8,47,1,0,0,
  	0,10,54,1,0,0,0,12,60,1,0,0,0,14,65,1,0,0,0,16,77,1,0,0,0,18,82,1,0,0,
  	0,20,96,1,0,0,0,22,24,3,4,2,0,23,22,1,0,0,0,24,27,1,0,0,0,25,23,1,0,0,
  	0,25,26,1,0,0,0,26,28,1,0,0,0,27,25,1,0,0,0,28,29,3,2,1,0,29,1,1,0,0,
  	0,30,32,3,8,4,0,31,33,5,1,0,0,32,31,1,0,0,0,32,33,1,0,0,0,33,3,1,0,0,
  	0,34,35,3,6,3,0,35,36,5,2,0,0,36,37,3,8,4,0,37,38,5,1,0,0,38,5,1,0,0,
  	0,39,44,5,11,0,0,40,41,5,3,0,0,41,42,3,12,6,0,42,43,5,4,0,0,43,45,1,0,
  	0,0,44,40,1,0,0,0,44,45,1,0,0,0,45,7,1,0,0,0,46,48,3,10,5,0,47,46,1,0,
  	0,0,48,49,1,0,0,0,49,47,1,0,0,0,49,50,1,0,0,0,50,9,1,0,0,0,51,55,5,10,
  	0,0,52,55,3,18,9,0,53,55,3,14,7,0,54,51,1,0,0,0,54,52,1,0,0,0,54,53,1,
  	0,0,0,55,11,1,0,0,0,56,57,5,11,0,0,57,59,5,5,0,0,58,56,1,0,0,0,59,62,
  	1,0,0,0,60,58,1,0,0,0,60,61,1,0,0,0,61,63,1,0,0,0,62,60,1,0,0,0,63,64,
  	5,11,0,0,64,13,1,0,0,0,65,70,5,11,0,0,66,67,5,3,0,0,67,68,3,16,8,0,68,
  	69,5,4,0,0,69,71,1,0,0,0,70,66,1,0,0,0,70,71,1,0,0,0,71,15,1,0,0,0,72,
  	73,3,20,10,0,73,74,5,5,0,0,74,76,1,0,0,0,75,72,1,0,0,0,76,79,1,0,0,0,
  	77,75,1,0,0,0,77,78,1,0,0,0,78,80,1,0,0,0,79,77,1,0,0,0,80,81,3,20,10,
  	0,81,17,1,0,0,0,82,83,5,6,0,0,83,84,3,20,10,0,84,85,5,7,0,0,85,86,5,8,
  	0,0,86,87,3,8,4,0,87,88,5,9,0,0,88,19,1,0,0,0,89,90,6,10,-1,0,90,97,5,
  	11,0,0,91,97,5,17,0,0,92,93,5,3,0,0,93,94,3,20,10,0,94,95,5,4,0,0,95,
  	97,1,0,0,0,96,89,1,0,0,0,96,91,1,0,0,0,96,92,1,0,0,0,97,103,1,0,0,0,98,
  	99,10,2,0,0,99,100,5,12,0,0,100,102,3,20,10,3,101,98,1,0,0,0,102,105,
  	1,0,0,0,103,101,1,0,0,0,103,104,1,0,0,0,104,21,1,0,0,0,105,103,1,0,0,
  	0,10,25,32,44,49,54,60,70,77,96,103
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  steplangParserStaticData = std::move(staticData);
}

}

StepLangParser::StepLangParser(TokenStream *input) : StepLangParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

StepLangParser::StepLangParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  StepLangParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *steplangParserStaticData->atn, steplangParserStaticData->decisionToDFA, steplangParserStaticData->sharedContextCache, options);
}

StepLangParser::~StepLangParser() {
  delete _interpreter;
}

const atn::ATN& StepLangParser::getATN() const {
  return *steplangParserStaticData->atn;
}

std::string StepLangParser::getGrammarFileName() const {
  return "StepLang.g4";
}

const std::vector<std::string>& StepLangParser::getRuleNames() const {
  return steplangParserStaticData->ruleNames;
}

const dfa::Vocabulary& StepLangParser::getVocabulary() const {
  return steplangParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView StepLangParser::getSerializedATN() const {
  return steplangParserStaticData->serializedATN;
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


std::any StepLangParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any StepLangParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any StepLangParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any StepLangParser::HeaderContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any StepLangParser::BodyContext::accept(tree::ParseTreeVisitor *visitor) {
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
      ((1ULL << _la) & 3136) != 0));
   
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


std::any StepLangParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any StepLangParser::Variable_listContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any StepLangParser::InvocationContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any StepLangParser::Expression_listContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any StepLangParser::LoopContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any StepLangParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
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

void StepLangParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  steplangParserInitialize();
#else
  ::antlr4::internal::call_once(steplangParserOnceFlag, steplangParserInitialize);
#endif
}
