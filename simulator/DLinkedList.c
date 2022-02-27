#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist)  
{
	plist->head=(Node*)malloc(sizeof(Node)); //더미 노드 생성 
    plist->head->next=NULL;
    plist->comp=NULL;
    plist->numOfData=0;
}
void FInsert(List * plist, LData data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

void SInsert(List * plist, LData data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	Node * pred = plist->head;
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
void LInsert(List * plist, LData data)    //리스트의 멤버 comp에 무엇이 저장되어 있느냐에 따라 둘 중에 결정.
{
	if(plist->comp==NULL){    //정렬기준 없으면
        FInsert(plist,data);  //머리에 노드를 추가
    }else{                    //정렬기준 있으면
        SInsert(plist,data);  //정렬기준에 근거해 노드를 추가
    }
}  
int LFirst(List * plist, LData * pdata){   
    if(plist->head->next==NULL){       //더미 노드가 NULL을 가리키면, 반환할 데이터가 없다.
        return FALSE;
    }
    plist->before=plist->head;         //before은 더미 노드를 가리키게 함.
    plist->cur=plist->head->next;      //cur은 첫 번째 노드를 가리키게 함.
    *pdata=plist->cur->data;           //첫 번째 노드의 데이터를 전달.
    return TRUE;                       //반환 성공
}

int LNext(List * plist, LData * pdata) //LFirst > LNext 순서로 넘어온다. 
{
	if(plist->cur->next==NULL)         //더미 노드가 NULL을 가리킨다면 반환할 데이터가 없다.
		return FALSE;
    plist->before=plist->cur;          //cur이 가리키던 것을 before가 가리킴
    plist->cur=plist->cur->next;       //cur은 그 다음 노드를 기리킴
    *pdata=plist->cur->data;           //cur이 가리키는 노드의 데이터 전달.
    return TRUE;                       //반환 성공
}

LData LRemove(List * plist)                  //바로 이전에 호출된 LFirst , LNext 함수가 반환한 데이터를 삭제한다.
{                                            //중간에 있던 데이터 삭제 후, before를 사용해 이전 노드가 가리키는 노드 조정
    Node * rpos = plist->cur;                //소멸 대상의 주소 값을 rpos에 저장
    LData rdata = rpos->data;                //소멸 대상의 데이터를 rdata에 저장

    plist->before->next=plist->cur->next;    //소멸 대상을 리스트에서 제거
    plist->cur=plist->before;                //cur이 가리키는 위치를 재조정

    free(rpos);                              //리스트에서 제거된 노드 소멸
    (plist->numOfData)--;                    //저장된 데이터의 수 하나 감소
    return rdata;                            //제거된 노드의 데이터 반환
}

int LCount(List * plist)
{
	return plist->numOfData;
}
void SetSortRule(List * plist, int (*comp)(LData d1, LData d2)){
    printf("");
}