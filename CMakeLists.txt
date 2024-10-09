cmake_minimum_required(VERSION 3.5)

project(SDL_TD VERSION 0.1 LANGUAGES CXX)

find_package(SDL2 QUIET)

set(SDL_INCLUDE_DIRS ${SDL2_INCLUDE_DIRS})
set(SDL_LIBRARIES ${SDL2_LIBRARIES})

find_library(SDL_MIXER_LIBRARY NAMES SDL2_mixer)
include_directories(${SDL_INCLUDE_DIRS})

file(GLOB_RECURSE PROJECT_SOURCES src/*.cpp)
file(GLOB_RECURSE PROJECT_HEADERS src/*.hpp)

add_executable(SDL_TD
	${PROJECT_SOURCES}
	${PROJECT_HEADERS}
)

target_link_libraries(SDL_TD
	${SDL_LIBRARIES}
	${SDL_MIXER_LIBRARY}
	fmt
)
