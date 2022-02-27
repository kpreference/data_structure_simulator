#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE    1
#define FALSE   0

typedef int Data;

typedef struct _stacknode{
    Data data;
    struct _stacknode * next;
} Node1;

typedef struct _listStack{
    Node1 * head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);  
void SPush(Stack * pstack, Data data);  
Data SPop(Stack * pstack);   
Data SPeek(Stack * pstack);  

#endif