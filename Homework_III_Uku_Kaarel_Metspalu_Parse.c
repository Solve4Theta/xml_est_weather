/**
 * File:        Homework_III_Uku_Kaarel_Metspalu_Parse.c
 * Author:      Uku Kaarel Metspalu
 * Created:     29.05.2023
 * Modified:    01.06.2023
 *
 * Description: Code file for processing xml data
 */

#include "Homework_III_Uku_Kaarel_Metspalu_Parse.h"

/**
 * Description: Accesses xml data in order to display max and
 * min temp for Estonia 
 * 
 * Parameters:  xmlDocPtr doc - libxml2 data structure for parsing
 * xml document
 *              xmlNodePtr cur - libxml2 data structure for traversing 
 * xml document
 * 
 * Return:      Void
 */
void GetInfoEst(xmlDocPtr doc, xmlNodePtr cur)
{
    cur = cur->xmlChildrenNode;
    
    while (cur != NULL)
    {
        if ((!xmlStrcmp(cur->name, (const xmlChar *)"tempmin"))) 
        {
            xmlChar *temp = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            printf("min temp: %s\n", temp);
            xmlFree(temp);
        }
        else if ((!xmlStrcmp(cur->name, (const xmlChar *)"tempmax"))) 
        {
            xmlChar *temp = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            printf("max temp: %s\n", temp);
            xmlFree(temp);
        }

        cur = cur->next;
    }
}

/**
 * Description: Accesses xml data in order to distinguish from night
 * and day data
 * 
 * Parameters:  xmlDocPtr doc - libxml2 data structure for parsing
 * xml document
 *              xmlNodePtr cur - libxml2 data structure for traversing 
 * xml document
 * 
 * Return:      Void
 */
void ParseEst (xmlDocPtr doc, xmlNodePtr cur) 
{
    cur = cur->xmlChildrenNode;
    while (cur != NULL) 
    {
        if ((!xmlStrcmp(cur->name, (const xmlChar *)"night"))) 
        {
            printf("\nNight:\n");
            GetInfoEst(doc, cur);
        }
        else if ((!xmlStrcmp(cur->name, (const xmlChar *)"day"))) 
        {
            printf("\nDay:\n");
            GetInfoEst(doc, cur);
        }

        cur = cur->next;
    }
}

/**
 * Description: Deals with all of the initial document processing,
 * parsing, and error checking for xml data about Estonia. Calls out
 * subsidiary function for traversing the document.
 * 
 * Parameters:  None
 * 
 * Return:      integer, depending on success or failure
 */
int MainParseEst()
{
    xmlDocPtr doc;
    xmlNodePtr cur;
    
    doc = xmlParseFile(DOC_NAME_EST);

    if (doc == NULL ) 
    {
        fprintf(stderr,"Document not parsed successfully.\n");
        xmlFreeDoc(doc);
        xmlCleanupParser();
        return 1;
    }

    cur = xmlDocGetRootElement(doc);

    if (cur == NULL) 
    {
        fprintf(stderr,"empty document\n");
        xmlFreeDoc(doc);
        xmlCleanupParser();
        return 1;
    }

    if (xmlStrcmp(cur->name, (const xmlChar *) "forecasts")) 
    {
        fprintf(stderr,"document of the wrong type, root node != forecasts\n");
        printf("%s\n", cur->name);
        xmlFreeDoc(doc);
        xmlCleanupParser();
        return 1;
    }

    cur = cur->xmlChildrenNode;
    while (cur != NULL) 
    {
        if ((!xmlStrcmp(cur->name, (const xmlChar *)"forecast")))
        {
            printf("\nforecast date: %s\n", xmlGetProp(cur, (const xmlChar*)"date"));
            ParseEst(doc, cur);
        }
        
        cur = cur->next;
    }

    xmlFreeDoc(doc);
    xmlCleanupParser();

    return 0;
}

/**
 * Description: Function to access data and display hardcoded
 * data fields in xml document.
 * 
 * Parameters:  xmlDocPtr doc - libxml2 data structure for parsing
 * xml document
 *              xmlNodePtr cur - libxml2 data structure for traversing 
 * xml document
 * 
 * Return:      Void
 */
