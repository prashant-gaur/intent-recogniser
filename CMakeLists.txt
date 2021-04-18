cmake_minimum_required (VERSION 3.1.3)
include(GNUInstallDirs)

## Project
project (EmbeddedIntentRecognizer CXX)

## Build
set (TARGET application)
add_executable (${TARGET} "")

## Sources
target_sources(
    ${TARGET}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/app/Main.cpp
        ${PROJECT_SOURCE_DIR}/src/DiscoverIntention.cpp
)

## Headers
target_include_directories (
    ${TARGET}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/interface
        ${PROJECT_SOURCE_DIR}/inc
)

# Link external/3rd party libs
target_link_libraries (
    ${TARGET}
    PRIVATE
)

# Compilation Params
target_compile_options (
    ${TARGET}
    PRIVATE
        -std=c++17
        -Wall
        -Werror
        -Wunused
        -pedantic
)

# Custom Commands

# Installation Lib/Binary/Systemd Service/DBus Service Config
install (
    TARGETS         ${TARGET}
    DESTINATION     ${PROJECT_SOURCE_DIR}/build
)

# Unit Tests
add_subdirectory(tests)