cmake_minimum_required(VERSION 3.10)
project(parser)

set(CMAKE_CXX_STANDARD 11)

# Путь к vcpkg
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)

# Добавление зависимостей
find_package(CURL REQUIRED)
#find_package(Gumbo REQUIRED) - в разработке

add_executable(parser main.cpp parser.cpp)

target_link_libraries(parser PRIVATE CURL::libcurl)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)