#include<stdio.h>
#define MAX 100
void mergeSort(int[],int,int);
void merge(int[],int,int,int);
void main()
{
    int arr[MAX],n,i;
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter elements of the array:");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    mergeSort(arr,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
void mergeSort(int arr[],int lb,int ub)
{
    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}
void merge(int arr[],int lb,int mid,int ub)
{
    int i=lb,j=mid+1,k=lb,b[ub+1];
    while(i<=mid&&j<=ub)
    {
        if(arr[i]<=arr[j])
            b[k++]=arr[i++];
        else
            b[k++]=arr[j++];
    }
    if(i>mid)
    {
        while(j<=ub)
            b[k++]=arr[j++];
    }
    else
        while(i<=mid)
            b[k++]=arr[i++];
    for(i=lb;i<=ub;i++)
        arr[i]=b[i];
}