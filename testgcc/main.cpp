#include <iostream>
#include <string>
#include <regex>
#include <curl/curl.h>
#include "gumbo.h"
#include "parser.h"
#include "algorithm"
#include "string"
#include "main.h"

int main(int argc, char **argv)
{
  std::string arg = "iphone+14";
  std::cout << arg;
 
  std::string res = request(arg);
  std::cout << scrape(res) << std::endl;
  std::cout << std::endl;
  return EXIT_SUCCESS;
}