
// Generated from StepLang.g4 by ANTLR 4.13.2


#include "StepLangLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct StepLangLexerStaticData final {
  StepLangLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  StepLangLexerStaticData(const StepLangLexerStaticData&) = delete;
  StepLangLexerStaticData(StepLangLexerStaticData&&) = delete;
  StepLangLexerStaticData& operator=(const StepLangLexerStaticData&) = delete;
  StepLangLexerStaticData& operator=(StepLangLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag steplanglexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<StepLangLexerStaticData> steplanglexerLexerStaticData = nullptr;

void steplanglexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (steplanglexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(steplanglexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<StepLangLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "ACTION", "IDENTIFIER", "OPERATOR", "MUL", "DIV", "ADD", "SUB", "NUMBER", 
      "WHITESPACE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,18,85,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,
  	4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,11,
  	1,11,3,11,64,8,11,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,16,4,16,75,
  	8,16,11,16,12,16,76,1,17,4,17,80,8,17,11,17,12,17,81,1,17,1,17,0,0,18,
  	1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,
  	29,15,31,16,33,17,35,18,1,0,4,3,0,97,97,108,108,114,114,1,0,97,122,1,
  	0,48,57,2,0,9,9,32,32,89,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,
  	0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,
  	19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,
  	0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,1,37,1,0,0,0,3,39,1,0,0,
  	0,5,41,1,0,0,0,7,43,1,0,0,0,9,45,1,0,0,0,11,47,1,0,0,0,13,49,1,0,0,0,
  	15,51,1,0,0,0,17,53,1,0,0,0,19,55,1,0,0,0,21,57,1,0,0,0,23,63,1,0,0,0,
  	25,65,1,0,0,0,27,67,1,0,0,0,29,69,1,0,0,0,31,71,1,0,0,0,33,74,1,0,0,0,
  	35,79,1,0,0,0,37,38,5,10,0,0,38,2,1,0,0,0,39,40,5,61,0,0,40,4,1,0,0,0,
  	41,42,5,40,0,0,42,6,1,0,0,0,43,44,5,41,0,0,44,8,1,0,0,0,45,46,5,44,0,
  	0,46,10,1,0,0,0,47,48,5,60,0,0,48,12,1,0,0,0,49,50,5,62,0,0,50,14,1,0,
  	0,0,51,52,5,91,0,0,52,16,1,0,0,0,53,54,5,93,0,0,54,18,1,0,0,0,55,56,7,
  	0,0,0,56,20,1,0,0,0,57,58,7,1,0,0,58,22,1,0,0,0,59,64,3,25,12,0,60,64,
  	3,27,13,0,61,64,3,29,14,0,62,64,3,31,15,0,63,59,1,0,0,0,63,60,1,0,0,0,
  	63,61,1,0,0,0,63,62,1,0,0,0,64,24,1,0,0,0,65,66,5,42,0,0,66,26,1,0,0,
  	0,67,68,5,47,0,0,68,28,1,0,0,0,69,70,5,43,0,0,70,30,1,0,0,0,71,72,5,45,
  	0,0,72,32,1,0,0,0,73,75,7,2,0,0,74,73,1,0,0,0,75,76,1,0,0,0,76,74,1,0,
  	0,0,76,77,1,0,0,0,77,34,1,0,0,0,78,80,7,3,0,0,79,78,1,0,0,0,80,81,1,0,
  	0,0,81,79,1,0,0,0,81,82,1,0,0,0,82,83,1,0,0,0,83,84,6,17,0,0,84,36,1,
  	0,0,0,4,0,63,76,81,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  steplanglexerLexerStaticData = std::move(staticData);
}

}

StepLangLexer::StepLangLexer(CharStream *input) : Lexer(input) {
  StepLangLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *steplanglexerLexerStaticData->atn, steplanglexerLexerStaticData->decisionToDFA, steplanglexerLexerStaticData->sharedContextCache);
}

StepLangLexer::~StepLangLexer() {
  delete _interpreter;
}

std::string StepLangLexer::getGrammarFileName() const {
  return "StepLang.g4";
}

const std::vector<std::string>& StepLangLexer::getRuleNames() const {
  return steplanglexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& StepLangLexer::getChannelNames() const {
  return steplanglexerLexerStaticData->channelNames;
}

const std::vector<std::string>& StepLangLexer::getModeNames() const {
  return steplanglexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& StepLangLexer::getVocabulary() const {
  return steplanglexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView StepLangLexer::getSerializedATN() const {
  return steplanglexerLexerStaticData->serializedATN;
}

const atn::ATN& StepLangLexer::getATN() const {
  return *steplanglexerLexerStaticData->atn;
}




void StepLangLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  steplanglexerLexerInitialize();
#else
  ::antlr4::internal::call_once(steplanglexerLexerOnceFlag, steplanglexerLexerInitialize);
#endif
}
