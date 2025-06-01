#define MAX 100
#include<stdio.h>
#include<string.h>
void push(char[],int*,char);
char pop(char[],int*);
int precedence(char);
int main()
{
    char iexp[MAX],pexp[MAX],e[MAX];
    int i=0,j=0,top=-1;
    printf("Enter an infix expression:");
    gets(iexp);
    iexp[strlen(iexp)]=')';
    iexp[strlen(iexp)+1]='\0';
    push(e,&top,'(');
    while(iexp[i]!='\0')
    {
        if((iexp[i]>='a'&&iexp[i]<='z')||(iexp[i]>='A'&&iexp[i]<='Z'))
        pexp[j++]=iexp[i];
        else if(iexp[i]=='(')
        push(e,&top,iexp[i]);
        else if(iexp[i]==')')
        {
            while(e[top]!='(')
            pexp[j++]=pop(e,&top);
            pop(e,&top);
        }
        else if(precedence(iexp[i])>precedence(e[top]))
        push(e,&top,iexp[i]);
        else if(precedence(iexp[i])<=precedence(e[top]))
        {
            while(top!=-1&&precedence(iexp[i])<=precedence(e[top]))
            pexp[j++]=pop(e,&top);
            push(e,&top,iexp[i]);
        }
        i++;
    }
    pexp[j]='\0';
    for(j=0;pexp[j]!='\0';j++)
    printf("%c",pexp[j]);
}
void push(char e[],int *top,char o)
{
    (*top)++;
    e[(*top)]=o;
}
char pop(char e[],int *top)
{
    char x;
    x=e[(*top)--];
    return x;
}
int precedence(char o)
{
        if(o=='^')
        return 3;
        if(o=='*'||o=='/')
        return 2;
        if(o=='+'||o=='-')
        return 1;
        return 0;
}