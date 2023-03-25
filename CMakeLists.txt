cmake_minimum_required(VERSION 3.21)
project(labor5)

set(CMAKE_CXX_STANDARD 14)

add_executable(labor6_FINAL test.cppT application.cpp Domain/client.cpp UI/auto_ui.cpp Controller/auto_controller.cpp Controller/test_controller.cpp Domain/auto.cpp Repository/auto_repository.cpp Repository/test_repository.cpp)
