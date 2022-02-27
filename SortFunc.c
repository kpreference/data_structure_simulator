#include<stdlib.h>
#include"SortFunc.h"
#include"ListBaseQueue.h"
#include"UsefulHeap.h"
void BubbleSort(int arr[],int n){
    int i,j;
    int temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<(n-i)-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void InserSort(int arr[],int n){
    int i,j;
    int insData;
    for(i=1;i<n;i++){
        insData=arr[i];
        for(j=i-1;j>=0;j--){
            if(arr[j]>insData)
                arr[j+1]=arr[j];
            else 
                break;
        }
        arr[j+1]=insData;
    }
}
void MergeTwoArea(int arr[],int left, int mid, int right){
    int fIdx = left;
    int rIdx = mid+1;
    int i;
    int * sortArr=(int*)malloc(sizeof(int)*(right+1));
    int sIdx=left;

    while(fIdx<=mid && rIdx<=right){
        if(arr[fIdx]<=arr[rIdx])
            sortArr[sIdx]=arr[fIdx++];
        else
            sortArr[sIdx]=arr[rIdx++];
        sIdx++;
    }
    if(fIdx>mid){
        for(i=rIdx;i<=right;i++,sIdx++)
            sortArr[sIdx]=arr[i];

    }else{
        for(i=fIdx;i<=mid;i++,sIdx++)
            sortArr[sIdx]=arr[i];
    }
    for(i=left;i<=right;i++)
        arr[i]=sortArr[i];
    free(sortArr);
}
void MergeSort(int arr[], int left, int right){
    int mid;
    if(left<right){
        mid=(left+right)/2;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);
        MergeTwoArea(arr,left,mid,right);
    }
}

void Swap(int arr[], int idx1, int idx2){
    int temp=arr[idx1];
    arr[idx1]=arr[idx2];
    arr[idx2]=temp;
}
int Partition(int arr[],int left, int right){
    int pivot = arr[left]; 
    int low = left+1;
    int high = right;

    while(low<=high){

        while(pivot >= arr[low]&&low<=right){
            low++;
        }
        
        while(pivot <= arr[high]&&high>=(left+1)){
            high--;
        }
        
        if(low<=high){
            Swap(arr,low,high);
        }
    }
    Swap(arr,left,high); 
    return high;  
}
void QuickSort(int arr[],int left,int right){
    if(left <= right){
        int pivot =Partition(arr,left,right); //둘로 나눠서
        QuickSort(arr,left,pivot-1);  //왼쪽 영역을 정렬
        QuickSort(arr,pivot+1,right); //오른쪽 영역 정렬
    }
}
void SelSort(int arr[],int n){
    int i,j;
    int maxIdx;
    int temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[maxIdx]){
                maxIdx=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[maxIdx];
        arr[maxIdx]=temp;
    }
}

void RadixSort(int arr[], int num, int maxLen){
    //매개변수 maxlen에는 정렬대상 중 가장 긴데이터의 길이 정보가 전달
    Queue buckets[BUCKET_NUM];
    int bi;
    int pos;
    int di;
    int divfac=1;
    int radix;
    //총 10개의 버킷 초기화
    for(bi=0;bi<BUCKET_NUM;bi++){
        QueueInit(&buckets[bi]);
    }
    //가장 긴데이터의 길이만큼 반복
    for(pos=0;pos<maxLen;pos++){
        //정렬대상의 수만큼 반복
        for(di=0;di<num;di++){
            //n번째 자리의 숫자 추출
            radix=(arr[di]/divfac)%10;
            //추출한 숫자를 근거로 버킷에 데이터 저장
            Enqueue(&buckets[radix],arr[di]);
        }
        //버킷 수만큼 반복
        for(bi=0,di=0;bi<BUCKET_NUM;bi++){
            //버킷에 저장된 것 순서대로 다 꺼내어 다시 arr에 저장
            while(!QIsEmpty(&buckets[bi]))
                arr[di++]=Dequeue(&buckets[bi]);
        }
        //n번째 자리의 숫자 추출을 위한 피제수의 증가
        divfac*=10;
    }

}

void HeapSort(int arr[],int n, PriorityComp pc){
    Heap heap;
    int i;
    
    HeapInit(&heap,pc);
    
    for(i=0;i<n;i++){
        
        HInsert(&heap,arr[i]);   
        
    }
    
    
    for(i=0;i<n;i++){
        arr[i]=HDelete(&heap);
    }
}