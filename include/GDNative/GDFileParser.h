#pragma once

#include <Godot.hpp>
#include <Node.hpp>
#include <Parser/DataParser.h>

class GDFileParser : public godot::Node {
    GODOT_CLASS(GDFileParser, Node)

public:
    static void _register_methods();

    GDFileParser();
    ~GDFileParser();

    void _init(); // our initializer called by Godot

    godot::Dictionary parseLevelFile(godot::String path);

private:
    DataParser fileParser;
};


