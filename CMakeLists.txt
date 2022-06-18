cmake_minimum_required(VERSION 3.12)
project(smg)

add_executable(${PROJECT_NAME} main.c)

target_include_directories(${PROJECT_NAME} PUBLIC ./argp-standalone)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/argp-standalone/libargp.a)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
