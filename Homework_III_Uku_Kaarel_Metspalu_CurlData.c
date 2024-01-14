/**
 * File:        Homework_III_Uku_Kaarel_Metspalu_CurlData.c
 * Author:      Uku Kaarel Metspalu
 * Created:     29.05.2023
 * Modified:    01.06.2023
 *
 * Description: Code file for retrieving xml data
 */

#include "Homework_III_Uku_Kaarel_Metspalu_CurlData.h"

/**
 * Description: Function to check if downloaded data is older than 1 hour.
 * 
 * Parameters:  const char *fileName - pointer to name of file
 * 
 * Return:      Void
 */
int isCacheValid(const char *fileName) 
{
    struct stat st;
    if (stat(fileName, &st) != 0) 
    {
        // File doesn't exist, need to download
        return 0;
    }
  
    // Get the current time
    time_t current_time = time(NULL);

    // Compare the file's last modification time with the current time
    if (current_time - st.st_mtime < 3600) 
    {
        // The file was modified within the last hour, skip download
        return 1;
    }

    // File exists but is outdated, need to download
    return 0;
}

/**
 * Description: Function to check if downloaded data is older than 1 hour.
 * 
 * Parameters:  void *buffer: pointer to the received data buffer. 
 * 
 *              size_t size: specifies the size of each data element received. 
 *  
 *              size_t nmemb: specifies the number of data elements received in the buffer. 
 *                  
 *              void *userdata: allows one to pass a user-defined pointer or data structure to the function. 
 * 
 * Return:      size_t written, ie total amount written to file
 */ 
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) 
{
    FILE* file = (FILE*)userp;
    size_t written = fwrite(contents, size, nmemb, file);

    // Does not necessarilyneed to return anything
    return written;
}

/**
 * Description: Function to retireve weather data from hardcoded URLs.
 * 
 * Parameters:  const char *url - pointer url string
 *              
 *              const char *outputFile - pointer string which will 
 * specify data file name
 * 
 * Return:      1 or 0, depending on success or failure of various 
 * operations taking place throughout the function.
 */
int PerformCurlRequest(const char* url, const char* outputFile) 
{
    CURL* curl = curl_easy_init();
    if (!curl) 
    {
        fprintf(stderr, "Error initializing libcurl\n");
        return 1;
    }

     // Check if the cache is valid
    if (isCacheValid(outputFile)) 
    {
        printf("Using cached data for %s\n", outputFile);
        curl_easy_cleanup(curl);
        return 0;
    }

    FILE* file = fopen(outputFile, "w");
    if (!file) 
    {
        fprintf(stderr, "Error opening file for writing\n");
        curl_easy_cleanup(curl);
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) 
    {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return 1;
    }

    curl_easy_cleanup(curl);
    fclose(file);
    return 0;
}

