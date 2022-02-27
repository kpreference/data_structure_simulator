#ifndef __Sort_Func__
#define __Sort_Func__
#include"ListBaseQueue.h"
#include"UsefulHeap.h"

#define BUCKET_NUM 10

void BubbleSort(int arr[],int n);
void InserSort(int arr[],int n);
void MergeTwoArea(int arr[],int left, int mid, int right);
void MergeSort(int arr[], int left, int right);
void Swap(int arr[], int idx1, int idx2);
int Partition(int arr[],int left, int right);
void QuickSort(int arr[],int left,int right);
void SelSort(int arr[],int n);
void RadixSort(int arr[], int num, int maxLen);
int PriComp(int n1, int n2);
void HeapSort(int arr[],int n, PriorityComp pc);
#endif