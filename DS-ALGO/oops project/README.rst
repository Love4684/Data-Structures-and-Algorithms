.. contents::
   :local:
   :depth: 3
  
Bank Management System
===============================================================================


.. code:: c++


    #include<stdio.h>
    #include<iostream>
    using namespace std;

    class bank
    {
        char name[100],add[100],y;
        int balance, amount;
    public:
        void open_account ();
        void deposite_money();
        void withdraw_money ();
        void display_account();
    };
    void bank::open_account()
    {
        cout<<"Enter your full name ::";
        cin.ignore();
        cin.getline(name,100);
        cout<<"Enter your addess ::";
        cin.ignore();
        cin.getline(add,100);
        cout<<"what type of account you want to open saving (s) or current (c)";
        cin>>y;
        cout<<"Enter amount for deposite ::";
        cin>>balance;
        cout<<"Your account is created ";

    }
    void bank::deposite_money()
    {
        int a ;
        cout<<"Enter how much money you want to deposit::";
        cin>>a;
        balance+=a;
        cout<<"Your total deposit amount\n";
    }
    void bank::display_account()
    {
        cout<<"Enter the name ::"<<name<<endl;
        cout<<"Enterened your addees ::"<<add<<endl;
        cout<<"Type of account that you open ::"<<y<<endl;
        cout<<"Amount you deposite ::"<<balance<<endl;

    }
    void bank::withdraw_money()
    {
        cout<<"withdeaw ::";
        cout<<"Enter your amount for withdrawing ";
        cin>>amount;
        balance=balance-amount;
        cout<<"Now your total amount is left ::"<<balance;
    }

    int main()
    {
        int ch,x,n;
        bank obj;
        do
        {
        cout<<"01)open account \n";
        cout<<"02)deposite money \n";
        cout<<"03)withdeaw money \n";
        cout<<"04)display account\n";
        cout<<"05)Exit\n";
        cout<<"please sir, select the option from above ";
        cin>>ch;

        switch(ch)
        {
            case 1:"01)open account \n";
            obj.open_account ();
            break;
            case 2:"02)deposite money \n";
            obj.deposite_money();
            break;
            case 3:"03)withdeaw money \n";
            obj.withdraw_money ();
            break;
            case 4:"04)display account\n";
            obj.display_account();
            break;
            case 5:
                if(ch==5)
                {
                   cout<< "exit";
                }
            default:
                cout<<"This is not exit please try again ";

        }
        cout<<"\n do you want to select next step then please press::y\n";
        cout<<"if you want to exit then please press:: N ";
        x=getch();
        if(x=='n' || x=='N')
        cout<<"exit";
        }
        while (x=='y' || x=='Y');


     getch();
     return 0;




    }
    
Bank Management System
===============================================================================

// Design a Data Structure SpecialStack that supports
// all the stack operations like push(), pop(), isEmpty(), 
// isFull() and an additional operation getMin() which 
// should return minimum element from the SpecialStack. 
// All these operations of SpecialStack must be O(1)

  
Bank Management System
===============================================================================

C/C++ Test: Set #5
Q1.Develop an application that does the following:
 
Continuously maintains prices (for each product) in ascending order based on supplied inputs.
Each input contains the following type of record:
struct Book {
char Product[5];            	/* E.g. “P1”, “P2”, etc. */
int Price;             	/* E.g. 2000, 3000, etc */
int SeqNum;        	/* Positive number, e.g. 1, 2, 3 */
};
 
In order to demonstrate the working of this application, prepare the following methods/functions:
1. 	Book* Load()
From the given inputs, create and store data as Book records in a list (in the same sequence as given) and return this list.
2. 	void Process(const Book* newBook)
Use the information inside newBook to maintain topmost 5 prices in ascending order for this input product – in appropriate data structure(s).
Display this product’s processed information in the specified output format.
NOTE: For output purposes – assume topmost default values of Price to be zero.
 
Given the above specifications, the application is expected to execute as follows:
1. 	Create/initialize the required data storage(s).
2. 	Call Load() and iterate through the returned list.
3. 	For each element iterated in the above list - call Process() for that element.
 
Guidelines
1.     Make suitable assumptions and decisions regarding data types, data structures and their relationships.
2.     Error & boundary conditions should be appropriately handled
3.     Application output should clearly demonstrate the required functionality
4.     Application code should be optimized for least memory usage and least processing time - during execution.
 

The list of inputs for creating Book records is given below:
P3, 3350, 1
P1, 1500, 2
P2, 2400, 3
P1, 1300, 4
P3, 50, 5
P1, 1450, 6
P2, -1000, 7
P3, -50, 8
P1, 1350, 9
P2, 2350, 10
P1, 1400, 11
P3, 3400, 12
P1, 1300, 13
P2, -2350, 14
P1, 1250, 15
P3, 3350, 16
 
The format of expected output is given below (Price values separated by commas):
<SeqNum>: <Product> || <topmost 5 Price values ascending from left to right> ||
 
Input example (for reference only) is given below:
K7, 100, 1
K7, 90, 2
K7, 110, 3
K5, 80, 4
K7, -10, 5
K7, 80, 6
K7, 95, 7
K7, 80, 8
 
Output example (for reference only) is given below:
1: K7 || 100, 0, 0, 0, 0 ||
2: K7 || 90, 100, 0, 0, 0 ||
3: K7 || 90, 100, 110, 0, 0 ||
4: K5 || 80, 0, 0, 0, 0 ||
5: K7 || -10, 90, 100, 110, 0 ||
6: K7 || -10, 80, 90, 100,110 ||
7: K7 || -10, 80, 90, 95, 100 ||
8: K7 || -10, 80, 90, 95, 100 ||

    
