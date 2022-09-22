
.. contents::
   :local:
   :depth: 3



`Search in Rotated Sorted Array <https://leetcode.com/problems/search-in-rotated-sorted-array/>`_
===============================================================================

.. code:: c++

    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int mid = (l + r)/2;
        while(l<=r){
            mid=(l+r)/2;
            if(target==nums[mid]){
                return mid;
            }
            if(nums[l] <= nums[mid]){
                if(target>=nums[l] && target<=nums[mid]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(target>=nums[mid] && target<=nums[r]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return -1;
    }
    
`Find the number of elements greater than k in a sorted array <https://www.geeksforgeeks.org/find-the-number-of-elements-greater-than-k-in-a-sorted-array/>`_
===============================================================================

.. code:: java

      import java.io.*;
      import java.util.*;
      class JavaProgramming
      {
      static int countGreater(int arr[], int n, int k)
      {
         int l = 0;
         int r = n - 1;
         int leftGreater = n;
         while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] > k) {
               leftGreater = m;
               r = m - 1;
            }
            else
               l = m + 1;
         }
         return (n - leftGreater);
      }
      public static void main(String[] args)
      {
         int arr[] = { 3, 3, 4, 7, 7, 7, 11, 13, 13 };
         int n = arr.length;
         int k = 7;
         System.out.println(countGreater(arr, n, k));
      }
      }

    
    
`Find First and Last Position of Element in Sorted Array <https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/>`_
===============================================================================

.. code:: c++


      int firstOcc(vector<int> a, int t)
    {
        int l=0,h=a.size()-1,ans=-1;
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(a[mid] == t)
            {
                ans = mid;
                h=mid-1;
            }else if(a[mid] > t)
                h=mid-1;
            else
                l=mid+1;
        }
        return ans;
    }
    
     int secondOcc(vector<int> a, int t)
    {
        int l=0,h=a.size()-1,ans=-1;
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(a[mid] == t)
            {
                ans = mid;
                l=mid+1;
            }else if(a[mid] > t)
                h=mid-1;
            else
                l=mid+1;
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOcc(nums,target), secondOcc(nums,target)};
    }


    
    
`Find Minimum in Rotated Sorted Array <https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/>`_
===============================================================================

.. code:: c++

    int findMin(vector<int>& nums) {
        
        int l = 0, r = nums.size()-1;
        int mid = (l+r)/2;
        while(l<r)
        {   
            if(nums[r]<nums[mid])
                l = mid+1;
            else
                r = mid;
            mid = (l+r)/2;
            
        }
        return nums[l];
    }
    
`Find Minimum in Rotated Sorted Array II <https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/>`_
===============================================================================

.. code:: c++

    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int mid = (l+r)/2;
        while(l<r)
        {   
            if(nums[mid]>nums[r])
                l = mid+1;
            else if(nums[mid]<nums[r])
                r = mid;
            else
                r--;
            mid = (l+r)/2;
            
        }
        return nums[l];
    }

`Peak Index in a Mountain Array <https://leetcode.com/problems/peak-index-in-a-mountain-array/>`_
===============================================================================

.. code:: c++

    public int peakIndexInMountainArray(int[] arr) {
        int l = 0, r = arr.length-1;
        int mid = (l+r)/2;
        while(l<r)
        {   mid = (l+r)/2;
            if(arr[mid] < arr[mid+1])
                l = mid+1;
            else
                r = mid;
                
        }
        return l;
    }
    
`Single Element in a Sorted Array <https://leetcode.com/problems/single-element-in-a-sorted-array/>`_
===============================================================================

.. code:: c++    

    int singleNonDuplicate(vector<int>& nums) {
    int low = 0;
    int high = nums.size()-1;
    
    while(low <= high) {  
        int mid = low + (high-low)/2;
        
        if(mid == 0 || mid == nums.size()-1) return nums[mid];
        
        if(mid%2==0) {
             if(nums[mid] == nums[mid+1]) low = mid+1;
            else if(nums[mid] == nums[mid-1]) high = mid-1;
            else return nums[mid];
        }
        else {
            if(nums[mid] == nums[mid+1]) high = mid-1;
            else if(nums[mid] == nums[mid-1]) low = mid+1;
            else return nums[mid];
        }       
    }
    
    return nums[low];
    }
    
    
`Sqrt(x) <https://leetcode.com/problems/sqrtx/>`_
===============================================================================

.. code:: c++    

    long long int bs(int n){
        int l=0,h=n;
        long long int mid;
        long long int ans=-1;
        while(l<=h){
            mid=l+(h-l)/2;
            long long int sqrt=mid*mid;
            if(sqrt==n)
            return mid;
            else if(sqrt<n)
            {
            ans=mid;
            l=mid+1;
            }
            else
            h=mid-1;
        }
        return ans;
    }
    int mySqrt(int x) {
        return bs(x);
    }
   
`Nth Root of a Number using Binary Search <https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search/>`_
===============================================================================

.. code:: c++

      #include <bits/stdc++.h>
      using namespace std;
      void getNthRoot(int n, int m) {
          double low = 1;
          double high = m;
          double eps = 1e-7; 

          while((high - low) > eps) {
              double mid = (low + high) / 2.0; 
              if(pow(mid, n) < m) {
                  low = mid; 
              }
              else {
                  high = mid; 
              }
          }

          cout <<n<<"th root of "<<m<<" is "<<low<<endl; 

      }


`Nth Magical Number <https://leetcode.com/problems/nth-magical-number/>`_
===============================================================================

.. code:: c++

