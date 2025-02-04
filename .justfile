set dotenv-load

build target='debug':
    #!/usr/bin/env zsh
    local target="{{lowercase(target)}}"
    mkdir -p ./build/$target
    cd ./build/$target
    cmake ../../. -GNinja -DCMAKE_BUILD_TYPE=$target
    cmake --build . --target all -- -j 4
    ln -sf ./build/$target/compile_commands.json ../../compile_commands.$target.json

test target='debug': build
    #!/usr/bin/env zsh
    local target="{{lowercase(target)}}"
    ./build/$target/StepEngine/test/test
