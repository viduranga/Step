#pragma once

struct StackFrame{
    Body* body;
    Body::iterator seeker;
    std::map<char, uint32_t> variables;
};