#include<stdio.h>
void merge(int lb,int ub,int mid, int a[]){
    int b[20],i=lb,j=mid+1,k=0;
    while(i<=mid && j<=ub){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            k++;
            j++;
        }
    }

        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
    
    
        while(j<=ub){
            b[k]=a[j];
            k++;
            j++;
        }
    
    for(k=0,i=lb;i<=ub;i++,k++){
        a[i]=b[k];    }
        
    
    }    
        

void mergesort(int lb,int ub,int a[]){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergesort(lb,mid,a);
        mergesort(mid+1,ub,a);
        merge(lb,ub,mid,a);
        
    }
}
void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
}
int main(){
    int n,a[20];
    printf("enter size of array\n");
    scanf("%d",&n);
    printf("enter values\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(0,n-1,a);
    printf("sorted list is\n");
    
    
    display(a,n);
    return 0;
}