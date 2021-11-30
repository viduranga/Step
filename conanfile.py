from conans import ConanFile


class StepEngine(ConanFile):
    name = "StepEngine"
    version = "0.1"
    requires = (
        "catch2/2.13.7",
        "docopt.cpp/0.6.2",
        "fmt/8.0.1",
        "spdlog/1.9.2",
        "godot-cpp/3.4",
        "antlr4-cppruntime/4.9.3"
    )
    generators = "cmake", "gcc", "txt", "cmake_find_package"
