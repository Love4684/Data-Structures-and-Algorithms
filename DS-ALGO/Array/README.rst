
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
  

`Maximum Subarray(Kadane's Algorithm) <https://leetcode.com/problems/maximum-subarray/>`_
=========================================

.. code:: c++

    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int currsum = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            currsum += nums[i];
            if(currsum > maxsum)
                maxsum = currsum;
            if(currsum < 0)
                currsum = 0;
        }
        return maxsum;
    }

`Maximum Sum Circular Subarray <https://leetcode.com/problems/maximum-sum-circular-subarray/>`_
=========================================


`Merge two sorted arrays <https://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/>`_
=========================================

.. code:: c++

      void merge(int arr1[], int arr2[], int n, int m) {
              int i=0;
              while(arr1[n-1]>arr2[0])
              {
                  if(arr1[i]>arr2[0])
                  {
                      swap(arr1[i],arr2[0]);
                      sort(arr2,arr2+m);
                  }
                  i++;
              }
          }


.. code:: c++

1. find the nth Prime Number
===============================================================================

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;

      int main()
       {     
           int j, n = 5, count = 0;
           for (int i = 2; i > 0; ++i)
           {  int  flag = 0;
               for ( j = 2; j < i; ++j)
               {
                   if(i%j == 0)
                   {
                      flag = 1;
                      break;
                   }
               }
               if(i == j)
               {
                  count++;
               }
               if(count == n)
               {
                  cout << i;
                  break;
               }
           }
           return 0;
      }


2. Segregate Even and Odd numbers
===============================================================================

cpp code

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      int main()
      {
          int arr[7] = {6, 5, 3, 4, 2, 1, 4};
          int i = 0;
          int j = 6;
          while(i<j)
          {
              while((arr[i]&1) == 0)
              {
                  i++;
              }
              while((arr[j]&1) == 1)
              {
                  j--;
              }
              swap(arr[i], arr[j]);
              i++; j--;
          }
          for (int i = 0; i < 7; ++i)
          {

              cout << arr[i] << " ";
          }
      }

output

.. code:: c++

      6 4 2 4 3 1 5 

3. Program to print the diamond shape
===============================================================================

cpp code

.. code:: c++

   #include<bits/stdc++.h>
   using namespace std;

   int main()
    {
        int n, j, k;
           cin >> n;
           for(int i = 1; i <= n; i++ )
           {
               for (j = n; j > i; j--)
               {
                   cout << " ";
               }
               for (k = 1; k <= i; k++)
               {
                   cout << "* ";
               }
               cout << endl;
           }
           for(int i = 1; i < n; i++ )
           {
               for (j = 1; j <= i; j++)
               {
                   cout << " ";
               }
               for (k = n-1; k >= i; k--)
               {
                   cout << "* ";
               }
               cout << endl;
           }

       return 0;
   }

output

.. code:: c++

          * 
         * * 
        * * * 
       * * * * 
      * * * * * 
       * * * * 
        * * * 
         * * 
          * 

4. product of all prime number less than given number
===============================================================================

.. code:: c++

    #include<bits/stdc++.h>
    using namespace std;

    int main()
     {      
         int n, result = 1, j;
            cin >> n;
            for(int i = 2; i < n; i++ )
            {
                for (j = 2; j < i; j++)
                {
                    if(i%j == 0)
                    {
                        break;
                    }
                }
                if(i == j)
                    result *= i;
            }
            cout << result << endl;
        return 0;
    }
    // ans = 30

5. Given an array A[] and a number x, check for pair in A[] with sum as x
===============================================================================


.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;

      void findpair(std::vector<int> v, int sum)
      {
          sort(v.begin(), v.end());
          int l = 0;
          int r = v.size() - 1;
          while(l<r)
          {
              if((v[l] + v[r]) == sum)
              {
                  cout << v[l] << " " << v[r];
                  break;
              }
              if((v[l] + v[r]) < sum)
                  l++;
              else
                  r--;
          }
      }

      int main()
      {
         std::vector<int> v = {4, 5, 6, 7, 5, 4, 4};
         int sum = 10;
         findpair(v, sum);
         return 0;
      }


6. Given an array replace every element by greater element on right side.
===============================================================================

.. code:: c++

      #include <iostream>
      using namespace std;
      int main(){
      int n=6,i,temp;    
      int a[6]={16,17,4,3,5,2};
      int max;
      max= a[n-1];
      a[n-1]=-1;
      for(i=n-2;i>=0;i--){
          temp=a[i];
          if(max>a[i+1])
              a[i]=max;
          else
              a[i]=a[i+1];
          max=temp;   
          }
       for(i=0;i<n;i++){
           cout<<a[i]<<" ";
       } 
      }
      
      
