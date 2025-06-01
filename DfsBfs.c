#include<stdio.h>
#include<stdlib.h> 
typedef struct Node{
    int data;
    struct Node* next;
}node;
node* createNode(int n) {
    node*newNode=(node*)malloc(sizeof(node));
    newNode->data=n;
    newNode->next=NULL; 
    return newNode;
}
void addEdge (node* adj [], int s, int d){ 
    node* newNode=createNode(d);
    newNode->next=adj[s]; 
    adj [s]=newNode;
    newNode=createNode(s);
    newNode->next=adj [d]; 
    adj [d]=newNode;
}
void display(node* adj [], int nV) {
    for(int i=0;i<nV; i++){
        printf("%d:",i);
        node* temp=adj [i];
        while(temp!=NULL){
            printf("%d ", temp->data); 
            temp=temp->next;
        }
        printf("\n");   
    }
}
void dfs(node* adj [], int s,int nV){
    int visited [nV]={0},pop;
    visited [s]=1;
    int stack [nV];
    int top=-1;
    stack [++top]=s;
    while(top>-1){
        pop=stack[top--];
        printf("%d ", pop); 
        node* temp=adj [pop]; 
        while(temp!=NULL){
            if (visited [temp->data]==0){
                stack [++top]=temp->data; 
                visited [temp->data]=1;
            }
            temp=temp->next;
        }
    }
}
void bfs(node* adj[],int s,int nV){
    int visited[nV]={0},f,r,dq;
    visited[s]=1;
    int queue[nV];
    f=r=-1;
    queue[++r]=s;
    while(r!=f){
        dq=queue[++f];
        printf("%d ",dq);
        node* temp=adj[dq];
        while(temp){
            if(!visited[temp->data]){
                queue[++r]=temp->data;
                visited[temp->data]=1;
            }
            temp=temp->next;
        }
    }
}
void main(){
    int nV,nE,source,destination;
    node* adj [10];
    scanf("%d",&nV);
    scanf("%d",&nE);
    for(int i=0;i<nV;i++)
    adj [i]=NULL;
    for(int i=0;i<nE;i++){
        scanf("%d %d",&source,&destination);    
        addEdge (adj,source,destination);
    }
    display(adj,nV);
    dfs(adj,1,nV);
    printf("\n");
    bfs(adj,1,nV);
}