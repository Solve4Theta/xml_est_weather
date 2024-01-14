/**
 * File:        curl_data.h
 * Author:      Uku Kaarel Metspalu
 * Created:     29.05.2023
 * Modified:    01.06.2023
 *
 * Description: Header file for retrieving xml data code file
 */

#ifndef CURL_DATA_H
#define CURL_DATA_H

#include <curl/curl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include "main.h"

int isCacheValid(const char *fileName);
int PerformCurlRequest(const char* url, const char* outputFile); 
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) ;


#endif //CURL_DATA_H
