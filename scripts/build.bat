cmake -S .. -G "Ninja" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang -B ../build/ -DCMAKE_TOOLCHAIN_FILE=C:/Users/GhostNear/scoop/apps/vcpkg/current/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_ARCHITECTURE=x64-windows-static -DCMAKE_BUILD_TYPE=RELEASE -DBUILD_TARGET=WIN -Wno-dev
cmake --build ../build/