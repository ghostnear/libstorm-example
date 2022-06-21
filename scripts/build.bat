set BUILD_TYPE="RELEASE"
set BUILD_GENERATOR="Ninja" 
set VCPKG_ROOT="C:/Users/GhostNear/scoop/apps/vcpkg/current"
set VCPKG_TOOLCHAIN="%VCPKG_ROOT%/scripts/buildsystems/vcpkg.cmake"
set VCPKG_TRIPLET="x64-windows-static"
cmake -S .. -G %BUILD_GENERATOR% -B ../build/ -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -DBUILD_TARGET=WIN -Wno-dev -DVCPKG_TARGET_TRIPLET=%VCPKG_TRIPLET% -DCMAKE_TOOLCHAIN_FILE=%VCPKG_TOOLCHAIN%
cmake --build ../build/