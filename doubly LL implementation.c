#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
}*front,*rear;

void enqueue(int data){
    struct node*newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(front==NULL){
        front=rear=newnode;
        return;
    }
    else{
        rear->next=newnode;
        newnode->prev=rear;
        rear=newnode;
    }
}
void dequeue(){
    struct node*temp;
    temp=front;
    if(front==NULL){
        printf("underflow\n");
        return;
    }
    else{
        front=front->next;
        free(temp);
    }
}
void display(){
    struct node*temp;
    temp=front;
    if(front==NULL){
        printf("underflow");
        return;
    }
    else{
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}

int main(){
    int data,choice;
    printf("1:enqueue\n2:dequeue\n3:display\n4:exit\n");
    while(1){
        printf("select a choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("enter data\n");
                   scanf("%d",&data);
                   enqueue(data);
                   break;
            case 2:dequeue();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);       
        }
    }
}