

.. contents::
   :local:
   :depth: 2
   
palindromic string
===============================================================================

.. code:: c++
      
      #include <iostream>
      using namespace std;

      int main(){
          char string1[20];
          int i, length;
          int flag = 0;

          cout << "Enter a string: "; cin >> string1;

          length = strlen(string1);

          for(i=0;i < length ;i++){
              if(string1[i] != string1[length-i-1]){
                  flag = 1;
                  break;
         }
      }

          if (flag) {
              cout << string1 << " is not a palindrome" << endl; 
          }    
          else {
              cout << string1 << " is a palindrome" << endl; 
          }
          system("pause");
          return 0;
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
          string s1 = "aab";
          string s2 = "abc";
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
      
Length of the longest substring without repeating characters
===============================================================================

Distribute N candies among K people
===============================================================================
