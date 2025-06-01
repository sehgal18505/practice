#include<stdio.h>
#define MAX 100

void insertionSort(int[],int);
void swap(int,int);

void main()
{
    int i,arr[MAX],n;
    printf("Enter size of the array:");
    scanf("%d",&n);
    printf("Enter the array:");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    insertionSort(arr,n);
    printf("Sorted array:");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
}

void insertionSort(int arr[],int size)
{
    int i,j,temp;
    for(i=1;i<size;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}