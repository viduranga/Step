#include <GDNative/GDInterpreter.h>

void GDInterpreter::_register_methods() {
    register_method("loadProgram", &GDInterpreter::loadProgram);
    register_method("step", &GDInterpreter::step);
    register_method("reset", &GDInterpreter::reset);
}

GDInterpreter::GDInterpreter() {

}

GDInterpreter::~GDInterpreter() {

}


void GDInterpreter::_init() {

}

godot::Dictionary GDInterpreter::loadProgram(godot::String code) {
    try{
        program = interpreter.parse(std::string(code.alloc_c_string()));
        runtime.load(program);
        return godot::Dictionary::make(
                "error", false);
    } catch (const std::exception& exception) {
        return godot::Dictionary::make(
                "error", true,
                "message", exception.what());
    }
}

char GDInterpreter::step() {
    return static_cast<char>(runtime.step());
}

void GDInterpreter::reset() {
    runtime.reset();
}
