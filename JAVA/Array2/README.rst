
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

`Find the Duplicate Number <https://leetcode.com/problems/find-the-duplicate-number/>`_
===============================================================================


.. code:: c++

      class Solution {
      public:
          int findDuplicate(vector<int>& nums) {
                      int i = 0;
              while(1){
                  if(nums[i] < 0) return i;
                  nums[i] *= -1;
                  i = -1*nums[i];
              }
          }
      };
      
.. code:: c++

      class Solution {
      public:
          int findDuplicate(vector<int>& nums) {
              int slow = nums[0];
              int fast = nums[0];
              do {
                  slow = nums[slow];
                  fast = nums[nums[fast]];
              }while (slow != fast);

              fast = nums[0];
              while (fast != slow) {
                  fast = nums[fast];
                  slow = nums[slow];
              }
              return fast;
          }
      };
      
      

`Sort Colors <https://leetcode.com/problems/sort-colors/submissions/>`_
===============================================================================

.. code:: c++     
      
      class Solution {
      public:
          void sortColors(vector<int>& nums) {
             int lo = 0; 
              int hi = nums.size() - 1; 
              int mid = 0;
              while (mid <= hi) { 
                  switch (nums[mid]) { 
                  case 0: 
                      swap(nums[lo++], nums[mid++]); 
                      break;  
                  case 1: 
                      mid++; 
                      break; 
                  case 2: 
                      swap(nums[mid], nums[hi--]); 
                      break; 
                  }
              }
          }
      };

`Height Checker <https://leetcode.com/problems/height-checker/>`_
===============================================================================

.. code:: c++ 

      / 1) Using non-comparative sort: T=O(N), S=O(1) ==> (100% faster, and efficient)
      // Use the logic of counting sort since total height is limited up to 101.

      class Solution {
      public:
          int heightChecker(vector<int>& heights) {
              int counter[101] = {0};
              for (auto& it:heights) counter[it]++;

              int k = 0, difference = 0;
              for (int i=0; i<=100; i++){
                  if (counter[i] != 0)
                      for (int times=0; times<counter[i]; times++){
                          if (heights[k] != i) difference++;
                          if (++k >= heights.size()) return difference;
                      }
              }
              return difference;
          }
      };

      // 2) Using comparative sort: T=O(N*logN), S=O(N)
      // sort two vectors and compare the values

      class Solution {
      public:
          int heightChecker(vector<int>& heights) {
              vector<int> vec = heights;
              sort(vec.begin(), vec.end());

              int count = 0;
              for (int i=0; i<vec.size(); i++){
                  if (vec[i] != heights[i])
                      count++;
              }
              return count;
          }
      };


`Number of Times Binary String Is Prefix-Aligned <https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/>`_
===============================================================================

.. code:: c++ 


`Interval List Intersections <https://leetcode.com/problems/interval-list-intersections/>`_
===============================================================================

.. code:: c++ 


    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int l1 = firstList.size();
        int l2 = secondList.size();
        int i = 0, j = 0;
        while(i<l1 && j<l2)
        {
            if(firstList[i][1]>=secondList[j][0] && firstList[i][0]<=secondList[j][1])
            {
                int x = max(firstList[i][0], secondList[j][0]);
                int y = min(firstList[i][1], secondList[j][1]);
                ans.push_back({x, y});
            }
            if(firstList[i][1]<secondList[j][1])
                i++;
            else if(firstList[i][1]>secondList[j][1])
                j++;
            else
            {
                i++; j++;
            }
        }
        return ans;
    }
    

`Get the Maximum Score <https://leetcode.com/problems/get-the-maximum-score/>`_
===============================================================================

.. code:: c++ 

    public int maxSum(int[] nums1, int[] nums2) {
        int MOD = (int) Math.pow(10,9) + 7;
        int p1 = 0, p2 = 0;
        long s1 = 0, s2 = 0;
        long maxScore = 0;
        
        while(p1 < nums1.length && p2 < nums2.length) {
            if(nums1[p1] < nums2[p2]) {
                s1 += nums1[p1];
                p1++;
            }
            else if(nums1[p1] > nums2[p2]) {
                s2 += nums2[p2];
                p2++;
            }
            else {
                maxScore += Math.max(s1, s2) + nums1[p1];
                maxScore %= MOD;
                s1 = s2 = 0;
                p1++;
                p2++;
            }
        }
        
        while(p1 < nums1.length) s1 += nums1[p1++];
        while(p2 < nums2.length) s2 += nums2[p2++];
        
        maxScore += Math.max(s1, s2);
        maxScore %= MOD;
        
        return (int) maxScore;
    }

