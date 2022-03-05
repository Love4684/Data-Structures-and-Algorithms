
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
