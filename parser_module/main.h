#include <iostream>
#include <string>
#include <regex>
#include <curl/curl.h>
#include "gumbo.h"
#include "parser.h"
#include "algorithm"
#include "string"

typedef size_t( * curl_write)(char * , size_t, size_t, std::string * );

std::string request(std::string word);

std::string extract_text(GumboNode *node);

std::string find_definitions(GumboNode *node);

std::string scrape(std::string markup);

std::string str_replace(std::string search, std::string replace, std::string &subject);

std::string extract_text(GumboNode *node);

std::string strtolower(std::string str);