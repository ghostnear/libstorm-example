cmake_minimum_required(VERSION 3.2)

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
    if(BUILD_TARGET MATCHES "ANDROID")
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -frtti")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frtti")
        SET(CMAKE_ANDROID_GUI TRUE)
    endif()
    # Project output path for install()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/)
endif()

add_compile_definitions(BUILD_TYPE_${BUILD_TARGET})
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# Project metadata
project(exampleApp)

# Project dependencies
add_subdirectory(external)

set(
    EXECUTABLE_FILES
    "src/main.cpp"
    "src/states/mainState.cpp"
)

# Project core
if(BUILD_TARGET MATCHES "WIN")
    add_executable(
        ${PROJECT_NAME}
        WIN32
        ${EXECUTABLE_FILES}
    )
else()
    add_executable(
        ${PROJECT_NAME}
        ${EXECUTABLE_FILES}
    )
endif()

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        libStorm
)

# Disables command prompt on windows
if(BUILD_TARGET MATCHES "WIN")
    target_link_options(${PROJECT_NAME} PRIVATE -mwindows)
endif()

# PSVita config
if(BUILD_TARGET MATCHES "VITA")
    ## Create Vita files
    vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
    # The FILE directive lets you add additional files to the VPK, the syntax is
    # FILE src_path dst_path_in_vpk. In this case, we add the LiveArea paths.
    vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
        VERSION ${VITA_VERSION}
        NAME ${VITA_APP_NAME}
        FILE assets/vita/icon0.png sce_sys/icon0.png
        FILE assets/vita/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
        FILE assets/vita/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
        FILE assets/vita/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
        FILE assets/fonts/LICENSE.md assets/fonts/LICENSE.md
        FILE assets/fonts/SourceCodePro-Light.otf assets/fonts/SourceCodePro-Light.otf
        FILE assets/fonts/SourceCodePro-SemiboldIt.otf assets/fonts/SourceCodePro-SemiboldIt.otf
    )
else()
    # Install executables
    install(TARGETS ${PROJECT_NAME} DESTINATION bin)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
    COMMAND "${CMAKE_COMMAND}" -E copy_directory
            "../assets/fonts"
            "../bin/assets/fonts" 
        COMMENT "Copying assets to output directory")  
endif()