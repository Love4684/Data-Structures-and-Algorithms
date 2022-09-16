.. contents::
   :local:
   :depth: 3
   

`Container With Most Water <https://leetcode.com/problems/container-with-most-water/>`_
=========================================

.. code:: c++

    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1, maxar=0;
        while(i<j)
        {
            maxar = max(maxar, min(height[i], height[j])*(j-i));
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return maxar;
    }

`Subarray with given sum <https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1>`_
==================================

.. code:: c++

    vector<int> subarraySum(int arr[], int n, long long s)
    {
    vector<int>ans;
       int sum=0;
        int i=0,j=0;
        while(j<n){
            if(sum<s){
                sum=sum+arr[i];
                if(sum==s){
                    ans.push_back(j+1);
                    ans.push_back(i+1);
                    return ans;
                }
                i++;
            }
            else{
                sum=0;
                j++;
                i=j;
            }
        }

        ans.push_back(-1);
        return ans;
    }



`3Sum <https://leetcode.com/problems/3sum/>`_
=========================================

.. code:: c++

    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       vector<vector<int>> ans;
        for(int i = 0; i<nums.size()-2; i++)
        {
            if(i==0 || (i>0&&nums[i]!=nums[i-1])) 
            {
                int j = i+1, k = nums.size()-1;
                while(j<k)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        ans.push_back(temp);
                        
                        while(j<k && nums[j]==nums[j+1])j++;
                        while(j<k && nums[k]==nums[k-1])k--;
                        
                    }
                    
                    if(nums[i]+nums[j]+nums[k]<0)j++;
                    else k--;
                }
            }
        }
        return ans;
    }