.. code:: c++

      I/p : 16 17 4 3 5 2

      o/p : 17 5 5 5 2 -1

7. Given an array replace every element by smaller element on left side.
===============================================================================

.. code:: c++

      #include <iostream>
      using namespace std;
      #include<bits/stdc++.h> 
      int main()
      {
      int n=6,i,temp;    
      int a[6]={16,17,4,3,5,2};
      int min;
      min= a[0];
      a[0]=INT_MAX;
      for(i=1;i<n;i++)
      {
          temp=a[i];
          if(min>a[i-1])
              a[i]=a[i-1];
          else
              a[i]=min;
          min=temp;
      }
       for(i=0;i<n;i++)
       {
           cout<<a[i]<<" ";
       }   
      }

.. code:: c++

      I/o : 16 17 4 3 5 2

      O/P : int max 16 16 4 3 3
 
8. Given the sorted 2d array having 0's and 1's , find the row number which have maximum no 1's.
===============================================================================

 #hint check column wise to get one in any row and that wil be the max
 
.. code:: c++

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
          
.. code:: c++

       input
         0 1 2 3
       0 0 0 1 1
       1 0 1 1 1
       2 0 0 1 1
       3 1 1 1 1
       output 3
 
9. array in zigzag fashion
===============================================================================

Given an array rearrange the element of array in zigzag fashion .


.. code:: c++          

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

.. code:: c++          

      I/P 4 3 7 8 6 2 1
      O/P 3 7 4 8 2 6 1

10. multiplication of previous and next element
===============================================================================

Given an array of integers, update every element with multiplication of previous and next element with following execeptions. a.) First element replaced by multiplication of first and second. b.) Last element replaced by multiplication of last and second last.


.. code:: c++

      #include <iostream>
      using namespace std;
      void NewArray(int arr[] , int n)
      {   
          if(n<=1)                         //if number of element less then two
          {
              return;            
          }

          int previous = arr[0];          //first element assigning with keeping the track of this element     
          arr[0] =previous*arr[1];

          for(int i=1; i<n-1; i++)
          {
              int current = arr[i];
              arr[i]  = previous*arr[i+1];
              previous = current;
          }

          arr[n-1] = previous*arr[n-1];
      }

      int main()
      {int n,i;
          int arr[] = {2, 3, 4, 5, 6};
          n=sizeof(arr)/sizeof(arr[0]);
          NewArray(arr , n);
          for(i=0;i<n;i++)
          {
             cout << arr[i]  <<" "; 
          }
      }

.. code:: c++

      I/P : arr[] = {2, 3, 4, 5, 6}
      O/p : arr[] = {6, 8, 15, 24, 30}

11. Maximized Number of Consecutive 1’s
===============================================================================

You are given with an array of 1s and 0s. And you are given with an integer m, which signifies number of flips allowed. find the maximum number of consecutive 1's. and also find the position of zeros which when flipped will produce maximum continuous series of 1s.


.. code:: c++

      #include<bits/stdc++.h> 
      using namespace std; 
      void findZeroes(int arr[], int n, int m) 
      { 
          // Left and right indexes of current window 
          int wL = 0, wR = 0;  

          // Left index and size of the widest window  
          int bestL = 0, bestWindow = 0;  

          // Count of zeroes in current window 
          int zeroCount = 0;  

          // While right boundary of current window doesn't cross  
          // right end 
          while (wR < n) 
          { 
              // If zero count of current window is less than m, 
              // widen the window toward right 
              if (zeroCount <= m) 
              { 
                  if (arr[wR] == 0) 
                    zeroCount++; 
                  wR++; 
              } 

              // If zero count of current window is more than m, 
              // reduce the window from left 
              if (zeroCount > m) 
              { 
                  if (arr[wL] == 0) 
                    zeroCount--; 
                  wL++; 
              } 

              // Updqate widest window if this window size is more 
              if ((wR-wL > bestWindow) && (zeroCount<=m)) 
              { 
                  bestWindow = wR-wL; 
                  bestL = wL;
              } 
          } 
        cout<<"mximum 1's "<<bestWindow<<endl;
          // Print positions of zeroes in the widest window 
          cout << "Indexes of zeroes to be flipped are "; 
          for (int i=0; i<bestWindow; i++) 
          { 
              if (arr[bestL+i] == 0) 
                 cout << bestL+i << " "; 
          } 
      }   
      // Driver program 
      int main() 
      { 
         int arr[] = {1, 1, 0, 1, 1, 0, 0, 1, 1, 1}; 
         int m = 2; 
         int n =  sizeof(arr)/sizeof(arr[0]); 
         findZeroes(arr, n, m); 
         return 0; 
      } 
      
