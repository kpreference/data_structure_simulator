simulator_exe : main.o AVLRebalance.o BinarySearchTree3.o BinaryTree3.o DLinkedList.o DLLTable.o ListBaseQueue.o ListBaseStack.o Person.o PriorityQueue.o SortFunc.o Table2.o UsefulHeap.o
	gcc -o simulator_exe main.o AVLRebalance.o BinarySearchTree3.o BinaryTree3.o DLinkedList.o DLLTable.o ListBaseQueue.o ListBaseStack.o Person.o PriorityQueue.o SortFunc.o Table2.o UsefulHeap.o

main.o : main.c
	gcc -c -o main.o main.c

AVLRebalance.o : AVLRebalance.c
	gcc -c -o AVLRebalance.o AVLRebalance.c

BinarySearchTree3.o : BinarySearchTree3.c
	gcc -c -o BinarySearchTree3.o BinarySearchTree3.c
BinaryTree3.o : BinaryTree3.c
	gcc -c -o BinaryTree3.o BinaryTree3.c
DLinkedList.o : DLinkedList.c
	gcc -c -o DLinkedList.o DLinkedList.c
DLLTable.o : DLLTable.c
	gcc -c -o DLLTable.o DLLTable.c
ListBaseQueue.o : ListBaseQueue.c
	gcc -c -o ListBaseQueue.o ListBaseQueue.c
ListBaseStack.o : ListBaseStack.c
	gcc -c -o ListBaseStack.o ListBaseStack.c
Person.o : Person.c
	gcc -c -o Person.o Person.c
PriorityQueue.o : PriorityQueue.c
	gcc -c -o PriorityQueue.o PriorityQueue.c
SortFunc.o : SortFunc.c
	gcc -c -o SortFunc.o SortFunc.c
Table2.o : Table2.c
	gcc -c -o Table2.o Table2.c
UsefulHeap.o : UsefulHeap.c
	gcc -c -o UsefulHeap.o UsefulHeap.c

clean : 
	rm *.o simulator_exe