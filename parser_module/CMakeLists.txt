include(FetchContent)
FetchContent_Declare(
    gumbo-module
    GIT_REPOSITORY https://github.com/google/gumbo-parser.git
    GIT_TAG master
)
FetchContent_MakeAvailable(gumbo-module)

cmake_minimum_required(VERSION 3.10)
project(parser)

set(CMAKE_CXX_STANDARD 11)

# Путь к vcpkg
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)

include_directories(C:/msys64/mingw64/include)
link_directories(C:/msys64/mingw64/lib)
# Добавление зависимостей
find_package(CURL REQUIRED)
#find_package(Gumbo REQUIRED) 
#find_package(unofficial-gumbo CONFIG REQUIRED) - альтернативный путь

add_executable(parser main.cpp parser.cpp)
target_link_libraries(parser curl gumbo)
# target_link_libraries(parser C:/msys64/mingw64/lib/libcurl.a C:/msys64/home/admitrew/gumbo-parser/build/libgumbo.a) - эксперименты со статическими библиотеками (могут понадобиться)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)