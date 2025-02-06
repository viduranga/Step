set dotenv-load

clean target='Debug':
    #!/usr/bin/env zsh
    rm -rf build/{{target}}

build target='Debug':
    #!/usr/bin/env zsh
    conan install . --build=missing --settings=build_type={{target}}
    cmake --preset conan-{{lowercase(target)}}
    cmake --build --target all --preset conan-{{lowercase(target)}}
    ln -sf build/{{target}}/compile_commands.json compile_commands.json

test target='Debug': build
    #!/usr/bin/env zsh
    ./build/{{target}}/StepEngine/test/test
