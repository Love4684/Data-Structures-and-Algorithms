
.. contents::
   :local:
   :depth: 3

`Minimum Size Subarray Sum <https://leetcode.com/problems/minimum-size-subarray-sum/>`_
===============================================================================

.. code:: c++

`Longest Substring Without Repeating Characters <https://leetcode.com/problems/longest-substring-without-repeating-characters/>`_
===============================================================================

.. code:: c++

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

