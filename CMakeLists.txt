cmake_minimum_required(VERSION 3.12)

project(theGame)

add_executable(theGame
	menu/menu.cpp
	menu/menu.h	
	theGame.cpp
	theGame.h
	functions.cpp
	functions.h
)

target_include_directories( theGame PRIVATE
	${CMAKE_SOURCE_DIR}/menu/
)

set_target_properties( game PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)