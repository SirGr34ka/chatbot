#include <iostream>
#include <string>
#include <curl/curl.h>
#include "parser.h"

int main() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    // Эксперименты с LIBCURL
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.dns-shop.ru");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK) fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    

    // Планируется модифицировать эту часть с помощью модуля gumbo (или другого, если будет необходимо)
    std::cout << readBuffer << std::endl;

    return 0;
}
