/**
 * File:        Homework_III_Uku_Kaarel_Metspalu_CurlData.h
 * Author:      Uku Kaarel Metspalu
 * Created:     29.05.2023
 * Modified:    01.06.2023
 *
 * Description: Header file for retrieving xml data code file
 */

#ifndef HOMEWORK_III_UKU_KAAREL_METSPALU_CURLDATA_H
#define HOMEWORK_III_UKU_KAAREL_METSPALU_CURLDATA_H

#include <curl/curl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include "Homework_III_Uku_Kaarel_Metspalu_Main.h"

int isCacheValid(const char *fileName);
int PerformCurlRequest(const char* url, const char* outputFile); 
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) ;


#endif //HOMEWORK_III_UKU_KAAREL_METSPALU_CURLDATA_H