void GetInfo(xmlDocPtr doc, xmlNodePtr cur)
{
    float latitude, longitude;

    while (cur != NULL)
    {
        if ((!xmlStrcmp(cur->name, (const xmlChar *)"longitude"))) 
        {
            xmlChar *var;
            var = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            longitude = strtof((const char*)var, NULL);
            xmlFree(var);
        }
        else if ((!xmlStrcmp(cur->name, (const xmlChar *)"latitude"))) 
        {
            xmlChar *var;
            var = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            latitude = strtof((const char*)var, NULL);
            xmlFree(var);
            printf("Google Maps URL: https://www.google.com/maps/place/%lf,%lf\n", latitude, longitude);
        }
        else if ((!xmlStrcmp(cur->name, (const xmlChar *)"phenomenon"))) 
        {
            xmlChar *var = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            printf("Phenomenon: %s\n", var);
            xmlFree(var);
        }
        else if ((!xmlStrcmp(cur->name, (const xmlChar *)"precipitations"))) 
        {
            xmlChar *var = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            printf("Precipitations (mm): %s\n", var);
            xmlFree(var);
        }
        else if ((!xmlStrcmp(cur->name, (const xmlChar *)"airpressure"))) 
        {
            xmlChar *var = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            printf("Airpressure (hPa): %s\n", var);
            xmlFree(var);
        }
        else if ((!xmlStrcmp(cur->name, (const xmlChar *)"relativehumidity"))) 
        {
            xmlChar *var = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            printf("Relative humidity (pcnt): %s\n", var);
            xmlFree(var);
        }
        else if ((!xmlStrcmp(cur->name, (const xmlChar *)"airtemperature"))) 
        {
            xmlChar *var = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            printf("Temperature (C): %s\n", var);
            xmlFree(var);
        }
        else if ((!xmlStrcmp(cur->name, (const xmlChar *)"windspeed"))) 
        {
            xmlChar *var = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            printf("Average windspeed (m/s): %s\n", var);
            xmlFree(var);
        }
        else if ((!xmlStrcmp(cur->name, (const xmlChar *)"windspeedmax"))) 
        {
            xmlChar *var = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            printf("Max windspeed (m/s): %s\n", var);
            xmlFree(var);
        }

        cur = cur->next;
    }
}

/**
 * Description: Function to traverse,  access and display hardcoded
 * data fields in xml document. Function is called when user preferences
 * are detected and thus, xml document data must be further traversed.
 * 
 * Parameters:  xmlDocPtr doc - libxml2 data structure for parsing
 * xml document
 *              xmlNodePtr cur - libxml2 data structure for traversing 
 * xml document
 * 
 * Return:      Void
 */
void ParseStationCustom(xmlDocPtr doc, xmlNodePtr cur, list *pTemp) 
{
    xmlNodePtr childNode = cur->xmlChildrenNode;
    xmlChar *var;

    while (childNode != NULL) 
    {
        if ((!xmlStrcmp(childNode->name, (const xmlChar *)"name"))) 
        {
            var = xmlNodeListGetString(doc, childNode->xmlChildrenNode, 1);
            
            if (!xmlStrcmp(var, (const xmlChar *)pTemp->name))
            {
                // puts("I get here");
                printf("\nStation name: %s\n", xmlNodeListGetString(doc, childNode->xmlChildrenNode, 1));
                GetInfo(doc, childNode);
                xmlFree(var);
                break;
            }
        }
        
        childNode = childNode->next;
    }
    
    xmlFree(var);
}

/**
 * Description: Function to traverse and display default, hardcoded
 * data fields in xml document. Function is called when no user preferences
 * are found.
 * 
 * Parameters:  xmlDocPtr doc - libxml2 data structure for parsing
 * xml document
 *              xmlNodePtr cur - libxml2 data structure for traversing 
 * xml document
 * 
 * Return:      Void
 */
void ParseStationDefault(xmlDocPtr doc, xmlNodePtr cur) 
{
    xmlNodePtr childNode = cur->xmlChildrenNode;
    while (childNode != NULL) 
    {
        if ((!xmlStrcmp(childNode->name, (const xmlChar *)"name"))) 
        {
            xmlChar *var = xmlNodeListGetString(doc, childNode->xmlChildrenNode, 1);

            if (!xmlStrcmp(var, (const xmlChar *)"Tallinn-Harku"))
            {
                printf("\nStation name: %s\n", var);
                xmlFree(var);
                GetInfo(doc, childNode);
            }
            else if (!xmlStrcmp(var, (const xmlChar *)"Tartu-Tõravere"))
            {
                printf("\nStation name: %s\n", var);
                xmlFree(var);
                GetInfo(doc, childNode);
            }
            else if (!xmlStrcmp(var, (const xmlChar *)"Narva"))
            {
                printf("\nStation name: %s\n", var);
                xmlFree(var);
                GetInfo(doc, childNode);
            }
        }

        childNode = childNode->next;
    }
}

/**
 * Description: Function to perform initial routines and check for 
 * errors in either used xml document or the actions that are taken
 * towards processing the document. 
 * 
 * Parameters:  xmlDocPtr doc - libxml2 data structure for parsing
 * xml document
 *              xmlNodePtr cur - libxml2 data structure for traversing 
 * xml document
 * 
 *              int opFlag - in order to determine if MainParse will 
 * traverse data further or verify user input.
 * 
 * Return:      Void
 */
