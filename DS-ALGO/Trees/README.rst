

.. contents::
   :local:
   :depth: 3

Trees
===============================================================================

`Path Sum II <https://leetcode.com/problems/path-sum-ii/>`_
===============================================================================

.. code:: c++

`Binary Tree Longest Consecutive Sequence <https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/>`_
===============================================================================

.. code:: c++


`Binary Tree Maximum Path Sum <https://leetcode.com/problems/binary-tree-maximum-path-sum/>`_
===============================================================================

.. code:: c++

`Binary Tree Level Order Traversal <https://leetcode.com/problems/binary-tree-level-order-traversal/>`_
===============================================================================

.. code:: c++

`Construct Binary Tree from Preorder and Inorder Traversal <https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/>`_
===============================================================================

.. code:: c++


`Populating Next Right Pointers in Each Node <https://leetcode.com/problems/populating-next-right-pointers-in-each-node/>`_
===============================================================================

.. code:: c++




Image of binary tree
=====================

      class Solution {
          void swap(TreeNode *curr)
          {
              if(!curr)
                  return;
              swap(curr->left);
              swap(curr->right);
              TreeNode *temp;
              temp = curr->left;
              curr->left = curr->right;
              curr->right = temp;
          }
      public:
          TreeNode* invertTree(TreeNode* root) {
              swap(root);     //Creates mirror image
              return root;
          }
      };

Image of binary tree
=====================

      {
      #include <bits/stdc++.h>
      using namespace std;
      /* A binary tree node has data, pointer to left child
         and a pointer to right child */
      struct Node {
          int data;
          Node* right;
          Node* left;

          Node(int x){
              data = x;
              right = NULL;
              left = NULL;
          }
      };
      /* Returns true if the given tree is a binary search tree
       (efficient version). */
      bool isBST(struct Node* node);
      int isBSTUtil(struct Node* node, int min, int max);
      /* Driver program to test size function*/
      int main()
      {
        int t;
        struct Node *child;
        scanf("%d
      ", &t);
        while (t--)
        {
           map<int, Node*> m;
           int n;
           scanf("%d
      ",&n);
           struct Node *root = NULL;
           while (n--)
           {
              Node *parent;
              char lr;
              int n1, n2;
              scanf("%d %d %c", &n1, &n2, &lr);
            //  cout << n1 << " " << n2 << " " << (char)lr << endl;
              if (m.find(n1) == m.end())
              {
                 parent = new Node(n1);
                 m[n1] = parent;
                 if (root == NULL)
                   root = parent;
              }
              else
                 parent = m[n1];
              child = new Node(n2);
              if (lr == 'L')
                parent->left = child;
              else
                parent->right = child;
              m[n2]  = child;
           }
           cout << isBST(root) << endl;
        }
        return 0;
      }

      }
      /*This is a function problem.You only need to complete the function given below*/
      /* A binary tree node has data, pointer to left child
         and a pointer to right child  
      struct Node {
          int data;
          Node* right;
          Node* left;

          Node(int x){
              data = x;
              right = NULL;
              left = NULL;
          }
      }; */
      bool checkBST(Node *root,int min,int max)
      {
          if(!root)
              return true;    //NULL is not a node to be checked. So, return true always
          if(root->data>min && root->data<max)
              return (checkBST(root->left,min,root->data) && checkBST(root->right,root->data,max));

          return false;
      }

      bool isBST(Node* root) {
          // Your code here
          if(!root)
              return true;
          if(checkBST(root->left,0,root->data) && checkBST(root->right,root->data,1001))
              return true;
          return false;
      }




