.. sectnum::

===============================================================================
C++ crash course for C programmers
===============================================================================
:Author: `Love Kumar <http://luvji.com/>`_
:Sources: `crash-course.rst <crash-course.rst>`_

.. contents::
   :local:
   :depth: 2

Foreword
===============================================================================
This is an introduction to C++ for C programmers:

* If you can't understand the code below, you'd better start with a C tutorial.

  .. code:: c++

     #include <stdio.h>

     void main (int argc, char **argv)
     {
         printf("Hello World!\n");
     }

# program to check whether the entered string is palindrome or not.

===============================================================================

```cpp
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
```


# Different methods to reverse a string in C/C++

===============================================================================


## METHOD 1. using swap function
```cpp
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

```
## METHOD 2. using reverse() function

```cpp
#include <bits/stdc++.h> 
using namespace std; 
int main() 
{ 
	string str = "ROHAN"; 
	reverse(str.begin(), str.end()); 
    cout << str; 
	return 0; 
} 
```
## METHOD 3. using reverse() function
```cpp

```
