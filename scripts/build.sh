# Change this however you see fit
cmake -S .. -G "Ninja" -B ../build/ -DCMAKE_BUILD_TYPE=DEBUG -DBUILD_TARGET=UNIX -Wno-dev
cmake --build ../build/