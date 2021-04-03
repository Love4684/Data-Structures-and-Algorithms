
.. contents::
   :local:
   :depth: 2
   
   
program to check whether the entered string is palindrome or not.
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
 
 
 
Different methods to reverse a string in C/C++
===============================================================================

METHOD 1. using swap function
------------
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
    
METHOD 2. using reverse() function
------------
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

METHOD 3. using .push_back () function
------------
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



Length of the longest substring without repeating characters
===============================================================================

