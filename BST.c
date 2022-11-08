#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*right;
    struct node*left;
};
struct node* insert(struct node* root,int ele){
    struct node* newnode=malloc(sizeof(struct node));
    //int ele=0;
    
    if(root==NULL){
   
    newnode->data=ele;
    newnode->right=NULL;
    newnode->left=NULL;
        return newnode;
    }
    
    if(ele<root->data){
    
        root->left=insert(root->left,ele);
        }
    if(ele>root->data){
            
    
        root->right=insert(root->right,ele);
        }
    
    return root;
}
void search(struct node*root,int key){
   
    
    if(root==NULL){
        printf("element not found\n");
    }
    else{
        if(key==root->data){
            printf("element found\n");
        }
        else if(key<root->data){
            search(root->left,key);
        }
        else{
            search(root->right,key);
        }
    }
}
void display(struct node*root){
    if(root!=NULL){
        display(root->left);
        printf("%d\t",root->data);
        display(root->right);
    }
}
int main(){
    struct node*root=NULL;
    int ch,ele,key;
    while(1){
        printf("enter choice\n1:insert\n2:search\n3:display\n4:exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("enter data\n");
                   scanf("%d",&ele);
                   root=insert(root,ele);
                   break;
            case 2:printf("enter key\n ");
                   scanf("%d",&key);
                   search(root,key);
                   break;
            case 3:display(root);
                   break;
           case 4:exit(0);
        }
    }
}
