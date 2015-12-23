cmake_minimum_required(VERSION 3.2.2)
project(CHOUI)

set(CMAKE_MODULE_PATH "/usr/share/cmake/Modules/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package(SFML 2.3.2 COMPONENTS graphics window system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

add_subdirectory(${CMAKE_SOURCE_DIR}/deps)
include_directories(${CMAKE_SOURCE_DIR}/deps/STP/include)

add_definitions("-Wall -g")


set(SOURCE_FILES main.cpp Entity.cpp Entity.h Animation.cpp Animation.h AnimatedSprite.cpp AnimatedSprite.h Player.cpp Player.h Mob.cpp Mob.h NPC.cpp NPC.h)
add_executable(CHOUI ${SOURCE_FILES})
target_link_libraries(CHOUI ${SFML_LIBRARIES} STP)

