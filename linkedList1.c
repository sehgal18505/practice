#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
}node;

node* create(int);
node* reverse(node*);

void main()
{
    node *head=NULL, *temp;
    int choice,data;
    do
    {
        printf("Enter data:");
        scanf("%d",&data);
        if(!head)
        head=temp=create(data);
        else
        {
            temp->next=create(data);
            temp=temp->next;
        }
        printf("Do you wish to add more?(1/0)");
        scanf("%d",&choice);
    } while (choice);
    temp=head;
    while(temp)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("\\0\n");
    head=reverse(head);
    temp=head;
    while(temp)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("\\0");
}

node* create(int data)
{
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

node* reverse(node *head)
{
    node *first=head,*second=head,*third=NULL;
    while(first)
    {
        first=first->next;
        second->next=third;
        third=second;
        second=first;
    }
    head=third;
    return head;
}