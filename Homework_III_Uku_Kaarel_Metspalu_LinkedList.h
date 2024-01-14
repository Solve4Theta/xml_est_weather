/**
 * File:        ll_basecode.h
 * Author:      Uku Kaarel Metspalu
 * Created:     29.05.2023
 * Modified:    01.06.2023
 *
 * Description: Header for the linked list .c file
 */
#ifndef HOMEWORK_III_UKU_KAAREL_METSPALU_LINKED_LIST_H
#define HOMEWORK_III_UKU_KAAREL_METSPALU_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINKED_LIST_FILE "LinkedList.txt"

typedef struct node
{
    int id;
    char *name;
    struct node *pNext;
} list;

struct node *CheckForDoubleNode(list *pHead, char *name);
void PrintList(list *pHead);
void EmptyFile();
void PrintNodeFile(FILE *fp, list *pNode);
void PrintListToFile(list *pHead);
void RemoveNodeByName(list **ppHead, char *name);
void PrintNode(list *pNode);
struct node *CreateNode(char *name);
void InsertNode(list **pHead, struct node *pNode);  
void Unload(list *pHead);
struct node *FindNodeByName(list *pHead, char *name);
struct node *FindNodeByID(list *pHead, int id);
char * GetName(void);
int GetNodeId(void);

#endif //HOMEWORK_III_UKU_KAAREL_METSPALU_LINKED_LIST_H
