
.. contents::
   :local:
   :depth: 3

STACKS
===============================================================================

Reverse a Sentence using Stacks
===============================================================================

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;

      int main()
       {      
           string s;
           getline(cin, s);
           stack <string> st;
           for (int i = 0; i < s.length(); ++i)
           {  string w = "";
               while(s[i]!=' ' && i < s.length() )
               {
                  w += s[i];
                  i++;
               }
               st.push(w);
           }

           while(!st.empty())
           {
              cout << st.top() << " ";
              st.pop();
           }

          return 0;
      }

input

.. code:: c++

      RAM is a good boy


output

.. code:: c++

      boy good a is RAM 
      
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

      
