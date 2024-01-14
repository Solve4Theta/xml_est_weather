/**
 * File:        Homework_III_Uku_Kaarel_Metspalu_Main.c
 * Author:      Uku Kaarel Metspalu
 * Created:     29.05.2023
 * Modified:    01.06.2023
 *
 * Description: Main code file for Homework III
 */

#include "Homework_III_Uku_Kaarel_Metspalu_Main.h"

int main(void) 
{
	list *pHead = NULL;
	xmlDocPtr doc = NULL;
    PerformCurlRequest(DOC_URL, DOC_NAME);
    PerformCurlRequest(DOC_URL_EST, DOC_NAME_EST);

	FILE* fp = fopen(LINKED_LIST_FILE, "r");
    if (fp == NULL) 
	{
        printf("No user preferences found\n");
    }
	else
	{
		char *pStr = NULL;
		char str[51];
		
		while (fscanf(fp, " %[^\n]", str) == 1) 
		{
			pStr = strdup(str);
			if (pStr == NULL)
			{
				fprintf(stderr, "Error with strdup!\n");
			}

			struct node *newNode = CreateNode(pStr);
			free(pStr);
			InsertNode(&pHead, newNode);
		}

		fclose(fp);
	}
	


    while (1)
	{
		char *name = NULL;
		char *searchedNodeName = NULL; 
        int val = Menu();

		switch (val)
		{
			case 1:
				MainParse(pHead, doc, 1);
				break;
				
			case 2:
				MainParseEst();
				break;
			
			// Print linked list
			case 3:
				PrintList(pHead);
				break;
			
			case 4:
				/* case 2 - Ask user for the name; use CreateNode() to allocate
                 *          the node. Use InsertNode() to add it.*/
                
				name = MainParse(pHead, doc, 0);

                if (name)
                {
                    struct node *newNode = CreateNode(name);
                    free(name);
                    InsertNode(&pHead, newNode);
                    PrintListToFile(pHead);
                }
                
				break;

			case 5:
				/* case 4 - Allows the user to enter a node name. 
                   Finds a node by the id value using FindNodeByName().
                   Returned pointer is passed to PrintNode() to display it */
				
				searchedNodeName = GetName();
				RemoveNodeByName(&pHead, searchedNodeName);
                free(searchedNodeName);
				break;
			
			case 6:

				if (!pHead)
					EmptyFile();
				else
					Unload(pHead);
				
				return EXIT_SUCCESS;
			
			default:
				break;
		}
	}

    return EXIT_SUCCESS;
}

/**
 * Description: Function presents the user with menu options and gets user input. It also 
 * checks whether the user entered the correct number.
 * 
 * Parameters:  Void
 * Return:      User input as integer
 */
int Menu()
{
    char input[100];
    int num;
    bool isValidInteger = false;

	puts("1 - Weather");
	puts("2 - Estonia forecast");
	puts("3 - Print user preferred stations");
	puts("4 - Insert new station to user preferences");
	puts("5 - Remove station via name");
	puts("6 - Exit");

    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';

        isValidInteger = IsInteger(input);

        if (isValidInteger) 
        {
            num = atoi(input);

            if (num <= 6 && num >= 0)
                return num;
            else
                printf("Integer must be within correct bounds.\n");

        }
    }       
    
    return 0;
}

int IsInteger(const char* input) 
{
    char* endptr;
    strtol(input, &endptr, 10);
    
    // If the entire input was consumed and the end pointer is pointing to the null character,
    // the input was a valid integer
    return (*input != '\0' && *endptr == '\0');
}
