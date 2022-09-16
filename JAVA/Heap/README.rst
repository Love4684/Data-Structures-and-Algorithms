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

      #include<bits/stdc++.h>
      using namespace std;

      int main()
       {     
           vector<int> v = {2, 4, 6, 3, 5};
           int  k = 3; 

          priority_queue<int, vector<int>, greater<int> > minheap;
          for (int i = 0; i < 5; ++i)
           {
               minheap.push(v[i]);
               if(minheap.size() > k)
               {
                  minheap.pop();
               }
           }
           while(!minheap.empty())
           {
              cout << minheap.top() << " ";
              minheap.pop();
           }       
          return 0;
      }
      
output

.. code:: c++

      4 5 6 

`Top K Frequent Elements <https://leetcode.com/problems/top-k-frequent-elements/>`_
===============================================================================

.. code:: c++

`Merge k Sorted Lists <https://leetcode.com/problems/merge-k-sorted-lists/>`_
===============================================================================

.. code:: c++


`Find Median from Data Stream <https://leetcode.com/problems/find-median-from-data-stream/>`_
===============================================================================

.. code:: c++

