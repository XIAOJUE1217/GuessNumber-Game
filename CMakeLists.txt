cmake_minimum_required(VERSION 3.14)
project(GuessNumber)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
  GIT_TAG main
)
FetchContent_MakeAvailable(ftxui)

file(GLOB SRC src/*.cpp src/*.h)
add_executable(game ${SRC})
target_link_libraries(game PRIVATE ftxui::ftxui)