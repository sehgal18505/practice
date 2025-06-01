#include<stdio.h>
#define MAX 100

void quickSort(int[],int,int);
int partition(int[],int,int);
void swap(int[],int,int);

void main()
{
    int arr[MAX],i,n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter the array:");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    quickSort(arr,0,n-1);
    printf("Sorted array:");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
}

void quickSort(int arr[],int lb, int ub)
{
    int location;
    if(lb<ub)
    {
        location=partition(arr,lb,ub);
        quickSort(arr,lb,location-1);
        quickSort(arr,location+1,ub);
    }
}

int partition(int arr[],int lb, int ub)
{
    int start=lb, end=ub, pivot=arr[lb];
    while(start<end)
    {
        while(arr[start]<=pivot)
        start++;
        while(arr[end]>pivot)
        end--;
        if(start<end)
        swap(arr,start,end);
    }
    swap(arr,lb,end);
    return end;
}

void swap(int arr[],int a, int b)
{
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}