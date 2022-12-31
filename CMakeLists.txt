cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(entneko)
	file (GLOB_RECURSE entneko_src
		"entneko/**.h"
		"entneko/**.cpp"
		)
	add_executable(entneko ${entneko_src})
	target_include_directories(entneko PUBLIC entneko)