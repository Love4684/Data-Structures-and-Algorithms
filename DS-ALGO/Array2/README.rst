
.. contents::
   :local:
   :depth: 3
   
`Remove Duplicates from Sorted Array <https://leetcode.com/problems/remove-duplicates-from-sorted-array/>`_
===============================================================================


.. code:: c++

    class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int n = nums.size();
            if(n == 0) return 0;
            int i = 0;
            for(int j = 1; j < n; j++)
            {
                if(nums[i] != nums[j])
                {
                    i++;
                    nums[i] = nums[j];
                } 
            }
            return i+1;
        }
    };
