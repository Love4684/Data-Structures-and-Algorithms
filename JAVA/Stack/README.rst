
.. contents::
   :local:
   :depth: 3

Implement stack using array
===============================================================================

.. code:: c++


      #include <bits/stdc++.h>
      using namespace std;
      #define n 5
      class Stack {
          int top;
          int *arr;
      public:
          Stack()
          {
              arr = new int[n];
              top = -1;
          }
          void push(int x)
          {
              if(top == n-1)
              {
                  cout << "Stack overflow" << endl;
                  return;
              }
              top++;

              arr[top] = x;
          }
          void pop()
          {
              if(top == -1)
              {
                  cout << "no elrment to delete" << endl;
                  return;
              }
              top--;
          }
          int peek()
          {
              if(top == -1)
              {
                  cout << "no elrment in Stack" << endl;
                  return -1;
              }
              return arr[top];
          }
          bool isEmpty()
          {
              return top==-1;
          }
      };
      int main()
      {
          Stack st;
          st.push(3);
          st.push(8);
          st.push(5);
          cout << st.peek() << endl;
          st.pop();
          cout << st.peek() << endl;
          st.pop();
          st.pop();
          st.pop();
          cout << st.isEmpty() << endl;
          return 0;
      }



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
      
Java

.. code:: c++      


      import java.io.*;
      import java.util.*;
      class JavaProgramming
      {	
           public static int[] nextGreaterElements(int[] nums) {
              int n = nums.length;
              int nge[] = new int[n];
              Stack < Integer > st = new Stack < > ();
              for (int i = n - 1; i >= 0; i--) {
                  while (st.isEmpty() == false && st.peek() <= nums[i]) {
                      st.pop();
                  }

                  if (i < n) {
                      if (st.isEmpty() == false) nge[i] = st.peek();
                      else nge[i] = -1;
                  }

                  st.push(nums[i]);
              }
              return nge;
          }
          public static void main(String args[]) {
              int arr[]={5,7,1,2,6,0};

              int arr2[] = nextGreaterElements(arr);
              System.out.println("The next greater elements are ");
              for (int i = 0; i < arr2.length; i++) {
                  System.out.print(arr2[i] + " ");
              }

         }	
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
      
Find maximum in a stack in O(1) time and O(1) extra space
===============================================================================

.. code:: c++
      

      #include <bits/stdc++.h>
      using namespace std;


      struct MyStack {
         stack<int> s;
         int maxEle;


         void getMax()
         {
            if (s.empty())
               cout << "Stack is empty\n";


            else
               cout << "Maximum Element in the stack is: "
                  << maxEle << "\n";
         }


         void peek()
         {
            if (s.empty()) {
               cout << "Stack is empty ";
               return;
            }

            int t = s.top(); 

            cout << "Top Most Element is: ";


            (t > maxEle) ? cout << maxEle : cout << t;
         }


         void pop()
         {
            if (s.empty()) {
               cout << "Stack is empty\n";
               return;
            }

            cout << "Top Most Element Removed: ";
            int t = s.top();
            s.pop();


            if (t > maxEle) {
               cout << maxEle << "\n";
               maxEle = 2 * maxEle - t;
            }

            else
               cout << t << "\n";
         }

         void push(int x)
         {

            if (s.empty()) {
               maxEle = x;
               s.push(x);
               cout << "Number Inserted: " << x << "\n";
               return;
            }


            if (x > maxEle) {
               s.push(2 * x - maxEle);
               maxEle = x;
            }

            else
               s.push(x);

            cout << "Number Inserted: " << x << "\n";
         }
      };

      int main()
      {
         MyStack s;
         s.push(3);
         s.push(5);
         s.getMax();
         s.push(7);
         s.push(19);
         s.getMax();
         s.pop();
         s.getMax();
         s.pop();
         s.peek();

         return 0;
      }
      
      
