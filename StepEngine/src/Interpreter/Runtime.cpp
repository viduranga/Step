#include <Interpreter/Runtime.h>
#include <Interpreter/Function.h>
#include <Interpreter/Evaluator.h>
#include <utility>

Runtime::Runtime()
{
}

void Runtime::load(Program _program)
{
    stack = std::stack<StackFrame>();
    program = std::move(_program);

    auto &main = *program[FUNC_MAIN];
    stack.push({ &main.statements, main.statements.begin(), {} });
}

ACTION Runtime::step()
{
    auto &stack_top = stack.top();
    auto &head = stack_top.seeker;

    while (head == stack_top.body->end()) {
        stack.pop();
        if (stack.empty())
            return ACTION::END;
        else
            return step();
    }

    if (std::holds_alternative<ACTION>(**head)) {
        return std::get<ACTION>(**(head++));
    } else if (std::holds_alternative<Invocation>(**head)) {
        auto &invocation = std::get<Invocation>(**head);

        if (auto it = program.find(invocation.function); it != program.end()) {
            StackFrame call_frame;
            std::vector<uint32_t> call_variables;
            Function &function = *it->second;
            call_frame.body = &function.statements;
            call_frame.seeker = call_frame.body->begin();

            auto &stack_variables = stack_top.variables;

            for (auto &argument : invocation.arguments) {
                auto result = Evaluator::evaluate(argument, stack_variables);
                if (result > 0)
                    call_variables.push_back(static_cast<unsigned int>(result));
                else {
                    head++;
                    return step();
                }
            }

            assert(function.parameters.size() == call_variables.size());

            for (uint32_t i = 0; i < function.parameters.size(); ++i) {
                call_frame.variables[function.parameters[i]] = call_variables[i];
            }
            head++;
            stack.push(std::move(call_frame));
            return step();
        } else
            assert(false);
    } else if (std::holds_alternative<Loop>(**head)) {
        auto &loop = std::get<Loop>(**head);
        auto condition = Evaluator::evaluate(loop.condition, stack_top.variables);
        if (stack_top.variables.find(SEEKER_VAR_1) == stack_top.variables.end())
            stack_top.variables[SEEKER_VAR_1] = 0;
        auto &loop_variable = stack_top.variables[SEEKER_VAR_1];
        if (condition > 0 && loop_variable < static_cast<uint32_t>(condition)) {
            StackFrame call_frame;
            call_frame.body = &loop.statements;
            call_frame.seeker = loop.statements.begin();
            call_frame.variables = stack_top.variables;
            stack.push(std::move(call_frame));

            loop_variable++;

            return step();
        } else {
            head++;
            stack_top.variables.erase(SEEKER_VAR_1);
            return step();
        }
    } else
        assert(false);
}

void Runtime::reset()
{
    stack = std::stack<StackFrame>();
    auto &main = *program[FUNC_MAIN];
    stack.push({ &main.statements, main.statements.begin(), {} });
}
