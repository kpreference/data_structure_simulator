#include <stdio.h>
#include <stdlib.h>
#include "DLLTable.h"

void TListInit(ListT * plist)
{
	plist->head = (NodeT*)malloc(sizeof(NodeT));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void TFInsert(ListT * plist, LTData data)
{
	NodeT * newNode = (NodeT*)malloc(sizeof(NodeT));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

void TSInsert(ListT * plist, LTData data)
{
	NodeT * newNode = (NodeT*)malloc(sizeof(NodeT));
	NodeT * pred = plist->head;
	newNode->data = data;

	while(pred->next != NULL &&
		plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}


void TLInsert(ListT * plist, LTData data)
{
	if(plist->comp == NULL)
		TFInsert(plist, data);
	else
		TSInsert(plist, data);
}

int TLFirst(ListT * plist, LTData * pdata)
{
	if(plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int TLNext(ListT * plist, LTData * pdata)
{
	if(plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LTData TLRemove(ListT * plist)
{
	NodeT * rpos = plist->cur;
	LTData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int TLCount(ListT * plist)
{
	return plist->numOfData;
}

void TSetSortRule(ListT * plist, int (*comp)(LTData d1, LTData d2))
{
	plist->comp = comp;
}