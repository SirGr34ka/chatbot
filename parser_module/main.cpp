#include <iostream>
#include <string>
#include <regex>
#include <curl/curl.h>
#include "gumbo.h"
#include "parser.h"

int main() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    std::string sitename;
    std::cout << "Введите полную ссылку на веб-страницу: \n";
    std::cin >> sitename;
    
    // часть curl
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, sitename);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK) fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    
    // std::cout << readBuffer << std::endl;
    
    // часть gumbo
    GumboOutput* output = gumbo_parse(readBuffer.c_str());
    search_for_prices(output->root);
    gumbo_destroy_output(&kGumboDefaultOptions, output);
    return 0;
}
