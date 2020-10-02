#include<stdio.h>
#include <limits.h>
int main(){
int n=6,i,temp;    
int a[6]={16,17,4,3,5,2};
int min;
min= a[0];
a[0]=INT_MAX;
for(i=1;i<n;i++){
    temp=a[i];
    if(min>a[i-1])
        a[i]=a[i-1];
    else
        a[i]=min;
    if(temp<min)
    min=temp;
        
    }
 for(i=0;i<n;i++){
     printf("%d ",a[i]);
 }   

}