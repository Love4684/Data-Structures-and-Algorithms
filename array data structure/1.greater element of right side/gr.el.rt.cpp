/*given an array replace every element by greater element on right side*/
#include <iostream>
using namespace std;
int main(){
int n=6,i,temp;    
int a[6]={16,17,4,3,5,2};
int max;
max= a[n-1];
a[n-1]=-1;
for(i=n-2;i>=0;i--){
    temp=a[i];
    if(max>a[i+1])
        a[i]=max;
    else
        a[i]=a[i+1];
    max=temp;   
    }
 for(i=0;i<n;i++){
     cout<<a[i]<<" ";
 } 
}