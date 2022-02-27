#include <stdio.h>
#include <stdlib.h>
#include "Table2.h"
#include "DLLTable.h"
#include "Person.h"
void TBLInit(Table * pt, HashFunc * f)
{
	int i;

	for(i=0; i<MAX_TBL; i++)
		TListInit(&(pt->tbl[i]));

	pt->hf = f;
}

void TBLInsert(Table * pt, Key k, Value v)
{
	int hv = pt->hf(k);
	Slot ns = {k, v};
	
	if(TBLSearch(pt, k) != NULL)       // 키가 중복되었다면
	{
		printf("키 중복 오류 발생 \n");
		return;
	}
	else
	{
		TLInsert(&(pt->tbl[hv]), ns);
	}
}

Value TBLDelete(Table * pt, Key k)
{
	int hv = pt->hf(k);
	Slot cSlot;

	if(TLFirst(&(pt->tbl[hv]), &cSlot))
	{
		if(cSlot.key == k)
		{
			TLRemove(&(pt->tbl[hv]));
			return cSlot.val;
		}
		else
		{
			while(TLNext(&(pt->tbl[hv]), &cSlot))
			{
				if(cSlot.key == k)
				{
					TLRemove(&(pt->tbl[hv]));
					return cSlot.val;
				}
			}
		}
	}

	return NULL;
}

Value TBLSearch(Table * pt, Key k)
{
	int hv = pt->hf(k);
	Slot cSlot;

	if(TLFirst(&(pt->tbl[hv]), &cSlot))
	{
		if(cSlot.key == k)
		{
			return cSlot.val;
		}
		else
		{
			while(TLNext(&(pt->tbl[hv]), &cSlot))
			{
				if(cSlot.key == k)
					return cSlot.val;
			}
		}
	}

	return NULL;
}
void TBLPrint(Table * pt){
	int i;
	Slot cSlot;
	for(i=0;i<100;i++){
		int hv = pt->hf(i);
		if(TLFirst(&(pt->tbl[hv]),&cSlot)){
			ShowPerInfo(cSlot.val);
			while(TLNext(&(pt->tbl[hv]), &cSlot))
			{
				ShowPerInfo(cSlot.val);
			}
		}
	}
}