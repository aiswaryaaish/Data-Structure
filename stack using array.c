#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int stack[MAX];
int top=-1;
void push(){
    int ele;
    if(top==MAX){
        printf("stack overflow");
    }
    else{
        printf("enter the value");
        scanf("%d",&ele);
        top++;
        stack[top]=ele;
    }
}

void pop(){
    if(top==-1){
        printf("underflow");
    }
    else{
        printf("poped element is %d ",stack[top]);
        top--;
    }
}

void display(){
    if(top==-1){
        printf("underflow");
    }
    else{
        for(int i=top;i>=0;i--){
          printf("%d\t",stack[i]);  
        }
    }
}

int main(){
    int choice;
    int flag=1;
    while(flag){
        printf("select a choice\n1:push\n2:pop\n3:display\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:push();
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            default: printf("invalid");       
        }
        printf("do you want to continue\n(y=1/N=0) ");
    scanf("%d",&flag);
        
    }
    return 0;
    }