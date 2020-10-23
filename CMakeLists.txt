cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

project(kaleidoscope)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

set(CMAKE_CXX_STANDARD 17)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

include_directories(include/)
set(SOURCE_FILES src/toy.cpp)

add_executable(toy ${SOURCE_FILES})

llvm_map_components_to_libnames(llvm_libs orcjit ${LLVM_TARGETS_TO_BUILD})

target_link_libraries(toy ${llvm_libs})
