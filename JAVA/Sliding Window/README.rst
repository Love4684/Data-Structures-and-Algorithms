
.. contents::
   :local:
   :depth: 3

`Minimum Size Subarray Sum <https://leetcode.com/problems/minimum-size-subarray-sum/>`_
===============================================================================

.. code:: c++

    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum = 0;           
        int left = 0;          
        int right = 0;          
        int shortest = n+1; 
        
        while(right<n){
            sum += nums[right];
            
            if(sum >= target){
                while(sum>=target){
                    sum -= nums[left++];
                }
                shortest = min(shortest,right-left+2);
            }
            right++;
        }
        return shortest==n+1?0:shortest;
    }

`Longest Substring Without Repeating Characters <https://leetcode.com/problems/longest-substring-without-repeating-characters/>`_
===============================================================================

.. code:: c++

      import java.util.*;
      public class Main {
          static int solve(String s) {
              HashMap < Character, Integer > mpp = new HashMap < Character, Integer > ();
      
              int left = 0, right = 0;
              int n = s.length();
              int len = 0;
              while (right < n) {
                  if (mpp.containsKey(s.charAt(right))) 
                     left = Math.max(mpp.get(s.charAt(right)) + 1, left);
      
                  mpp.put(s.charAt(right), right);
      
                  len = Math.max(len, right - left + 1);
                  right++;
              }
              return len;
          }
      
          public static void main(String args[]) {
              String str = "takeUforward";
              System.out.println("The length of the longest substring without repeating 
              characters is " + solve(str));
      
          }
      }


`Find All Anagrams in a String #Leetcode 438 <https://leetcode.com/problems/find-all-anagrams-in-a-string/>`_
===============================================================================

.. code:: c++

    vector<int> findAnagrams(string s, string p) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> result;
        vector<int> count1(26,0) , count2(26,0);
        int m = s.length() , n = p.length();
        if(m<n) return {};
        for(int i=0;i<n;i++){
            count1[s[i]-'a']++;
            count2[p[i]-'a']++;
        }
        if(count1 == count2) 
            result.push_back(0);
        for(int i=n;i<m;i++){
            count1[s[i]-'a']++;
            count1[s[i-n]-'a']--;
            if(count1==count2)
                result.push_back(i-n+1);
        }        
        return result;
    }

