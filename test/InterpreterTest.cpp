#include <iostream>
#include "Interpreter/Interpreter.h"
#include <catch2/catch.hpp>
#include <Interpreter/Runtime.h>
#include <Interpreter/Evaluator.h>


TEST_CASE("Interpreter test", "[interpreter]"){
    Interpreter intepreter;

    SECTION("evaluator test"){
        REQUIRE(Evaluator::evaluate("12*4+(15-2)-10/5") == 59);
    }

    SECTION("parser recursive test"){
        auto code = "g(x)=ag(x-1)\n"
                    "f(x)=g(x)rf(x-1)\n"
                    "f(10)\n";

        auto program = intepreter.parse(code);

        Runtime runtime;
        runtime.load(program);

        std::string output;
        for(auto action = runtime.step(); action != ACTION::END; action = runtime.step()){
            output += static_cast<char>(action);
        }

        REQUIRE(output == "aaaaaaaaaaraaaaaaaaaraaaaaaaaraaaaaaaraaaaaaraaaaaraaaaraaaraarar");
    }

    SECTION("parser iterative test"){
      auto code = "f(x)=<x>[a]rf(x-1)\n"
        "f(10)\n";

      auto program = intepreter.parse(code);

      Runtime runtime;
      runtime.load(program);

      std::string output;
      for(auto action = runtime.step(); action != ACTION::END; action = runtime.step()){
        output += static_cast<char>(action);
      }

      REQUIRE(output == "aaaaaaaaaaraaaaaaaaaraaaaaaaaraaaaaaaraaaaaaraaaaaraaaaraaaraarar");
    }
}