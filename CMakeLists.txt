cmake_minimum_required(VERSION 3.8)
project(ArduinoC)

set(CMAKE_CXX_STANDARD 11)
include_directories(./arduino-libraries/include)
include_directories(./arduino-libraries/arduino)
include_directories(./arduino-libraries/libraries/Wire/src)
include_directories(./arduino-libraries/libraries/SPI/src)
include_directories(src)
#set(SOURCE_FILES src/main.cpp)

SET(TARGET_SRC
        src/BigInt.cpp
        )
set(SOURCE_FILES
        src/main_test.cpp
        src/BigInt.cpp)
add_executable(ArduinoC ${SOURCE_FILES})