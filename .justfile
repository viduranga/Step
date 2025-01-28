set dotenv-load

build target='debug':
    #!/usr/bin/env zsh
    local target="{{lowercase(target)}}"
    mkdir -p ./build/$target
    cd ./build/$target
    cmake ../../. -GNinja -DCMAKE_BUILD_TYPE=$target
    cmake --build . --target all -- -j 4
    ln -sf ./build/$target/compile_commands.json ../../compile_commands.$target.json

run target='debug':
    #!/usr/bin/env zsh
    local target="{{lowercase(target)}}"
    # NOTE: poytry does not set PYTHONPATH. So we need to set it manually. We need to find a better way to do this.
    local pypath=`python -c 'import sys; print(":".join(sys.path))'`
    PYTHONPATH=$pypath ./build/$target/src/node/node
