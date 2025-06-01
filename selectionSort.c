#include<stdio.h>
#define MAX 100
void swap(int[],int,int);
void selectionSort(int[],int);
void swap(int[],int,int);
void main()
{
    int arr[MAX],i,n;
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter elements of the array:");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    selectionSort(arr,n);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
void selectionSort(int arr[],int n)
{
    int min,i,j;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        if(min!=i)
            swap(arr,i,min);
    }
}
void swap(int arr[],int i,int min)
{
    int temp;
    temp=arr[i];
    arr[i]=arr[min];
    arr[min]=temp;
}