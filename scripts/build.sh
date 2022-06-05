# Change this however you see fit
cmake -S .. -G "Ninja" -B ../build/ -DCMAKE_BUILD_TYPE=DEBUG -Wno-dev
cmake --build ../build/