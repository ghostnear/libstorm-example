cmake_minimum_required(VERSION 3.9)

# PSvita specifics
if(BUILD_TARGET MATCHES "VITA")
    # VitaSDK is required
    if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
        if(DEFINED ENV{VITASDK})
            set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
        else()
            message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
        endif()
    endif()

    include("$ENV{VITASDK}/share/vita.cmake" REQUIRED)

    ## Configuration options for this app
    # Display name (under bubble in LiveArea)
    set(VITA_APP_NAME "libStorm Example")
    # Unique ID must be exactly 9 characters. Recommended: XXXXYYYYY where X =
    # unique string of developer and Y = a unique number for this app
    set(VITA_TITLEID  "STRM00000")
    # Optional version string to show in LiveArea's more info screen
    set(VITA_VERSION  "00.01")
else()
    # Project output path for install()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/)
endif()

# Project metadata
project(exampleApp)

# Project dependencies
add_subdirectory(external)

# Project core
add_executable(
    ${PROJECT_NAME}
    "src/main.cpp"
    "src/states/mainState.cpp"
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        libStorm
)

# PSVita config
if(BUILD_TARGET MATCHES "VITA")
    ## Create Vita files
    vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
    # The FILE directive lets you add additional files to the VPK, the syntax is
    # FILE src_path dst_path_in_vpk. In this case, we add the LiveArea paths.
    vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
        VERSION ${VITA_VERSION}
        NAME ${VITA_APP_NAME}
        FILE assets/sce_sys/icon0.png sce_sys/icon0.png
        FILE assets/sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
        FILE assets/sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
        FILE assets/sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
    )
else()
    # Install executables
    install(TARGETS ${PROJECT_NAME} DESTINATION bin)
endif()