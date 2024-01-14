/**
 * File:        parse.h
 * Author:      Uku Kaarel Metspalu
 * Created:     29.05.2023
 * Modified:    01.06.2023
 *
 * Description: Header file for  xml data processing code file
 */

#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "main.h"
#include "linked_list.h"

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

#endif //PARSE_H
