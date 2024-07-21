cmake_minimum_required(VERSION 3.10.2)
project(testbt)
add_executable(testbt main.cpp)
target_link_libraries(testbt C:/msys64/mingw64/lib/libboost_system-mt.a)
target_link_libraries(testbt C:/Users/konst/vcpkg/installed/x64-windows/lib/libssl.lib)
target_link_libraries(testbt C:/Users/konst/vcpkg/installed/x64-windows/lib/TgBot.lib)
target_link_libraries(testbt -lssl -lcrypto -lpthread)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lTgBot -lboost_system -lC:/Users/konst/vcpkg/installed/x64-windows/include/tgbot")

# add_custom_command(
#     TARGET testbt
#     POST_BUILD
#     COMMAND testbt
# )