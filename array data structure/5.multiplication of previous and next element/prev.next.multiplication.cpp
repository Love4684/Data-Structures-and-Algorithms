#include <iostream>
using namespace std;
void NewArray(int arr[] , int n)
{   
    if(n<=1)                         //if number of element less then two
    {
        return;            
    }
    
    int previous = arr[0];          //first element assigning with keeping the track of this element     
    arr[0] =previous*arr[1];
    
    for(int i=1; i<n-1; i++)
    {
        int current = arr[i];
        arr[i]  = previous*arr[i+1];
        previous = current;
    }
    
    arr[n-1] = previous*arr[n-1];
}

int main()
{int n,i;
    int arr[] = {2, 3, 4, 5, 6};
    n=sizeof(arr)/sizeof(arr[0]);
    NewArray(arr , n);
    for(i=0;i<n;i++)
    {
       cout << arr[i]  <<" "; 
    }
}
