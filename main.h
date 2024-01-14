/**
 * File:        main.h
 * Author:      Uku Kaarel Metspalu
 * Created:     29.05.2023
 * Modified:    01.06.2023
 *
 * Description: Header file for main code file
 */

#ifndef MAIN_H
#define MAIN_H

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <stdbool.h>
#include "parse.h"
#include "curl_data.h"

#define DOC_URL_EST "https://www.ilmateenistus.ee/ilma_andmed/xml/forecast.php?lang=eng"
#define DOC_NAME_EST "est.xml"
#define DOC_URL "https://www.ilmateenistus.ee/ilma_andmed/xml/observations.php"
#define DOC_NAME "output.xml"

int Menu();
int IsInteger(const char* input);

#endif //MAIN_H
