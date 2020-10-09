#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int maxWater(int arr[], int n)
{int i,j;
    int total_water=0;
    for (i=0; i<n; i++) 
    {
        int left_max=arr[i];
        for (j=0; j<i; j++) 
        {
            left_max=max(left_max,arr[j]);
        }
        
        int right_max=arr[i];
        for (j=i+1; j<n; j++) 
        {
            right_max=max(right_max,arr[j]);
        }
        
        total_water  = total_water + min(right_max,left_max)-arr[i];
    }
    return total_water;
}
int main()  
{  
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};  
    int n = sizeof(arr)/sizeof(arr[0]);  
      
    cout << maxWater(arr, n);  
      
    return 0;  
} 