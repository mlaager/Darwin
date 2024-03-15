cmake_minimum_required(VERSION 3.20)

project(darwin 
    DESCRIPTION "Test of a grpc based server (and client)." 
    LANGUAGES CXX
)

option(BUILD_SKIP_CLIENT "Skip the build of the client" OFF)

# Standards is set to C++ 20.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding subfolder property.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# External packages
find_package(absl CONFIG REQUIRED)
find_package(protobuf CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(gRPC)

# Add submodules build.
add_subdirectory(External/Frame)

# Sources.
add_subdirectory(Common)
if ( NOT ${BUILD_SKIP_CLIENT})
  add_subdirectory(Client)
endif()
add_subdirectory(Server)
if ( NOT ${BUILD_SKIP_CLIENT})
  add_subdirectory(Test)
endif()
