/**
 * File:        linked_list.c
 * Author:      Uku Kaarel Metspalu
 * Created:     29.05.2023
 * Modified:    01.06.2023
 *
 * Description: Code file for linked list
 */

#include "linked_list.h"

/**
 * Description: Checks via node name if is already in the linked list.
 * 
 * Parameters:  list *pHead - pointer to the head of the linked list.
 *              char *name - node name to be checked.
 * 
 * Return:      NULL if node is not in list, pointer to node if it is
 * in the list.
 */
struct node *CheckForDoubleNode(list *pHead, char *name)
{
	list *pTemp;
	
	while (pHead != NULL)
	{
		pTemp = pHead;
		if (strcmp(pTemp->name, name) == 0)
		{
			return pTemp;
		}
		
		pHead = pHead->pNext;
	}
	
    return NULL;
};

/**
 * Description: Retrieves ID of node in linked list. NB! Function is not
 * in use in the program at the moment, rather it is kept in case any 
 * further development takes place in the near future.
 * 
 * Parameters:  Void
 * 
 * Return:      User input as integer
 */
int GetNodeId(void)
{
	int id;
	puts("Enter node ID:");
	scanf("%d", &id);
	
	return id;
}

/**
 * Description: Retrieves a string from the user and returns pointer to
 * the string. 
 * 
 * Parameters:  Void
 * 
 * Return:      Pointer to string
 */
char * GetName(void)
{
	char *pName = NULL;
	// Static buffer. A possibility for buffer overflow. Must be mentioned
	// in documentation
	char name[1024];
	puts("Enter weather station name:");
	scanf(" %[^\n]", name);
	pName = strdup(name);
    if (pName == NULL)
    {
        fprintf(stderr, "Error with strdup!\n");
    }
	
	return pName;
}

/**
 * Description: Finds a node from linked list given the node ID. Returns node
 * if node is found, and NULL is node is not found.
 * 
 * Parameters:  list *pHead - pointer to the head node
 * 				int id - ID integer of desired node
 * 
 * Return:      Pointer to desired node if node is found, NULL if node is not found.
 */
struct node *FindNodeByID(list *pHead, int id)
{
	list *pTemp;
	
	while (pHead != NULL)
	{
		pTemp = pHead;
		if (pTemp->id == id)
		{
			return pTemp;
		}
		pHead = pHead->pNext;
	}
	return NULL;
};

/**
 * Description: Finds a node from linked list given the node name. 
 * 
 * Parameters:  list *pHead - pointer to the head node
 * 				char *name - pointer to name of desired node
 * 
 * Return:      Pointer to desired node if node is found, NULL if node is not found.
 */
struct node *FindNodeByName(list *pHead, char *name)
{
	list *pTemp;
	
	while (pHead != NULL)
	{
		pTemp = pHead;
		if (strcmp(pTemp->name, name) == 0)
		{
			return pTemp;
		}
		
		pHead = pHead->pNext;
	}
	free(name);
	return NULL;
};

/**
 * Description: Destroys linked list in a memory safe manner. Used 
 * 
 * Parameters:  list *pHead - pointer to the head node
 * 
 * Return:      Void
 */
void Unload(list *pHead)
{
	list *pTemp;
    
	while (pHead != NULL)
	{
		pTemp = pHead;
		free(pHead->name);
		pHead = pHead->pNext;
		free(pTemp);
	}
}

/**
 * Description: Destroys linked list in a memory safe manner. Used
 * when user exits program and linked list contains one or more nodes.
 * 
 * Parameters:  list **pHead - pointer to pointer of the head of the list.
 * 				char *name - pointer to name of to be removed node
 * 
 * Return:      Void
 */
void RemoveNodeByName(list **ppHead, char *name) 
{
    list *current = *ppHead;
    list *previous = NULL;
    
    while (current != NULL) 
	{
        if (strcmp(current->name, name) == 0) 
		{
            if (previous == NULL) 
			{
                // Node to be removed is the head node
                *ppHead = current->pNext;
            } 
			else 
			{
                previous->pNext = current->pNext;
            }
            
			printf("Removed %s\n", current->name);
            free(current->name);
            free(current);
            return;
        }
        
        previous = current;
        current = current->pNext;
    }
    
    fprintf(stderr, "Weather station with name '%s' not found!\n", name);
}

