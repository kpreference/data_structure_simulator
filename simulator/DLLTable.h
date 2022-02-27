#ifndef __DLL_TABLE_
#define __DLL_TABLE_

#include "Slot2.h"

#define TRUE	1
#define FALSE	0

typedef Slot LTData;

typedef struct _nodeT
{
	LTData data;
	struct _nodeT * next;
} NodeT;

typedef struct _linkedListT
{
	NodeT * head;
	NodeT * cur;
	NodeT * before;
	int numOfData;
	int (*comp)(LTData d1, LTData d2);
} LinkedListT;


typedef LinkedListT ListT;

void TListInit(ListT * plist);
void TLInsert(ListT * plist, LTData data);

int TLFirst(ListT * plist, LTData * pdata);
int TLNext(ListT * plist, LTData * pdata);

LTData TLRemove(ListT * plist);
int TLCount(ListT * plist);

void TSetSortRule(ListT * plist, int (*comp)(LTData d1, LTData d2));

#endif