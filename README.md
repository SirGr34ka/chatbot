# TG Bot for parcing

* OS version: Windows 10 Version 22H2
* IDE: Visual Studio Code
* Compiler: GCC
* Additional libraries: curl, gumbo, tgbot-cpp

# Build

Последовательность сборки:
  # 1. Парсер
  For the parser to work, the CURL and GUMBO libraries are needed. Installation and connection via MSYS or VCPKG. MSYS will be used as an example.
Gumbo: pacman -S mingw-w64-x86_64-gumbo-parser and CURL: pacman -S mingw-w64-x86_64-curl. After installing the libraries using CMake Tools, create a build folder in parser_module, choosing GCC as the compiler.
  # 2. Телеграм бот
