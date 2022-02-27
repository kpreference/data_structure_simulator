#include<stdio.h>
#include<stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack){
    pstack->head=NULL;        //head�� ���� �߰��� ��带 �����Ѿ���. null�� �ʱ�ȭ.
}
int SIsEmpty(Stack * pstack){
    if(pstack->head==NULL){
        return TRUE;        //������ �� ��� head�� null�̹Ƿ� TRUE�� ��ȯ.
    }else{
        return FALSE;       
    }
}
void SPush(Stack *pstack, Data data){  //����Ʈ�� �Ӹ��� �� ��带 �߰��ϴ� �Լ�
    Node1 * newNode = (Node1*)malloc(sizeof(Node1));     //�� ��� ����
    newNode->data=data;          //�� ��忡 ������ ����
    newNode->next=pstack->head;  //�� ��尡 �ֱٿ� �߰��� ��带 ����Ŵ

    pstack->head=newNode;        //������ ���� head�� �� ��帣 ����Ŵ
}

Data SPop(Stack * pstack){
    Data rdata;
    Node1 * rnode;
    if(SIsEmpty(pstack)){
        printf("stack memory error!");
        exit(-1);
    }
    rdata=pstack->head->data;         //������ ����� �����͸� �ӽ÷� ����
    rnode=pstack->head;               //������ ����� �ּ� ���� �ӽ÷� ����

    pstack->head=pstack->head->next;  //������ ����� ���� ��带 head�� ����Ŵ
    free(rnode);       //��� ����
    return rdata;      //������ ��� ������ ��ȯ
}
Data SPeek(Stack * pstack){
    if(SIsEmpty(pstack)){
        printf("stack memory error!");
        exit(-1);
    }
     return pstack->head->data;  //head�� ����Ű�� ��忡 ����� ������ ��ȯ
}