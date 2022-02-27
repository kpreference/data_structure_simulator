#include<stdio.h>
#include<stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack){
    pstack->head=NULL;        //head는 새로 추가된 노드를 가리켜야함. null로 초기화.
}
int SIsEmpty(Stack * pstack){
    if(pstack->head==NULL){
        return TRUE;        //스택이 빈 경우 head는 null이므로 TRUE를 반환.
    }else{
        return FALSE;       
    }
}
void SPush(Stack *pstack, Data data){  //리스트의 머리에 새 노드를 추가하는 함수
    Node1 * newNode = (Node1*)malloc(sizeof(Node1));     //새 노드 생성
    newNode->data=data;          //새 노드에 데이터 저장
    newNode->next=pstack->head;  //새 노드가 최근에 추가된 노드를 가리킴

    pstack->head=newNode;        //포인터 변수 head가 새 노드르 가리킴
}

Data SPop(Stack * pstack){
    Data rdata;
    Node1 * rnode;
    if(SIsEmpty(pstack)){
        printf("stack memory error!");
        exit(-1);
    }
    rdata=pstack->head->data;         //삭제할 노드의 데이터를 임시로 저장
    rnode=pstack->head;               //삭제할 노드의 주소 값을 임시로 저장

    pstack->head=pstack->head->next;  //삭제할 노드의 다음 노드를 head가 가리킴
    free(rnode);       //노드 삭제
    return rdata;      //삭제된 노드 데이터 반환
}
Data SPeek(Stack * pstack){
    if(SIsEmpty(pstack)){
        printf("stack memory error!");
        exit(-1);
    }
     return pstack->head->data;  //head가 가리키는 노드에 저장된 데이터 반환
}