.. code:: c++

      arr={1 1 0 1 1 0 0 1 1 1 } m=1
      output={1 1 1 1 1 0 0 1 1 1} position=2
      arr={1 1 0 1 1 0 0 1 1 1 } m=2
      output={1 1 0 1 1 1 1 1 1 1} position=5,6

12. Trapping Rain Water
===============================================================================

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

.. image:: https://user-images.githubusercontent.com/42657629/95177014-46ae6a80-07db-11eb-8fe3-578ded353d25.png

method 1
--------
.. code:: c++

      #include<bits/stdc++.h>
      #include<iostream>
      using namespace std;
      int maxWater(int arr[], int n)
      {int i,j;
          int total_water=0;
          for (i=0; i<n; i++) 
          {
              int left_max=arr[i];
              for (j=0; j<i; j++) 
              {
                  left_max=max(left_max,arr[j]);
              }

              int right_max=arr[i];
              for (j=i+1; j<n; j++) 
              {
                  right_max=max(right_max,arr[j]);
              }

              total_water  = total_water + min(right_max,left_max)-arr[i];
          }
          return total_water;
      }
      int main()  
      {  
          int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};  
          int n = sizeof(arr)/sizeof(arr[0]);  

          cout << maxWater(arr, n);  

          return 0;  
      } 

method 2
--------
.. code:: c++

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

      }
      
method 3
--------
.. code:: c++

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

.. code:: c++

      input : arr[]={1, 0, 2, 1, 0, 1, 1, 3, 2, 1, 2, 1}

      output: 7

      Method 1 : 

                hint : Crate new array for left max

                       L[] = {1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3}

                       Create another array for right max

                       R[] = {3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1}

                       water wil trap between minimum of right and left
                       min(L[i] , R[i]) - arr[i]

                       Complexity Analysis: 

                       Time Complexity: O(n). 
                       Only one traversal of the array is needed, So time Complexity is O(n).
                       Space Complexity: O(n). 
                       Two extra array is needed each of size n.

13. Circular Tour
===============================================================================

Suppose there is a circle. There are n petrol pumps on that circle. You are given two sets of data. The amount of petrol that every petrol pump has. Distance from that petrol pump to the next petrol pump. Calculate the first point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity). Expected time complexity is O(n).

Assume for 1-litre petrol, the truck can go 1 unit of distance.
For example, let there be 4 petrol pumps with amount of petrol and distance to next petrol pump value pairs as {4, 6}, {6, 5}, {7, 3} and {4, 5}.

Return the starting petrol pumps index if you can travel around the circuit once in the clockwise direction, otherwise return -1.

.. code:: c++

      #include <bits/stdc++.h> 
      using namespace std;  
          int canCompleteCircuit(int Petrol[], int Distance[], int n ) 
          {
              int deficit = 0, surplus = 0, Start = 0;
              for(int i = 0; i < n; ++i){
                  surplus += Petrol[i] - Distance[i];

                  if(surplus < 0)
                  {
                      Start = i+1;
                      deficit+=surplus;
                      surplus = 0;
                  }
              }
              return (surplus+deficit < 0) ? -1 : Start;
          }
      int main()
      {
          int Petrol[]  = {6,3,7};
          int Distance[] = {4,6,3};
          int n=sizeof(Petrol)/sizeof(Petrol[0]);
          int start = canCompleteCircuit(Petrol,Distance, n);  

          (start == -1)? cout<<"No solution": cout<<"Start = "<<start;  
          return 0; 
      }

14. `Best Time to Buy and Sell Stock <https://leetcode.com/problems/best-time-to-buy-and-sell-stock/>`_
===============================================================================

.. code:: c++

    int maxProfit(vector<int>& prices) {
        int maxp = 0;
        int mine = prices[0];
        int n = prices.size();
        for(int i = 1; i < n; i++)
        {
            mine = min(mine, prices[i]);
            int profit = prices[i] - mine;
            maxp = max(maxp, profit);
        }
        return maxp;
    }
    
15. `Rotate Array <https://leetcode.com/problems/rotate-array/>`_
===============================================================================

.. code:: c++    

      class Solution {
      public:

          void reverse(vector<int> &num, int low, int high){
              while(low < high){
                  swap(num[low], num[high]);
                  low++;
                  high--;
              }
          }
          void rotate(vector<int>& nums, int k) {

              int n = (int)nums.size();
              k = k%n;
              reverse(nums, 0, n-k-1);
              reverse(nums, n-k, n-1);
              reverse(nums, 0, n-1);
          }
      };

