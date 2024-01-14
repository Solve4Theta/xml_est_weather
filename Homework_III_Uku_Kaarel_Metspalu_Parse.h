/**
 * File:        Homework_III_Uku_Kaarel_Metspalu_Parse.h
 * Author:      Uku Kaarel Metspalu
 * Created:     29.05.2023
 * Modified:    01.06.2023
 *
 * Description: Header file for  xml data processing code file
 */

#ifndef HOMEWORK_III_UKU_KAAREL_METSPALU_PARSE_H
#define HOMEWORK_III_UKU_KAAREL_METSPALU_PARSE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "Homework_III_Uku_Kaarel_Metspalu_Main.h"
#include "Homework_III_Uku_Kaarel_Metspalu_LinkedList.h"

int VerifyName(xmlDocPtr doc, xmlNodePtr cur, char *name);
void StationsMultipleTraverse(xmlNodePtr cur, xmlDocPtr doc, list *pTemp);
void StationsTraverse(xmlNodePtr cur, xmlDocPtr doc);
void GetInfoEst(xmlDocPtr doc, xmlNodePtr cur);
void ParseEst (xmlDocPtr doc, xmlNodePtr cur);
int MainParseEst();
void GetInfo(xmlDocPtr doc, xmlNodePtr cur);
char * MainParse(list *pHead, xmlDocPtr doc, int opFlag);
void ParseStationDefault(xmlDocPtr doc, xmlNodePtr cur);
void ParseStationCustom(xmlDocPtr doc, xmlNodePtr cur, list *pTemp);

#endif //HOMEWORK_III_UKU_KAAREL_METSPALU_PARSE_H