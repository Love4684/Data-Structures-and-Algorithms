
.. contents::
   :local:
   :depth: 3

linkedlist Overview
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
              node * next;
          node(int val)
          {
              data = val;
              next = NULL;
          }
      };

.. code:: c++


      void insert(node * &head, int val)
      {
          node * n = new node(val);
          if(head == NULL)
          {
              head = n;
              return;
          }
          node *p = head;
          while(p->next != NULL)
          {
              p = p->next;
          }
          p->next = n;
      }
      
.. code:: c++
      
      void display(node  * &head)
      {
          node *p = head;
          while(p != NULL)
          {
              cout << p->data << " ";
              p = p->next;
          }
      }
      
.. code:: c++
      
      node* reverse(node *&head)
      {
          node *current = head;
          node *nextp;
          node *prev = NULL;
          while(current != NULL)
          {
              nextp = current->next;
              current->next = prev;
              prev = current;
              current = nextp;
          }
      return prev;
      }
      
.. code:: c++

      node* reverse_rec(node* &head)
      {
          if(head==NULL || head->next == NULL)
          {
              return head;
          }
          node* newhead = reverse_rec(head->next);
          head->next->next = head;
          head->next = NULL;

          return newhead;
      }
      
.. code:: c++
      
      int main()
      {
          node *head = NULL;
          insert(head, 4);
          insert(head, 8);
          insert(head, 80);
          insert(head, 8);
          display(head);
          // node* newhead = reverse(head);
          // cout << endl;
          // display(newhead);
          node* rec_head = reverse_rec(head);
          cout << endl;
          display(rec_head);

          return 0;
      }

