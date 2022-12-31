cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(example)
	file (GLOB_RECURSE example_src
		"example/**.h"
		"example/**.cpp"
		)
	add_executable(example ${example_src})
	target_include_directories(example PUBLIC include)