#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#include <algorithm>
int main() 
{
    int t;
    cin>>t;

	while(t--)
	{
	    int n,i;
	    cin>>n;
	    
	   
	    int a[n];
	    for( i = 0; i < n ; i++)
	    {
	      cin>>a[i];
	      
	    }

	    int l[n];
	    l[0]=a[0];
	    for( i = 1; i < n ; i++)
	    {
	        l[i]=max(a[i],l[i-1]);
	    }

	     int r[n];
	     r[n-1]=a[n-1];
	     for( i = n-2; i>=0 ; i--)
	    {
	        r[i]=max(a[i],r[i+1]);
	    }
	    
	    int sum=0;
	    for( i = 0; i < n ; i++)
	    {
	        sum=sum+((min(l[i], r[i]))-a[i]);
	    }
	    cout<<sum<<endl;
	}
	return 0;
}