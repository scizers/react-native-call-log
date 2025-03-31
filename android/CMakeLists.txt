cmake_minimum_required(VERSION 3.13)
set(CMAKE_VERBOSE_MAKEFILE ON)

# Define the library name
project(reactnativecalllog)

# This file includes all the necessary to let you build your native module with React Native
include(${REACT_ANDROID_DIR}/cmake-utils/ReactNative-application.cmake)

# Add a shared library
add_library(${CMAKE_PROJECT_NAME} SHARED
  CallLogsModule.cpp
)

# Configure include directories
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
  "${PROJECT_BUILD_DIR}/generated/source/codegen/jni"
  "${REACT_ANDROID_DIR}/src/main/jni/react/turbomodule"
)

# Configure libraries for linking
target_link_libraries(${CMAKE_PROJECT_NAME}
  fbjni
  jsi
  react_nativemodule_core
  react_codegen_reactnativecalllog
)

# Use C++17
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)
