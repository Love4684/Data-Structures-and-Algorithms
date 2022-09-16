.. contents::
   :local:
   :depth: 3

Print all combinations of balanced parentheses
===============================================================================

.. code:: c++

    #include<bits/stdc++.h>
    using namespace std;
    void pran(char *arr, int n, int ind, int open , int close)
    {
        if(ind == 2*n){
            arr[2*n] = '\0';
                cout << arr;
            cout<< endl;
            return;
        }
        if(open < n){
            arr[ind] = '{';
            pran(arr, n, ind+1, open+1, close);
        }
        if(open > close){
            arr[ind] = '}';
            pran(arr, n, ind+1, open, close+1);
        }
    }
    int main()
    {
        char arr[100];
        int n;
        cin>>n;
        pran(arr, n, 0, 0, 0 );
    }
    
output

.. code:: c++

    {{}}
    {}{}

