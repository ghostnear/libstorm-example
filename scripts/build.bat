cmake -S .. -G "Ninja" -B ../build/ -DCMAKE_BUILD_TYPE=RELEASE -DBUILD_TARGET=WIN -Wno-dev -DCMAKE_TOOLCHAIN_FILE="C:/Users/GhostNear/scoop/apps/vcpkg/current/scripts/buildsystems/vcpkg.cmake" -DVCPKG_TARGET_TRIPLET="x64-windows-static"
cmake --build ../build/