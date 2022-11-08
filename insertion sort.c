#include<stdio.h>
int main(){
    int a[10],i,j,key,n;
    printf("enter size\n");
    scanf("%d",&n);
    printf("enter the values\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        j=i-1;
        key=a[i];
        while(j>=0&&key<a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    printf("sorted list is:\n");
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
    return 0;
}