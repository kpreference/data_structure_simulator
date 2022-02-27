#ifndef __TABLE2_H__
#define __TABLE2_H__

#include "Slot2.h"
#include "DLLTable.h"

#define MAX_TBL     100

typedef int HashFunc(Key k);

typedef struct _table
{
//	Slot tbl[MAX_TBL];
	ListT tbl[MAX_TBL];
	HashFunc * hf;
} Table;

void TBLInit(Table * pt, HashFunc * f); 
void TBLInsert(Table * pt, Key k, Value v);
Value TBLDelete(Table * pt, Key k);
Value TBLSearch(Table * pt, Key k);
void TBLPrint(Table * pt);

#endif