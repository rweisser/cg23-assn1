cmake_minimum_required(VERSION 3.12...3.25)

# External source files
set(REPOS C:/Users/rweis/source/repos)
set(VECLIB ${REPOS}/VecLib)

project(Trace)
set(TARGET Trace)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${TARGET})

# set C++ version to use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# I'm lazy here, and building with all cpp files in src
file(GLOB SOURCES  "src/*.cpp")
file(GLOB INCLUDES "src/*.hpp")
file(GLOB INLINES  "src/*.inl")

add_executable(${TARGET}
               ${SOURCES}
               ${INCLUDES}
               ${INLINES}
               ${VECLIB}/Vec2.hpp
               ${VECLIB}/Vec2.inl
               ${VECLIB}/Vec2.cpp
               ${VECLIB}/Vec3.hpp
               ${VECLIB}/Vec3.inl
               ${VECLIB}/Vec3.cpp
)

# This did not work to add VecLib to the list of include directories.
# target_include_directories(Trace PRIVATE ${VecLib})

# Add VecLib to the list of include directories.
include_directories(${VECLIB})

# Set balls3-color.ray as the command line arguemnt in debug mode.
# The VS_DEBUGGER_COMMAND_ARGUMENTS property is specific to Visual Studio.
set_target_properties(Trace PROPERTIES
                      VS_DEBUGGER_COMMAND_ARGUMENTS
                      balls3-color.ray
)

# set up config.h to find directories
set(PROJECT_BASE_DIR   "${PROJECT_SOURCE_DIR}")
set(PROJECT_DATA_DIR   "${PROJECT_BASE_DIR}/data")
set(PROJECT_BUILD_DIR  "${PROJECT_BINARY_DIR}")
set(PROJECT_OUTPUT_DIR "${PROJECT_BASE_DIR}/output")
configure_file(src/Config.h.in Config.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
