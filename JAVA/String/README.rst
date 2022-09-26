

.. contents::
   :local:
   :depth: 2
   
palindromic string
===============================================================================

.. code:: java

	import java.io.*;
	import java.util.*;
	class JavaProgramming
	{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		String S = new String();
		S = input.next();
		int n = S.length();
		String result = "YES";
		for (int i = 0; i < n/2; i++) 
			if (S.charAt(i) != S.charAt(n-i-1)) 
				result = "NO";
		System.out.println(result);
	}
	}

 
 
reverse a string
===============================================================================

swap function

.. code:: c++

    #include <bits/stdc++.h> 
    using namespace std; 

    void reverseStr(string& str) 
    { 
      int n = str.length(); 
      for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
    } 
    int main() 
    { 
      string str = "rohan"; 
      reverseStr(str); 
      cout << str; 
      return 0; 
    } 
    
reverse() function

.. code:: c++

  #include <bits/stdc++.h> 
  using namespace std; 
  int main() 
  { 
    string str = "ROHAN"; 
    reverse(str.begin(), str.end()); 
      cout << str; 
    return 0; 
  } 

.push_back () function

.. code:: c++

   #include <bits/stdc++.h> 
   using namespace std; 

   void reverse(string str) 
   { string str1;
   for (int i=str.length()-1; i>=0; i--) 
      str1.push_back(str[i]);
   cout << str1 << endl;

   } 

   int main(void) 
   { 
      string s = "dosti"; 
      reverse(s); 
      return (0); 
   } 

printing-pattern
===============================================================================


[ * * * * * ]

[ _ * * * _ ]

[ _ _ * _ _ ]

.. code:: c++

    #include <iostream>

    using namespace std;

    int main()
    {int n; cin>>n;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i  ; j++)
        {
            cout<<"_ ";

        }
        for(int j = 0; j < 2*n - (2*i + 1)  ; j++)
        {
            cout<<" * ";

        }
         for(int j = 0; j < i  ; j++)
        {
            cout<<" _";

        }
        cout << endl;

        }

        return 0;
    }


next palindrome
===============================================================================


.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;

      string nxtpl(string num)
      {
          int n = num.size();
          string str = num;
          for (int i = 0, j = n-1; i < j; ++i, --j)
          {
              str[j] = str[i];
          }
          if(str > num)
              return str;
          else
          {
              int mid = n/2;
              if((n&1) == 0) mid--;
              while(mid>=0)
              {
                  if(str[mid] < '9')
                  {
                      str[mid]++;
                      break;
                  }
                  else
                  {
                      str[mid] = '0';
                      mid--;
                  }
              }
              if(mid==-1 && str[0] == '0')
              {
                  n++;
                  str = '1' + str;
              }
              for(int i = 0, j = n-1; i < j; i++, j--)
              {
                  str[j] = str[i];
              }
              return str;
          }
      }

      int main()
      {
          string s = "4321";
          string np = nxtpl(s);
          cout << np;
          return 0;
      }


`Anagram of a String <https://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/>`_
===============================================================================

1. using 2 loop(n²)

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      bool isanagram(string s1 , string s2)
      {   bool anagram;
          bool visited[s1.size()];
          if(s1.size() == s2.size())
          {
              for (int i = 0; i < s1.size(); ++i)
              {char x = s1[i];
                  anagram = false;
                  for (int j = 0; j < s2.size(); ++j)
                  {
                      if((x == s2[j]) && !visited[j])
                      {   visited[j] = true;
                          anagram = true;
                          break;
                      }
                  }
                  if(!anagram)
                      return false;
              }
          }
          if(!anagram)
              return false;
          else
              return true;
      }
      int main()
      {
          string s1 = "aa#$123b";
          string s2 = "aba#$321";
          bool anagram = isanagram(s1, s2);
          if(anagram)
              cout << "anagram";
          else
              cout << "not anagram";
          return 0;
      }
 
2. using Sorting O(nLogn)

.. code:: c++

      bool isanagram(string s1 , string s2)
      {   
          if(s1.size() != s2.size())
              return false;
          sort(s1.begin(), s1.end());
          sort(s2.begin(), s2.end());
          for (int i = 0; i < s1.size(); ++i)
          {
              if(s1[i] != s2[i])
                  return false;
          }
          return true;
      }

3. using hashing O(n)
 
.. code:: c++

       bool isanagram(string s1 , string s2)
      {   
          if(s1.size() != s2.size())
              return false;
          map<char, int> map;
          for (int i = 0; i < s1.size(); ++i)
          {
             map[s1[i]]++;
             map[s2[i]]--;
          }
          for(auto it : map)
              if(it.second != 0)
                  return false;
          return true;
      }
      
`Group Anagrams <https://leetcode.com/problems/group-anagrams/>`_
===============================================================================

