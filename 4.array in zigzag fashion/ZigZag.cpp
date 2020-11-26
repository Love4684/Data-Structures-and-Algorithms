

#include <iostream>
using namespace std;
void rearrange(int a[] , int n)
    {   int i;
        for(i=0;i<n-1;i++)
        {
            if(i%2==0)
            {
                if(a[i]>a[i+1])
                swap(a[i],a[i+1]);
            }
            else
                if(a[i]<a[i+1])
                swap(a[i],a[i+1]);
        }
        for(i=0;i<n;i++)
        {
            cout <<a[i]<<" " ;
        }
    }

int main()
{
    int a[7] = {4,3,7,8,6,2,1};
     rearrange(a , 7);   
    return 0;
}
