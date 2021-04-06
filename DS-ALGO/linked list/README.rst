
.. contents::
   :local:
   :depth: 3

linkedlist
===============================================================================

Inserting a node
--------------

.. code:: c++

      #include<bits/stdc++.h>
      using namespace std;
      class node
      {
          public:
              int data;
              node * Next;
          node(int val)
          {
              data = val;
              Next = NULL;
          }
      };
      void insert(node * &head, int val)
      {
          node * n = new node(val);
          if(head == NULL)
          {
              head = n;
              return;
          }
          node * temp = head;
          while(temp->Next != NULL)
          {
              temp = temp->Next;
          }
          temp->Next = n;
      }
      void display(node * &head)
      {
          node * temp = head;
          while(temp->Next != NULL)
          {
              cout << temp->data << " ";
              temp = temp->Next;
          }
          cout << temp->data << " ";
          cout << "NULL";

      }
      int main()
      {node * head = NULL;
          insert(head, 1);
          insert(head, 2);
          insert(head, 3);
          display(head);
          return 0;
      }
