#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table2.h"
#include <windows.h>
#include "DLLTable.h" //DLINKEDLIST
#include "SortFunc.h"
#include "BinaryTree3.h"
#include "DlinkedList.h"
#include "ListBaseStack.h"
#include "ListBaseQueue.h" 
#include "PriorityQueue.h"
#include "BinarySearchTree3.h"
void rando(int arr[]){
    int c;
    Sleep(2000);
        srand(time(NULL));
    for(c=0;c<10000;c++){
        arr[c]=rand()%10000+1;
    }
}
int PriComp(int n1, int n2){
    return n1-n2; //내림차순 정렬
    //return n2-n1;
}
int DataPriorityComp(int ch1, int ch2)
{
	return ch2-ch1;
}
int MyHashFunc(int k)
{
	return k % 100;
}
int main(){
    int n,m,a;
    int i;
    

    while(1){
        system("cls");
        printf("Select Menu\n1. Linked List\n2. Stack\n3. Queue\n4. Priority Queue\n5. Sorting\n6. Binary Search Tree(AVL)\n7. Hash Table\n0. Quit\n");
        printf("Select Number : ");
        scanf("%d",&n);
        system("cls");
        if(n==0){
            break;
        }else if(n==1){
            List list;
            int data;
            ListInit(&list);
            while(1){
                printf("Linked List\n");
                printf("1. Insert Number\n2. Delete Number\n3. Count Data\n4. Show Data\n0. Quit\nSelect Number : ");
                scanf("%d",&m);
                if(m==0){
                    break;
                }else if(m==1){
                    printf("Number : ");
                    scanf("%d",&a);
                    LInsert(&list,a);
                }else if(m==2){
                    printf("Number : ");
                    scanf("%d",&a);
                    if(LFirst(&list,&data)){
                        if(data==a){
                            LRemove(&list);
                        }
                        while(LNext(&list,&data)){
                            if(data==a){
                                LRemove(&list);
                            }
                        }
                    }
                }else if(m==3){
                    printf("현재 저장된 데이터의 수 : %d\n",LCount(&list));
                }else if(m==4){
                    if(LFirst(&list,&data)){
                        printf("%d ",data);
                        while(LNext(&list,&data)){
                            printf("%d ",data);
                        }
                    }
                }
                printf("\n");
            }
        }else if(n==2){
            printf("Stack\n");
            Stack stack;
            StackInit(&stack);

            while(1){
                
                printf("1. Push\n2. Pop\n3. Peek\n0. Back to Main Menu\nSelect Number : ");
                scanf("%d",&m);
                if(m==0){
                    break;
                }else if(m==1){
                    printf("Push Number : ");
                    scanf("%d",&a);
                    SPush(&stack,a);
                }else if(m==2){
                    if(!SIsEmpty(&stack)){
                        printf("%d",SPop(&stack));
                    }else{
                        printf("Stack Empty!");
                    }
                }else if(m==3){
                    if(!SIsEmpty(&stack)){
                        printf("%d",SPeek(&stack));
                    }else{
                        printf("Empty Stack!");
                    }
                }
                printf("\n");
            }
        }else if(n==3){
            Queue q;
            QueueInit(&q);
            printf("Queue\n");
            while(1){
                printf("1. Enqueue\n2. Dequeue\n3. Peek\n0. Back to Main Menu\nSelect Number : ");
                scanf("%d",&m);
                if(m==1){
                    printf("Insert Number : ");
                    scanf("%d",&a);
                    Enqueue(&q,a);
                }else if(m==2){
                    if(!QIsEmpty(&q)){
                        printf("Dequeue Number : %d",Dequeue(&q));
                    }else{
                        printf("Empty Queue");
                    }
                }else if(m==3){
                    printf("Peek : %d",QPeek(&q));
                }
                    
                printf("\n");
            }
        }else if(n==4){
            int nn;
            printf("Priority Queue\n");
            Heap heap;
            HeapInit(&heap, DataPriorityComp);//1234567890
            while(1){
                printf("1. Insert Number\n2. Delete number\n3. Delete all number\n0. Back to Main Menu\nSelect Number : ");
                scanf("%d",&m);
                if(m==0){
                    break;
                }
                else if (m==1){
                    printf("Insert Number : ");
                    scanf("%d",&nn);
                    HInsert(&heap,nn);
                }else if(m==2){
                    if(HIsEmpty(&heap)==1){
                        printf("empty");
                    }else{
                        printf("%d \n",HDelete(&heap));    
                    }
                }else if(m==3){
                    if(HIsEmpty(&heap)==1){
                        printf("empty");
                    }else{
                        while(!HIsEmpty(&heap))
                            printf("%d \n",HDelete(&heap));   
                    }
                }
                printf("\n");
            }
        }else if(n==5){
            printf("Sorting\n");
            clock_t start, finish;
            double duration;
            int arr[10000];
            srand(time(NULL));
            
            printf("How many times do you want? : ");
            scanf("%d",&m);
            for(i=0;i<m;i++){
                printf("Case #%d\n",i+1);
                rando(arr);
                start = clock();
                
                BubbleSort(arr,sizeof(arr)/sizeof(int));

                finish = clock();
                duration = (double)(finish - start) / CLOCKS_PER_SEC;
                printf("Bubble sort : %f\n", duration);
                
                rando(arr);
                start = clock();

                InserSort(arr,sizeof(arr)/sizeof(int));

                finish = clock();
                duration = (double)(finish - start) / CLOCKS_PER_SEC;
                printf("Insert sort : %f\n",duration);

                rando(arr);
                start = clock();

                MergeSort(arr,0,sizeof(arr)/sizeof(int)-1);
                
                finish = clock();

                duration = (double)(finish - start) / CLOCKS_PER_SEC;
                printf("Merge sort : %f\n",duration);

                rando(arr);
                start = clock();

                QuickSort(arr,0,sizeof(arr)/sizeof(int)-1);
                
                finish = clock();

                duration = (double)(finish - start) / CLOCKS_PER_SEC;
                printf("Quick sort : %f\n",duration);

                rando(arr);
                start = clock();

                SelSort(arr,sizeof(arr)/sizeof(int));
                
                finish = clock();

                duration = (double)(finish - start) / CLOCKS_PER_SEC;
                printf("Select sort : %f\n",duration);

                rando(arr);
                int len=sizeof(arr)/sizeof(int);
                start = clock();

                RadixSort(arr,len,4);
                
                finish = clock();

                duration = (double)(finish - start) / CLOCKS_PER_SEC;
                printf("Radix sort : %f\n",duration);

                rando(arr);
                
                start = clock();

                HeapSort(arr,sizeof(arr)/sizeof(int),PriComp);
                
                finish = clock();

                duration = (double)(finish - start) / CLOCKS_PER_SEC;
                printf("Heap sort : %f\n",duration);

                printf("\n");
            }
        }else if(n==6){
            printf("Binary Search Tree(AVL)\n");
            BTreeNode * avlRoot;
            BTreeNode * clNode;		// current left node
            BTreeNode * crNode;		// current right node
            BTreeNode * sNode;
            BSTMakeAndInit(&avlRoot);
            while(1){
                printf("1. Insert Number\n2. Delete Number\n3. Show All Nodes\n0. Quit");
                printf("\nSelect Number : ");
                int temp;
                scanf("%d",&m);
                if(m==0){
                    break;
                }else if(m==1){
                    printf("Insert Number : ");
                    scanf("%d",&temp);
                    BSTInsert(&avlRoot, temp);
                }else if(m==2){
                    printf("Delete Number : ");
                    scanf("%d",&temp);
                    if(BSTSearch(avlRoot,temp)==NULL){
                        printf("A node doesn't exist.\n");
                    }else{
                        sNode = BSTRemove(&avlRoot, temp);
                        free(sNode);
                    }
                }else if(m==3){
                    BSTShowAll(avlRoot);
                }
                printf("\n");
                printf("root node : %d",GetData(avlRoot));
                printf("\n");
            }
        }else if(n==7){
            printf("Hash Table\n");
            Table tbl;
            Person * temp;
            Person * sp;
            Person * rp;
            TBLInit(&tbl,MyHashFunc);
            while(1){
                int nn,tempssn;
                char tempname[50];
                char tempaddr[50];
            
                printf("1. Insert information\n2. Show information\n3. Delete information\n4. Show all data\n0. quit\n");
                printf("select number : ");
                scanf("%d",&m);
                
                
                if(m==0){
                    break;
                }else if (m==1){
                    printf("ssn name addr : ");
                    scanf("%d %s %s",&tempssn,tempname,tempaddr);
                    temp=MakePersonData(tempssn,tempname,tempaddr);
                    TBLInsert(&tbl,GetSSN(temp),temp);
                }else if(m==2){
                    printf("insert ssn : ");
                    scanf("%d",&nn);
                    sp=TBLSearch(&tbl,nn);
                    if(sp!=NULL)
                        ShowPerInfo(sp);
                    else
                        printf("doesn't exist\n");
                }else if(m==3){
                    printf("insert ssn : ");
                    scanf("%d",&nn);
                    rp = TBLDelete(&tbl, nn);
                    if(rp != NULL)
                        free(rp);
                    else
                        printf("doesn't exist\n");
                }else if(m==4){
                    TBLPrint(&tbl);
                }
            }
        }
    }
}