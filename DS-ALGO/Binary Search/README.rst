
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
    
    

`Nth Magical Number <https://leetcode.com/problems/nth-magical-number/>`_
===============================================================================

.. code:: c++

