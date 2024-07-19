#include <iostream>
#include <string>
#include <regex>
#include <curl/curl.h>
#include "gumbo.h"
#include "parser.h"

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void search_for_prices(GumboNode* node) {
    if (node->type != GUMBO_NODE_ELEMENT) return;

    GumboVector* children = &node->v.element.children;
    
    for (size_t i = 0; i < children->length; ++i) {
        GumboNode* child = static_cast<GumboNode*>(children->data[i]);
        
        if (child->type == GUMBO_NODE_TEXT) {
            std::string text = child->v.text.text;

            // список подходящих регулярных выражений (при необходимости должен быть расширен вместе со списком сайтов, подлежащих парсингу)
            std::regex price_regex1(R"([0-9]+ ₽)");
            std::regex price_regex2(R"([0-9]+ [0-9]{3} ₽))");  
            std::regex price_regex3(R"([0-9]+ [0-9]{3} руб))");
            // std::regex price_regex4(R"(\$[0-9]+(?:\.[0-9]{2})?)");

            std::smatch match; // для хранения совпадений, если они имеются
            if (
                std::regex_search(text, match, price_regex1) ||
                std::regex_search(text, match, price_regex2) ||
                std::regex_search(text, match, price_regex3)
                // std::regex_search(text, match, price_regex4) 
            ) {
                std::cout << "Цена: " << match.str() << '\n';
            }
        }
        search_for_prices(child);
    }
}