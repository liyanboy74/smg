cmake_minimum_required(VERSION 3.12)
project(smg)

add_executable(${PROJECT_NAME} smg.c)

# for build on windows you need 'argp' lib
# adding by below command and compile that:
#   'git add submodule https://github.com/liyanboy74/argp-standalone.git'
if (WIN32)
target_include_directories(${PROJECT_NAME} PUBLIC ./argp-standalone)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/argp-standalone/libargp.a)
endif (WIN32)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
