
.. contents::
   :local:
   :depth: 3

STACKS
===============================================================================

`Reverse Words in a String <https://leetcode.com/problems/reverse-words-in-a-string/>`_
===============================================================================

.. code:: c++

    string reverseWords(string s) {
        stack <string> st;
        string ans = "";
     for (int i = 0; i < s.length(); ++i)
     {  string w = "";
         while(s[i]!=' ' && i < s.length() )
         {
            w += s[i];
            i++;
         }
      if(w.size() > 0)
          st.push(w);
     }
     while(!st.empty())
     {
        ans = ans + " " + st.top();
         st.pop();
     }
    if(ans.length() != 0 && ans[0] == ' ')
          ans =  ans.substr(1);
        return ans;
    }

      
`Balanced Brackets <https://www.hackerrank.com/challenges/balanced-brackets/problem>`_
===============================================================================

.. code:: c++


      #include <bits/stdc++.h>
      using namespace std;
      unordered_map<char, int> m = {{'(', -1}, {'{', -2}, {'[', -3}, {')', 1}, {'}', 2}, {']', 3}};
      string isBalanced(string s) {
      stack<char> st;
      for(char Bracket : s)
      {
          if(m[Bracket] < 0)
          st.push(Bracket);
          else
          {
              if(st.empty() || ((m[st.top()] + m[Bracket]) != 0)) return "NO";
              st.pop();
          }
      }
      if(st.empty()) return "YES";
      return "NO";
      }
      int main()
      {
        int t;
        cin >>  t;
        while(t--)
        {
          string s; 
          cin >> s;
          cout << isBalanced(s) << endl;
        }
        return 0;
      }
      
input

.. code:: c++

      3
      {[()]}
      {[(])}
      {{[[(())]]}}

output

.. code:: c++

      YES
      NO
      YES

`Next Greater Element <https://www.hackerrank.com/contests/second/challenges/next-greater-element/problem>`_
===============================================================================

.. code:: c++      


      void printNGE(int arr[], int n)
      {  stack<int> st;
         vector<int> nge(n, -1);
         for (int i = n-1; i >= 0; --i)
         {
            while(!st.empty() && st.top() <= arr[i])
            {
               st.pop();
            }
            if(i<n){
               if(!st.empty()) nge[i] = st.top();
            }
            st.push(arr[i]);
         }
         return nge;
      }

.. code:: c++      

      #include <bits/stdc++.h>
      using namespace std;

      vector<int> printNGE(vector<int> arr)
      {
          vector<int> v(arr.size());
          stack<int> st;
          for (int i = 0; i < arr.size(); i++)
          {
              while((!st.empty()) && (arr[i] > arr[st.top()]))
              {
                  v[st.top()] = i;
                  st.pop();
              }
              st.push(i);
          }

          while(!st.empty())
          {   
              v[st.top()] = -1;
                  st.pop();
          }
         return v;
      }
      int main()
      {       int n;
              cin >> n;
              vector<int> arr(n);
              for (int i = 0; i < n; ++i)
              {
                  cin >> arr[i];
              }
              vector<int> ans = printNGE(arr);
              for (int i = 0; i < arr.size(); ++i)
              {
                 cout << arr[i] << " " << (ans[i] == -1  ? -1 : arr[ans[i]]) << endl;
              }
          return 0;
      }
      
input

.. code:: c++

      6
      4 5 2 25 7 8
      
output

.. code:: c++

      4 5
      5 25
      2 25
      25 -1
      7 8
      8 -1
      
