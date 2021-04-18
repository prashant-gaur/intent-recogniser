find_path(INC_GTEST gtest.h PATH_SUFFIXES gtest)
include_directories(${INC_GTEST})
message(STATUS "INC_GTEST: ${INC_GTEST}")

find_path(INC_GMOCK gmock.h PATH_SUFFIXES gmock)
include_directories(${INC_GMOCK})
message(STATUS "INC_GMOCK: ${INC_GMOCK}")

## Project
project (UnitTests CXX)

## Build
set (TARGET unit-tests)
add_executable (${TARGET} "")

## Sources
target_sources(
    ${TARGET}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/Main.cpp
        ${PROJECT_SOURCE_DIR}/Unittests.cpp
        ${CMAKE_SOURCE_DIR}/src/DiscoverIntention.cpp
)

## Headers
target_include_directories (
    ${TARGET}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/interface
        ${PROJECT_SOURCE_DIR}/inc
        ${CMAKE_SOURCE_DIR}/inc
        ${CMAKE_SOURCE_DIR}/interface
)

# Link external/3rd party libs
target_link_libraries (
    ${TARGET}
    PRIVATE
      gtest
      gmock
      gmock_main
      pthread
)

# Compilation Params
target_compile_options (
    ${TARGET}
    PRIVATE
        -std=c++17
)

# Custom Commands

# Installation Lib/Binary/Systemd Service/DBus Service Config
install (
    TARGETS         ${TARGET}
    DESTINATION     ${PROJECT_SOURCE_DIR}/build
)