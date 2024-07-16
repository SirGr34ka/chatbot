#pragma once 

/**
 * @brief Функция обратного вызова, который curl использует для записи данных, полученных от http-запроса
 * 
 * @param contents указатель на полученные данные
 * @param size размер блока данных
 * @param nmemb количество блоков данных
 * @param userp указатель, переданный в CURLOPT_WRITEDATA (в main.cpp)
 */
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);

/**
 * @brief Функция поиска элемента html с информацией о цене товара
 * 
 * @param node узел дерева разбора html, который создаётся gumbo
 */
void search_for_prices(GumboNode* node);