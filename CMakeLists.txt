cmake_minimum_required(VERSION 3.16)

project(remain_in_light LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
find_package(dlib REQUIRED)

add_executable(ril src/image_processing.cpp src/main.cpp)
target_link_libraries(ril PRIVATE ${OpenCV_LIBS} dlib::dlib)