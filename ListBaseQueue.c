#include<stdio.h>
#include<stdlib.h>
#include"ListBaseQueue.h"

void QueueInit(Queue * pq){
    pq->front=NULL;
    pq->rear=NULL;
}
int QIsEmpty(Queue * pq){
	if(pq->front==NULL)  //F�� NULL�� ����Ǿ� ������
		return TRUE;     //ť�� �� �� ���̴� TRUE�� ��ȯ�Ѵ�. 
	else
		return FALSE;
}
void Enqueue(Queue * pq, Data data){
    Node2 * newNode = (Node2*)malloc(sizeof(Node2));
    newNode->next = NULL;
    newNode->data = data;

    if(QIsEmpty(pq)){
        pq->front = newNode;
        pq->rear = newNode;
    }else{
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}
Data Dequeue(Queue * pq){
    Node2 * delNode;
    Data retData;

    if(QIsEmpty(pq)){
        printf("queue memory error");
        exit(-1);
    }
    delNode=pq->front;
    retData=delNode->data;
    pq->front=pq->front->next;

    free(delNode);
    return retData;
}
Data QPeek(Queue * pq){
    if(QIsEmpty(pq)){
        printf("queue memory error");
        exit(-1);
    }
    return pq->front->data;
}