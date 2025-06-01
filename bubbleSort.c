#include<stdio.h>
#define MAX 100

void bubbleSort(int[],int);
void swap(int[],int,int);

void main()
{
    int arr[MAX],i,n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter the array:");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    bubbleSort(arr,n);
    printf("Sorted array:");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
}

void bubbleSort(int arr[],int size)
{
    int i,j;
    for(i=size-1;i>=0;i--)
    {
        for(j=0;j<size;j++)
        {
            if(arr[j]>arr[j+1])
            swap(arr,j,(j+1));
        }
    }
}

void swap(int arr[],int current, int next)
{
    int temp=arr[current];
    arr[current]=arr[next];
    arr[next]=temp;
}