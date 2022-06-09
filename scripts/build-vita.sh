# Change this however you see fit
cmake -S .. -B ../build/ -DCMAKE_BUILD_TYPE=DEBUG -DBUILD_TARGET=VITA -Wno-dev
cmake --build ../build/