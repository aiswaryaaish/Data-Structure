#include<stdio.h>
#include<stdlib.h>
int source,v,e,visited[20],g[20][20],q[20],front=-1,rear=-1;
void enqueue(int item){
    if(front==-1 && rear==-1){
        front=rear=0;
        q[rear]=item;
    }
    else{
        rear++;
        q[rear]=item;
    }
}
int dequeue(){
    if(front==-1 && rear==-1){
        return -1;
    }
    else if(front==rear){
        return q[front];
        front=rear=-1;
    }
    else{
        return q[front++];
    }
}
void DFS(int i){
    int j;
    visited[i]=1;
    printf("%d",i);
    for(j=1;j<=v;j++){
        if(g[i][j]==1 && visited[j]==0){
            DFS(j);
        }
    }
}


void BFS(int s){
    int i;
    visited[s]=1;
    printf("%d\t",s);
    enqueue(s);
    while(front!=-1){
        s=dequeue();
        for(i=1;i<=v;i++){
            if(g[s][i]==1 &&visited[i]==0){
                printf("%d\t",i);
                visited[i]=1;
                enqueue(i);
            }
        }
    }
}


void main(){
    int i,j,v1,v2,ch;
    printf("enter the number of vertices\n");
    scanf("%d",&v);
    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++){
            g[i][j]=0;
        }
    }
    printf("enter no.of edges\n");
    scanf("%d",&e);
    for(i=1;i<=e;i++){
        printf("enter the edges(format v1 v2):");
        scanf("%d%d",&v1,&v2);
        g[v1][v2]=1;
        g[v2][v1]=1;
    }
    printf("the adjacency matrix is\n");
    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++){
            printf("%d\t",g[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=v;i++){
        visited[i]=0;
    }
    printf("enter the source\n");
    scanf("%d",&source);
    
    printf("\nDFS is:\n");
    DFS(source);
    
    for(i=1;i<=v;i++){
        visited[i]=0;
    }
    
    printf("\nBFS is :\n");
    BFS(source);
    
}