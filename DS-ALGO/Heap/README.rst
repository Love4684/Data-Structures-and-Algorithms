.. contents::
   :local:
   :depth: 3

Heap
===============================================================================

K’th Smallest Element in Unsorted Array
===============================================================================

.. code:: c++

    #include<bits/stdc++.h>
    using namespace std;

    int main()
     {     
         vector<int> v = {2, 3, 4, 5, 6};
         int  k = 2; 

        priority_queue<int> maxheap;
        for (int i = 0; i < 5; ++i)
         {
             maxheap.push(v[i]);
             if(maxheap.size() > k)
             {
                maxheap.pop();
             }
         }
         cout << maxheap.top();

        return 0;
    }

.. code:: c++

    3

K Largest Element in Unsorted Array
===============================================================================

.. code:: c++

