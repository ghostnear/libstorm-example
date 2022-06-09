cmake -S .. -G "Ninja" -B ../build/ -DCMAKE_BUILD_TYPE=DEBUG -DBUILD_TARGET=WIN -Wno-dev
cmake --build ../build/