#!/usr/bin/env bash

antlr -Dlanguage=Cpp -visitor -o gen StepLang.g4
cp gen/*.h ../include/StepLang/.
cp gen/*.cpp ../src/StepLang/.
rm -fr gen
