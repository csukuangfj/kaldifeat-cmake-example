# Copyright (c)  2022  Xiaomi Corporation (author: Fangjun Kuang)

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(kaldifeat-cmake-example)

if(DEFINED Torch_DIR)
  list(APPEND CMAKE_PREFIX_PATH "${Torch_DIR}")
elseif(DEFINED ENV{Torch_DIR})
  list(APPEND CMAKE_PREFIX_PATH "$ENV{Torch_DIR}")
endif()

find_package(Torch QUIET)
if(NOT Torch_FOUND)
  message(FATAL_ERROR "Please use
  export Torch_DIR=$(python -c 'import torch; print(torch.utils.cmake_prefix_path)')
  mkdir build
  cd build
  cmake ..
  ")
endif()
message(STATUS "Torch_DIR: ${Torch_DIR}")


if(DEFINED kaldifeat_DIR)
  list(APPEND CMAKE_PREFIX_PATH "${kaldifeat_DIR}")
elseif(DEFINED ENV{kaldifeat_DIR})
  list(APPEND CMAKE_PREFIX_PATH "$ENV{kaldifeat_DIR}")
endif()

find_package(kaldifeat QUIET)
if(NOT kaldifeat_FOUND)
  message(FATAL_ERROR "Please use
  export kaldifeat_DIR=$(python -c 'import kaldifeat; print(kaldifeat.cmake_prefix_path)')
  mkdir build
  cd build
  cmake ..
  ")
endif()
message(STATUS "kaldifeat_DIR: ${kaldifeat_DIR}")

string(APPEND CMAKE_CXX_FLAGS " ${TORCH_CXX_FLAGS} ")
string(APPEND CMAKE_CXX_FLAGS " ${KALDIFEAT_CXX_FLAGS} ")
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")

add_executable(main main.cc)
target_link_libraries(main PRIVATE ${TORCH_LIBRARIES} ${KALDIFEAT_LIBRARIES})
