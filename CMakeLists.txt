cmake_minimum_required(VERSION 3.15)
project(BattleShipSrc)
set(CMAKE_CXX_STANDARD 14)

set(SRC_LIB_NAME BattleShipSrc)
set(EXE_NAME BattleShip)


add_library(${SRC_LIB_NAME} STATIC setup.cpp setup.h Game.cpp Game.h Player.cpp Player.h Board.cpp Board.h Ship.cpp Ship.h input_validation.cpp input_validation.h AIPlayer.cpp AIPlayer.h RandomAI.cpp RandomAI.h CheatingAI.cpp CheatingAI.h SearchDestroyAI.cpp SearchDestroyAI.h Utility.cpp Utility.h HumanPlayer.cpp HumanPlayer.h)
target_include_directories(${SRC_LIB_NAME}  PUBLIC .)
target_compile_options(${SRC_LIB_NAME}  PRIVATE -Wall -Wextra -Werror)

add_executable(${EXE_NAME} main.cpp)
target_link_libraries(${EXE_NAME} PRIVATE ${SRC_LIB_NAME})
target_compile_options(${EXE_NAME} PRIVATE -Wall -Wextra -Werror)
