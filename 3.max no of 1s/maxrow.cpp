#include <bits/stdc++.h> 
using namespace std;
const int R = 4;
const int C = 4;
void FindMax(int a[R][C])
    {   int Row=0,i;
        int j=C-1;
        for(i=0;i<R;i++)
        {
          while((a[i][j]==1) && (j>=0) )
          {
              j--;
              Row = i ;
          }
        }
        cout<<Row;
    }
int main()
    { 
      int a[ ][4] = {{0,0,1,1},{1,1,1,1},{0,0,1,1},{1,1,1,1}};
      FindMax(a);
      return 0;
    }