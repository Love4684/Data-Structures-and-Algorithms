#include<bits/stdc++.h>
using namespace std;
int Water_Trap(int a[], int n)
{
    int i=0;
    int j=n-1;
    int result=0;
    int left_max=0, right_max=0;
    while(i<j)
    {
        if(a[i]<=a[j])
        {
            left_max=max(left_max,a[i]);
            result+=left_max-a[i];
            i++;
        }
        else
        {
            right_max=max(right_max,a[j]);
            result+=right_max-a[j];
            j--;
        }
    }
    
    return result;
}
int main() 
{ 
    int a[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    cout << "Maximum water that can be accumulated is "
         << Water_Trap(a, n); 
    return 0; 
}
