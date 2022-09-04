# Change this however you see fit
export VITASDK=/usr/local/vitasdk
export PATH=$VITASDK/bin:$PATH
cmake -S .. -B ../build/ -DCMAKE_BUILD_TYPE=RELEASE -DBUILD_TARGET=VITA -Wno-dev
cmake --build ../build/
