#include <stdio.h>
#include <stdlib.h>
typedef struct bst 
{
    struct bstNode *left;
    int data;
    struct bstNode *right;
}Node;
void insert(Node** root, int data) 
{
    Node* currentNode=*root;//will traverse the tree
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->left=NULL;
    newNode->data=data;
    newNode->right=NULL;
    if (!(*root)) 
    *root=newNode; 
    while (1) 
    { 
        if (data<currentNode->data) 
        {
            if (!currentNode->left)
            {
                currentNode->left=newNode; 
                break;
            } 
            else 
            currentNode=currentNode->left;
        } 
        else if (data>currentNode->data) 
        {
            if (!currentNode->right) 
            {
                currentNode->right=newNode;
                break;
            } 
            else 
            currentNode=currentNode->right; 
        } 
        else 
        {
            printf("Data already present\n");
            free(newNode);
            break;
        }
    }
}
Node* find(Node* root,int data)
{
    if(!root)
    return NULL;
    else if(root->data==data)
    return root;
    else if(data<root->data)
    return find(root->left,data);
    else if(data>root->data)
    return find(root->right,data); 
}
void countLeafNodes(Node** root,int *count)
{
    if(!(*root))
    return;
    countLeafNodes((*root)->left,&count);
    if(!((*root)->left)&&!((*root)->right))
    (*count)++;
    countLeafNodes((*root)->right,&count);

}
void printPrimeData(Node** root)
{
    if(!(*root))
    return;
    printPrimeData(&(*root)->left);
    if(isPrime((*root)->data))
    printf("%d ",(*root)->data);
    printPrimeData(&(*root)->right);
}
int isPrime(int v)
{
    int i;
    if(v==1)
    return 0;
    for(i=2;i<v;i++)
    {
        if(v%i==0)
        return 0;
    }
    return 1;
}
void display(Node* root)
{
    if(!(*root))
    return;
    display((*root)->left);
    printf("%d ",(*root)->data);
    display((*root)->right);
}
void deleteNode(Node** root,int data)
{
    Node* temp=NULL;
    if(!(*root))
    return;
    else if(data<(*root)->data)
    delete(&(*root)->left,data);
    else if(data>(*root)->data)
    delete(&(*roo)->right,data);
    else
    {
        if(!(*root)->left&&!(*root)->right)
        {
            temp=(*root);
            free(temp);
            (*root)=NULL
        }
        else if(!(*root)->left)
        {
            temp=(*root)
            (*root)=(*root)->right;
            free(temp);
        }
        else if(!(*root)->right)
        {
            temp=(*root)
            (*root)=(*root)->left;
            free(temp);
        }
        else
        {
            temp=inSuc(*root);
            (*root)->data=temp->data;
            delete(&(*root)->right,temp->data);
        }
    }
}
Node* inSuc(Node* n)
{
    n=n->right;
    while(n->left)
    n=n->left;
    return n;
}
int main()
{
    Node* root=NULL;
    int ch,data,count=0;
    do
    {
        printf("1.Insert\n2.Display\n3.Count Leaf Nodes\n4.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter data:");
            scanf("%d",&data);
            insert(&root,data);
            break;
            case 2:
            display(root);
            break;
            case 3:
            countLeafNodes(&root,&count);
            printf("%d",count);
            break;
            case 4:
            return 0;        
        }
    } while (ch<=3);
    

}