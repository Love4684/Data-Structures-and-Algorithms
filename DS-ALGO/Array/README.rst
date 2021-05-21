
.. contents::
   :local:
   :depth: 3
   
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

using STL

.. code:: c++

      using namespace std;
      #include <bits/stdc++.h>

      int main()
      {
         int arr[5] = {4, 7, 6, 3, 9};
         int maxno = *max_element(arr, arr + 5);
         int minno = *min_element(arr, arr + 5);

         cout<<"min = "<< minno << endl << "max = "<< maxno;
         return 0;
      }

using python

.. code:: python

      arr = [4, 7, 6, 3, 9]
      min(arr)
      max(arr)

Searching Algorithms
===============================================================================

Linear Search O(n)
------------

cpp code

.. code:: c++

      using namespace std;
      #include <bits/stdc++.h>

            int LinearSearch(int arr[], int size, int key)
            {
               for(int i = 0; i < size; i++)
               {
                  if(arr[i]==key)
                     return i;
               }
               return -1;
            }

            int main()
            {
               int arr[5] = {4, 7, 6, 3, 9};
               int key = 6;
               int index = LinearSearch(arr, 5, key);
               (index == -1) ? cout<< "key not found" :cout << "key present at index = " << index;
               return 0;
            }

using python

.. code:: python

      def LinearSearch(arr, size, key):
        for i in range(size):
          if arr[i] == key:
            return i
        return -1

      arr = [4, 7, 6, 3, 9]
      index = LinearSearch(arr, len(arr), 6)
      if index == -1:
        print ("key not found")
      else :
        print("key found at index = ", index)

Binary Search O(log n)
------------

T(n) = T(n/2) + c 

cpp code

Recursive implementation of Binary Search , it's work on sorted array

.. code:: c++

      using namespace std;
      #include <bits/stdc++.h>

            int BinarySearch(int arr[], int l, int r, int key)
            {
               if(r >= l)
               {
                  int mid = (r + l)/2;
                  if(arr[mid] == key)
                     return mid;
                  if(arr[mid] > key)
                     return BinarySearch(arr, l, mid-1, key);

                  if(arr[mid] < key)
                     return BinarySearch(arr, mid + 1, r, key);
               }
               return -1;
            }

            int main()
            {
               int arr[5] = {3, 4, 6, 7, 9};
               int key = 9;
               int index = BinarySearch(arr, 0, 4, key);
               (index == -1) ? cout<< "key not found" :cout << "key present at index = " << index;
               return 0;
            }

Iterative implementation of Binary Search

.. code:: cpp


      #include <bits/stdc++.h>
      using namespace std;
      int binarySearch(int arr[], int l, int r, int x)
      {
         while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] == x)
               return m;
            if (arr[m] < x)
               l = m + 1;
            else
               r = m - 1;
         }
         return -1;
      }

      int main(void)
      {
         int arr[5] = { 2, 3, 4, 10, 40 };
         int x = 10;
         int result = binarySearch(arr, 0, n - 1, x);
         (result == -1) ? cout << "not present"
                  : cout << "present at index " << result;
         return 0;
      }


Sorting sorting algorithms
===============================================================================


Merge Sort (O(n log n))
------------

Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.
cpp code

.. code:: cpp

      #include<bits/stdc++.h>
      using namespace std;
      void merge(int arr[], int l, int mid, int r)
      {
          int n1 = mid-l+1;
          int n2 = r-mid;
          int a[n1], b[n2];
          for (int i = 0; i < n1; ++i)
          {
              a[i] = arr[l+i];
          }
           for (int i = 0; i < n2; ++i)
          {
              b[i] = arr[i+mid+1];
          }
          int i = 0;
          int j = 0;
          int k = l;
          while(i < n1 && j < n2)
          {
              if(a[i]<=b[j])
              {
                  arr[k] = a[i];
                  i++;
              }
              else
              {
                  arr[k] = b[j];
                  j++;
              }
              k++;
          }
         while(i<n1)
         {
          arr[k] = a[i];
          i++; k++;
         }
         while(j<n2)
         {
          arr[k] = b[j];
          j++; k++;
         }
      }
      void merge_sort(int arr[], int l, int r)
      {
          if(l<r)
          {
              int mid = (l + r)/2;
              merge_sort(arr, l, mid);
              merge_sort(arr, mid+1, r);
              merge(arr, l, mid, r);
          }
      }
      int main()  
      {
          int arr[5] = {3, 4, 7, 2, 1};
          merge_sort(arr, 0, 4);
          for (int i = 0; i < 5; ++i)
          {
              cout << arr[i];
          }
          return 0;
      }

QuickSort
------------
Worst-case (n²)

Average performance	O(n log n)

Best-case performance	O(n log n) 

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
