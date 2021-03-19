
.. contents::
   :local:
   :depth: 2
   
QuickSort
===============================================================================

QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways. 

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
