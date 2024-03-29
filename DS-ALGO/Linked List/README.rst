

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
          node *prev = NULL;
          node *current = head;
          node *nextp;
          
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

`Middle of the Linked List <https://leetcode.com/problems/middle-of-the-linked-list/>`_
===============================================================================

.. code:: c++

      class Solution {
      public:
          ListNode* middleNode(ListNode* head) {
             ListNode * slow = head, *fast = head;
              while(fast!=NULL && fast->next!=NULL)
              {
                  fast = fast->next->next;
                  slow = slow->next;
              }
              return slow;
          }
      };


`Delete Node in a Linked List <https://leetcode.com/problems/delete-node-in-a-linked-list/>`_
===============================================================================

.. code:: c++

    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
    
`Remove Nth Node From End of List <https://leetcode.com/problems/remove-nth-node-from-end-of-list/>`_
===============================================================================

.. code:: c++    


      class Solution {
      public:
          ListNode* removeNthFromEnd(ListNode* head, int n) {
              ListNode* start = new ListNode();
              start->next = head;
              ListNode *fast = start;
              ListNode *slow = start;
              for(int i = 0; i < n; i++)
                  fast = fast->next;
              while(fast->next != NULL)
              {
                  fast = fast->next;
                  slow = slow->next;
              }
              slow->next = slow->next->next;
              return start->next;
          }
      };

`Linked List Cycle <https://leetcode.com/problems/linked-list-cycle/>`_
===============================================================================

.. code:: c++

      class Solution {
      public:
          bool hasCycle(ListNode *head) {
              ListNode* slow = head;
              ListNode* fast = head;
              while(slow && fast && fast->next) {
                  slow = slow->next;
                  fast = fast->next->next;
                  if(fast == slow) return true;
              }     
              return false;
          }
      };
      
`Linked List Cycle II <https://leetcode.com/problems/linked-list-cycle-ii/>`_
===============================================================================

.. code:: c++

      class Solution {
      public:
          ListNode *detectCycle(ListNode *head) {
              ListNode* slow = head;
              ListNode* fast = head;
              ListNode* entry = head;
              while(fast && fast->next) {
                  slow = slow->next;
                  fast = fast->next->next;
                  if(fast == slow) 
                  {
                      while(slow != entry)
                      {
                      slow = slow->next;
                      entry = entry->next;
                      }
                   return entry;
                  }
              }     
              return NULL;
          }
      };
      

`Copy List with Random Pointer <https://leetcode.com/problems/copy-list-with-random-pointer/>`_
===============================================================================

.. code:: c++

      Node* copyRandomList(Node* head) 
      {
          Node *curr=head,*front=head;

          while(curr!=NULL)
          {
              front=curr->next;
              Node *copy=new Node(curr->val);
              curr->next=copy;
              copy->next=front;
              curr=front;
          }
          curr=head;
          while(curr!=NULL)
          {
              if(curr->random!=NULL)
              {
                  curr->next->random=curr->random->next;
              }
              curr=curr->next->next;
          }
          curr=head;
          Node *dummy=new Node(0);
          Node *copy=dummy;
          while(curr!=NULL)
          {
              front=curr->next->next;
              copy->next=curr->next;
              curr->next=front;
              copy=copy->next;
              curr=curr->next;
          }
          return dummy->next;
      }
      
`Add Two Numbers <https://leetcode.com/problems/add-two-numbers/>`_
===============================================================================

.. code:: c++      

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next;    
    }
      

`Next greater element in the Linked List <https://www.geeksforgeeks.org/next-greater-element-in-the-linked-list/>`_
===============================================================================

.. code:: c++


`Swap Nodes in Pairs <https://leetcode.com/problems/swap-nodes-in-pairs/>`_
===============================================================================

.. code:: c++

`Partition List <https://leetcode.com/problems/partition-list/>`_
===============================================================================

.. code:: c++



