#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE   1
#define FALSE  0

typedef int Data;

typedef struct _queuenode{
    Data data;
    struct _queuenode * next;
} Node2;
typedef struct _lQueue{
    Node2 * front;
    Node2 * rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif