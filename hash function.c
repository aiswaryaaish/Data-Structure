#include<stdio.h>
#define MAX 10
void insert(int hash[]){
    int data,key,i;
    printf("enter element\n");
    scanf("%d",&data);
    key=data%10;
    if(hash[key]==-1){
        hash[key]=data;
    }
    else{
        for(i=1;i<MAX-key;i++){
            int j=key+i;
            if(hash[j]==-1){
                hash[j]=data;
                break;
            }
        }
    }
}
void search(int hash[]){
    int val,i,flag=0;
    printf("enter data to be searched\n");
    scanf("%d",&val);
    int k=val%10;
    if(hash[k]==val){
        printf("found at %d\n",k);
        flag++;
    }
    else{
        for(i=1;i<MAX-k;i++){
            if(hash[i]==val){
                printf("found at %d",i);
                flag++;
                break;
            }
           
            }
            if(flag==0){
                printf("not found\n");
            }
        }
    }
    

void display(int hash[]){
    int i;
    for(i=0;i<MAX;i++){
        printf("hash[%d] =%d\n ",i,hash[i]);
    }
}
int main(){
    int i,ch;
    //printf("enter table size\n");
   // scanf("%d",&);
    int hash[MAX];
    for(i=0;i<MAX;i++){
        hash[i]=-1;
    }
    while(1){
        printf("\nselect one\n1:insert\n2:display\n3:search\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:insert(hash);
                   break;
            case 2:display(hash);
                   break;
            case 3:search(hash);       
        }
    }
    
    
}