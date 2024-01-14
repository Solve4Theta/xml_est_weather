/**
 * File:        Homework_III_Uku_Kaarel_Metspalu_Main.h
 * Author:      Uku Kaarel Metspalu
 * Created:     29.05.2023
 * Modified:    01.06.2023
 *
 * Description: Header file for main code file
 */

#ifndef HOMEWORK_III_UKU_KAAREL_METSPALU_MAIN_H
#define HOMEWORK_III_UKU_KAAREL_METSPALU_MAIN_H

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <stdbool.h>
#include "Homework_III_Uku_Kaarel_Metspalu_Parse.h"
#include "Homework_III_Uku_Kaarel_Metspalu_CurlData.h"
#include "Homework_III_Uku_Kaarel_Metspalu_CurlData.h"

#define DOC_URL_EST "https://www.ilmateenistus.ee/ilma_andmed/xml/forecast.php?lang=eng"
#define DOC_NAME_EST "est.xml"
#define DOC_URL "https://www.ilmateenistus.ee/ilma_andmed/xml/observations.php"
#define DOC_NAME "output.xml"

int Menu();
int IsInteger(const char* input);

#endif //HOMEWORK_III_UKU_KAAREL_METSPALU_MAIN_H