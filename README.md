# TG Bot for parcing

* OS version: Windows 10 Version 22H2
* IDE: Visual Studio Code
* Compiler: GCC
* Additional libraries: curl, gumbo, tgbot-cpp

# Build

Последовательность сборки:
  # 1. Парсер
  Для работы парсера, необходимы библиотеки CURL и GUMBO. Установка и подключение через MSYS или VCPKG. В качестве примера будет использоваться MSYS.
Gumbo: pacman -S mingw-w64-x86_64-gumbo-parser и CURL: pacman -S mingw-w64-x86_64-curl. После установки библиотек с помощью CMake Tools создаем build папку в parser_module, выбирая GCC в качестве компилятора.
  # 2. Телеграм бот
