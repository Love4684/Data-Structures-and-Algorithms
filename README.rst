
.. contents::
   :local:
   :depth: 2
   
Array in C++
===============================================================================

An Array is a data structure used to store blocks of information in contiguous
memory allocation. The data can be integer, strings, characters, class objects, etc.

Finding Max and Min element
------------

cpp code


.. code:: c++


      using namespace std;
      #include <bits/stdc++.h>

            int main()
            {
               int arr[5] = {4, 7, 6, 3, 9};
               int maxno = INT_MIN;
               int minno = INT_MAX;
               for(int i = 0; i < 5; i++)
               {
                  maxno = max(maxno, arr[i]);
                  minno = min(minno, arr[i]);

               }

               cout<<"min = "<< minno << endl << "max = "<< maxno;
               return 0;
            }





QuickSort
===============================================================================

QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways. 

cpp code

.. code:: cpp

    using namespace std;
    #include <bits/stdc++.h>
    int partition(int arr[], int l, int r)
    {
      int i=l-1;
      int pivot = arr[r];
      for(int j = l; j < r; j++)
      {
        if(arr[j] < pivot )
        {
          i++;
        swap(arr[i], arr[j]);
        }	

      }
      swap(arr[i+1], arr[r]);
      return i+1;
    }
    void quicksort(int arr[], int l, int r)
    {
      if(l < r)
      {
        int pi = partition(arr, l, r);
        quicksort(arr, l, pi - 1);
        quicksort(arr, pi + 1, r);
      }
    }
    int main(){
      int arr[5] = {4, 5, 3, 7, 8};
      quicksort(arr, 0, 4);
      for(int i = 0; i < 5; i++)
      {
        cout << arr[i] << " ";
      }
      return 0;
    }
    
python code

.. code:: python

      def partition(arr, l, r):
        i = l-1;
        pivot = arr[r]
        for j in range (l, r):
          if arr[j] < pivot :
            i = i + 1
            arr[i] , arr[j] = arr[j] , arr[i]
        arr[i+1], arr[r] = arr[r], arr[i+1]
        return i+1

      def Quicksort(arr, l, r):
        if l >= r :
          return
        if l < r :
          pi = partition(arr, l, r)
          Quicksort(arr, l, pi-1)
          Quicksort(arr, pi+1, r)

      arr = [9, 5, 6, 7, 3, 8, 2]
      n = len(arr)
      Quicksort(arr, 0, n-1)
      print(arr)
