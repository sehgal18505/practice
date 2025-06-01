#include<Stdio.h>
void toh(int n,char f,char a,char t)
{
    if(n==1)
    {
        printf("Move disk from %c to %c using %c\n",f,t,a);
        return;
    }
    toh(n-1, f, t, a);
    printf("Move disk from %c to %c using %c\n",f,t,a);
    toh(n-1, a, f, t);
}
int main()
{
    int n;
    printf("Enter number of disks:");
    scanf("%d",&n);
    toh(n,'A','B','C');
}