/**
 * Description: Inserts node into linked list as the new head of the list.
 * 
 * Parameters:  list **pHead - pointer to pointer of the head of the list.
 * 				struct node *pNode - pointer to node
 * 
 * Return:      Void
 */
void InsertNode(list **ppHead, struct node *pNode)
{
	if (pNode != NULL)
	{
		pNode->pNext = *ppHead;
		*ppHead = pNode;
	}
	else
	{
		fprintf(stderr, "pNode is NULL in InsertNode!\n");
	}
}

/**
 * Description: Creates a node which can in turn be added to the list of nodes.
 * 
 * Parameters:  char *name - pointer to name of node.
 * 
 * Return:      pointer to created node.
 */
struct node *CreateNode(char *name)
{
	static int ID = 0;
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode == NULL)
	{
		puts("Error allocating memory to new node!");
		return NULL;
	}
	
	newNode->id = ID;
	ID++;
	
	newNode->name = strdup(name);
	if (newNode->name == NULL)
	{
		puts("strdup failed in CreateNode!");
	}
    
	newNode->pNext = NULL;
	
	return newNode;
};

/**
 * Description: Empties a hardcoded file 
 * 
 * Parameters:  none
 * 
 * Return:      pointer to created node.
 */
void EmptyFile()
{
	FILE* fp = fopen(LINKED_LIST_FILE, "w");
    if (fp == NULL) 
	{
        fprintf(stderr, "Error opening file in EmptyFile\n");
        return;
    }

    fclose(fp);
}

/**
 * Description: Writes contents of linked list into file.
 * Uses PrintNodeFile(), which is actually not strictly  necessary.
 * 
 * Parameters:  list *pHead - pointer to the head of the list.
 * 
 * Return:      Void
 */
void PrintListToFile(list *pHead)
{
    list *pTemp;
	FILE *fp = fopen(LINKED_LIST_FILE, "w");

	if (fp == NULL)
	{
		fprintf(stderr, "Error with file pointer in PrintListToFile!\n");
		return;
	}
	
    
    if (pHead)
        for (pTemp = pHead; pTemp; pTemp = pTemp->pNext)
            PrintNodeFile(fp, pTemp);

	fclose(fp);
}

/**
 * Description: Writes specific node name into file. If node is NULL,
 * which it should never be in this function, it will display an error
 * message.
 * 
 * Parameters:  FILE *fp - File pointer
 * 				list *pNode - pointer to node
 * 
 * Return:      Void
 */
void PrintNodeFile(FILE *fp, list *pNode)
{
	// pNode should never be NULL here but just in case
	if (pNode == NULL)
	{
		fprintf(stderr, "Node passed to PrintNode is NULL!\n");
	}
	else
	{
		fprintf(fp, "%s\n", pNode->name);
	}
}

/**
 * Description: Displays contents of linked list. Uses PrintNode to
 * display contents of specific node.
 * 
 * Parameters:  list *pHead - pointer to head of list.
 * 
 * Return:      Void
 */
void PrintList(list *pHead)
{
    list *pTemp;
    
    if (pHead)
        for (pTemp = pHead; pTemp; pTemp = pTemp->pNext)
            PrintNode(pTemp);
    else
        fprintf(stderr, "No weather stations in user preferences!\n");
}

/**
 * Description: Displays specific node contents. Displays error message
 * if node is NULL.
 * 
 * Parameters:  list *pNode - pointer to node
 * 
 * Return:      Void
 */
void PrintNode(list *pNode)
{
	if (pNode == NULL)
	{
		fprintf(stderr, "Node passed to PrintNode is NULL!\n");
	}
	else
	{
		printf("ID: %d\nName: %s\npNext: %p\n", pNode->id, pNode->name, pNode->pNext);
	}
}