C++

.. code:: c++      

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        
        for(auto x: strs)
        {
            string temp = x;
            sort(x.begin(),x.end());
            mp[x].push_back(temp);
        }
        for(auto x: mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
    
JAVA

.. code:: java

		import java.io.*;
		import java.util.*;
		class JavaProgramming
		{	
		 public static List<List<String>> groupAnagrams(String[] strs) {
		HashMap<String, List<String>> hm = new HashMap<>();
		    for(int i = 0; i < strs.length; i++) {
		    char[] sw = strs[i].toCharArray();
		    Arrays.sort(sw);
		    String word = new String(sw);
		    if (!hm.containsKey(word))
			hm.put(word, new ArrayList<>());
		    hm.get(word).add(strs[i]);

		}
		return new ArrayList<>(hm.values());
		}
		public static void main(String args[])
		{
		    String arr[] = { "cat", "dog", "tac", "god", "act" };
			List<List<String>> ans = groupAnagrams(arr);
			for (List<String> l1 : ans)
		       System.out.println(l1); 

		}					
		}


`Group Shifted String <https://www.geeksforgeeks.org/group-shifted-string/>`_
===============================================================================

.. code:: c++


	public static ArrayList<ArrayList<String>> groupShiftedStrings(String[] array) {
		HashMap<String, ArrayList<String>> map = new HashMap<String, ArrayList<String>>();
		for(int i = 0 ;i < array.length ;i++) {
			String codedString = generatecode(array[i]);
			if (!map.containsKey(codedString))
                		map.put(codedString, new ArrayList<>());
            		map.get(codedString).add(array[i]);
		}
		return new ArrayList<>(map.values());
	}
	
	  public static String generatecode(String str) {
		String ans = "";
		for(int i = 1; i < str.length() ; i++) {
			char ch1 = str.charAt(i);
			char ch2 = str.charAt(i - 1);
			int diff = ch1 - ch2;
			if(diff < 0) {
				diff += 26;
			}
			ans += 'a' + diff;
		}
		
		return ans;
	}


`Reverse Words in a String <https://leetcode.com/problems/reverse-words-in-a-string/>`_
===============================================================================

`using stack <https://github.com/Love4684/Data-Structures-and-Algorithms/tree/master/DS-ALGO/stacks#id1>`_

.. code:: c++

    string reverseWords(string s) {
        string ans ;
        int i = 0;
        int n = s.length();
        while(i<n)
        {
            while(i < n && s[i] == ' ') i++;
            if(i >= n) break;
            int j = i+1;
            while(j < n && s[j] != ' ') j++;
            string sub = s.substr(i, j-i);
            if(ans.length() == 0) 
                ans = sub;
            else 
                ans = sub + " " + ans;
            i = j+1;
        }
        return ans;
    }
    
JAVA

.. code:: java

    //  Time Complexity = O(N)
    //  Space Complexity = O(1)     Neglecting the required String answer space
    
    public String reverseWords(String s) {
        //  Triming all the leading and trailing spaces with just one space in the end
        s=s.trim()+" ";         
        String answer = "", word = "";  //  Resultant String array "answer" and String "word" for each word
        int flag=0;             //  Flag variable
        
        for(int i = 0 ; i < s.length() ; i++){
            if(s.charAt(i) != ' '){
                word += s.charAt(i);
                flag=0;
            }
            else if(flag == 0){
                answer = word +" "+ answer;
                word = "";
                flag = 1;
            }
        }
        
        return answer.trim();
    }
    
.. code:: java

	import java.io.*;
	import java.util.*;
	class JavaProgramming
	{
	    public static String reverseWords(String s) {
	    String[] arr = s.replaceAll(" +", " ").split(" "); 

	    String ans = "";
	    for(String str : arr){
		    ans = str +" "+ans;  
	    }
	    return ans.trim();
	}
	public static void main(String[] args)
	{
		String s = "TUF is great for interview preparation";
		System.out.print(reverseWords(s));
	 }
	}
    

`Implement strStr() <https://leetcode.com/problems/implement-strstr/>`_
===============================================================================

.. code:: c++


      int strStr(string haystack, string needle)
      {
          int n = haystack.size();
          int m = needle.size();

          if (m == 0)
              return 0;

          int i = 0, j = 0;

          for (i = 0; i < n; ++i)
              if (haystack[i] == needle[0])
              {
                  for (j = 1; j < m; ++j)
                      if (haystack[i + j] != needle[j])
                          break;

                  if (j == m)
                      return i;
              }

          return -1;
      }

`Length of the longest substring without repeating characters <https://leetcode.com/problems/longest-substring-without-repeating-characters/>`_
===============================================================================

`Rotate String <https://leetcode.com/problems/rotate-string/>`_
===============================================================================

.. code:: c++
