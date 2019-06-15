cmake_minimum_required(VERSION 3.11)
project(OOP_indie_studio_2018)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(PATH_MODULE_Irrlicht "${CMAKE_MODULE_PATH}/Irrlicht")
set(Irrlicht_DIR "${CMAKE_MODULE_PATH}/Irrlicht")

set(PATH_MODULE_SFML "${CMAKE_MODULE_PATH}/SFML")
set(SFML_DIR "${CMAKE_MODULE_PATH}/SFML")
set(SFML_ROOT "${CMAKE_MODULE_PATH}/SFML")

find_package(Irrlicht REQUIRED)

find_package(SFML 2 COMPONENTS system audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

include_directories(cmake)
include_directories(cmake/Irrlicht)
include_directories(cmake/Irrlicht/include)
include_directories(include)
include_directories(include/Irrlicht)

link_libraries(${Irrlicht_LIBRARIES})
link_libraries(${SFML_AUDIO_LIBRARY_RELEASE} ${SFML_SYSTEM_LIBRARY_RELEASE})

add_executable(bomberman
        include/Core.hpp
        include/Game.hpp
        include/GameStat.hpp
        include/Menu.hpp
        include/Player.hpp
        include/Select.hpp
        include/MyEventReceiver.hpp
        include/Pause.hpp
        src/Core.cpp
        src/Player.cpp
        src/Select.cpp
        src/Game.cpp
        src/main.cpp
        src/Menu.cpp
        src/MyEventReceiver.cpp
        src/Option.cpp
        src/Pause.cpp)

target_compile_options(bomberman PRIVATE -g3)

get_target_property(INDIE_EXE_PATH bomberman CMAKE_RUNTIME_OUTPUT_DIRECTORY)