char * MainParse(list *pHead, xmlDocPtr doc, int opFlag)
{
    xmlNodePtr cur;
    int nameCheck;
    char *name = NULL;
    struct node *nodeCheck;
    
    doc = xmlParseFile(DOC_NAME);

    if (doc == NULL ) 
    {
        fprintf(stderr,"Document not parsed successfully.\n");
        xmlFreeDoc(doc);
        xmlCleanupParser();
    }

    cur = xmlDocGetRootElement(doc);

    if (cur == NULL) 
    {
        fprintf(stderr,"empty document\n");
        xmlFreeDoc(doc);
        xmlCleanupParser();
    }

    if (xmlStrcmp(cur->name, (const xmlChar *) "observations")) 
    {
        fprintf(stderr,"document of the wrong type, root node != observations\n");
        printf("%s\n", cur->name);
        xmlFreeDoc(doc);
        xmlCleanupParser();
    }

    if (opFlag)
    {
        if (!pHead)
        {
            printf("\nDisplaying default locations\n\n");
            StationsTraverse(cur, doc);
        }
        else
        {
            list *pTemp = pHead;
            StationsMultipleTraverse(cur, doc, pTemp);
        }
    }
    else
    {
        do
        {
            name = GetName();
            nameCheck = VerifyName(doc, cur, name);
        } 
        while (nameCheck != 0);

        nodeCheck = CheckForDoubleNode(pHead, name);

        if (nodeCheck)
        {
            printf("Station is already in user preferred stations!\n");
            xmlFreeDoc(doc);
            xmlCleanupParser();
            name = NULL;
            return name;        
        }
    }
    
    xmlFreeDoc(doc);
    xmlCleanupParser();
    
    return name;
}

/**
 * Description: Verifies user input in the context of adding a new weather 
 * station to user preferences
 * 
 * Parameters:  xmlDocPtr doc - libxml2 data structure for parsing
 * xml document
 *              xmlNodePtr cur - libxml2 data structure for traversing 
 * xml document
 * 
 *              char *name - pointer to string, which will undergo verification
 * 
 * Return:      integer, signifying success or failure 
 */
int VerifyName(xmlDocPtr doc, xmlNodePtr cur, char *name) 
{
    xmlNodePtr stations;
    stations = cur->xmlChildrenNode;
    xmlChar *var;

    while (stations != NULL) 
    {
        if ((!xmlStrcmp(stations->name, (const xmlChar *)"station")))
        {
            xmlNodePtr childNode = stations->xmlChildrenNode;
            while (childNode != NULL) 
            {
                if ((!xmlStrcmp(childNode->name, (const xmlChar *)"name"))) 
                {
                    var = xmlNodeListGetString(doc, childNode->xmlChildrenNode, 1);

                    if (!xmlStrcmp(var, (const xmlChar *)name))
                    {
                        printf("Name successfully verified\n");
                        xmlFree(var);
                        return 0;
                    }
                }
                childNode = childNode->next;
            }
        }   
        stations = stations->next;
    }
    
    xmlFree(var);
    printf("Name not verified\n");
    return 1;
}

/**
 * Description: Function to perform one part of xml data traversing and 
 * call out subsidiary function for further traversing. Used, when no
 * user preferences are found.
 * 
 * Parameters:  xmlDocPtr doc - libxml2 data structure for parsing
 * xml document
 *              xmlNodePtr cur - libxml2 data structure for traversing 
 * xml document
 * 
 * Return:      Void
 */
void StationsTraverse(xmlNodePtr cur, xmlDocPtr doc)
{
    xmlNodePtr stations;
    stations = cur->xmlChildrenNode;
    while (stations != NULL) 
    {
        if ((!xmlStrcmp(stations->name, (const xmlChar *)"station")))
        {
            ParseStationDefault(doc, stations);
        }   

        stations = stations->next;
    }
}

/**
 * Description: Function to perform one part of xml data traversing and 
 * call out subsidiary function for further traversing. Used, when 
 * user preferences are found.
 * 
 * Parameters:  xmlDocPtr doc - libxml2 data structure for parsing
 * xml document
 *              xmlNodePtr cur - libxml2 data structure for traversing 
 * xml document
 * 
 * Return:      Void
 */
void StationsMultipleTraverse(xmlNodePtr cur, xmlDocPtr doc, list *pTemp)
{
    xmlNodePtr stations;
    while (pTemp->id >= 0)
    {
        stations = cur->xmlChildrenNode;
        while (stations != NULL) 
        {
            if ((!xmlStrcmp(stations->name, (const xmlChar *)"station")))
            {
                ParseStationCustom(doc, stations, pTemp);
            }   

            stations = stations->next;
        }

        if (pTemp -> pNext == NULL)
        {
            break;
        }

        pTemp = pTemp->pNext;
    }
}