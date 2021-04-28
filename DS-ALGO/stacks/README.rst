
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
      
Check for Balanced Brackets in an expression (well-formedness) using Stack
===============================================================================

.. code:: c++
      
      
      
