cmake_minimum_required(VERSION 3.10)
project(parser)

set(CMAKE_CXX_STANDARD 14)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# Добавление зависимостей
find_package(CURL)
find_package(unofficial-gumbo CONFIG REQUIRED)

if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    add_definitions(-DHAVE_CURL)
endif()

add_executable(parser main.cpp parser.cpp)
target_link_libraries(parser unofficial::gumbo::gumbo)
# target_link_libraries(parser C:/msys64/mingw64/lib/libcurl.a C:/msys64/home/admitrew/gumbo-parser/build/libgumbo.a) - эксперименты со статическими библиотеками (могут понадобиться)

add_custom_command(
    TARGET parser
    POST_BUILD
    COMMAND parser
)

include(CPack)
