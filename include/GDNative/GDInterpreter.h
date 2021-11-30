#pragma once
#include <Godot.hpp>
#include <Node.hpp>
#include <Interpreter/Interpreter.h>
#include <Interpreter/Runtime.h>

class GDInterpreter : public godot::Node {
GODOT_CLASS(GDInterpreter, Node)

public:
    static void _register_methods();

    GDInterpreter();
    ~GDInterpreter();

    void _init(); // our initializer called by Godot

    godot::Dictionary loadProgram(godot::String code);
    char step();
    void reset();

private:
    Program program;
    Interpreter interpreter;
    Runtime runtime;
};
