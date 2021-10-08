set(CMAKE_LEGACY_CYGWIN_WIN32 OFF)
cmake_minimum_required(VERSION 3.15)
project(GomaeronEngine C CXX)
add_definitions(-D_USE_MATH_DEFINES)
set(THIRD_PARTY_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/third_party/glad/include"
									"${CMAKE_CURRENT_SOURCE_DIR}/third_party/glfw-3.3.2/include"
									"${CMAKE_CURRENT_SOURCE_DIR}/third_party/eigen-3.3.9"
									"${CMAKE_CURRENT_SOURCE_DIR}/third_party/stb"
									)
set(GOMAERON_ENGINE_INCLUDE_DIRECTORY "${CMAKE_SOURCE_DIR}/source/")

if(MSVC)
	set(THIRD_PARTY_LIBRARIES glad glfw stb)
else()
	set(THIRD_PARTY_LIBRARIES glad glfw stb)
endif(MSVC)

configure_file(CMakeConfigFiles/root_directory.h.in "${CMAKE_SOURCE_DIR}/source/GomaEngineLib/root_directory.h")
add_subdirectory(third_party)
add_subdirectory(source)
