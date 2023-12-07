cmake_minimum_required(VERSION 3.10)

project(FSAExample)

# Указываем, что нужно использовать стандарт C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем исполняемый файл main.cpp
add_executable(main main.cpp)

# Добавляем исполняемый файл machine.cpp
add_library(machine machine.cpp)

# Линкуем исполняемый файл с библиотекой
target_link_libraries(main machine)
