cmake_minimum_required(VERSION 3.23)
project(classWordle)

set(CMAKE_CXX_STANDARD 14)

add_executable(classWordle main.cpp classWordle.h classWordle.cpp board.cpp board.h LetterBank.cpp LetterBank.h Input.cpp Input.h Word.cpp Word.h WordBank.cpp WordBank.h Wordle.cpp Wordle.h DrawBoard.cpp DrawBoard.h Square.cpp Square.h)
target_link_libraries(classWordle sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)