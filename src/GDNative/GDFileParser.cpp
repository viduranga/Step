#include <GDNative/GDFileParser.h>
#include <fstream>

#include <TileMap.hpp>

void GDFileParser::_register_methods() {
    register_method("parseLevelFile", &GDFileParser::parseLevelFile);
}

GDFileParser::GDFileParser() {

}

GDFileParser::~GDFileParser() {

}

void GDFileParser::_init() {

}

godot::Dictionary GDFileParser::parseLevelFile(godot::String path) {
    auto level = fileParser.parseLevel(std::ifstream(path.alloc_c_string()));

    godot::Dictionary rtn;

    auto grid = godot::PoolByteArray();
    grid.resize(static_cast<int>(level.grid.size()));

    for(uint32_t i=0; i < level.grid.size(); i++){
        grid.insert(static_cast<int>(i), static_cast<uint8_t>(level.grid[i]));
    }

    rtn["grid"] = grid;
    rtn["size"] = level.grid_size;
    rtn["facing"] = static_cast<char>(level.facing);
    return rtn;
}

