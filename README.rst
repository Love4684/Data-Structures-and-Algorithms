.. contents::
   :local:
   :depth: 3

MCQ
===============================================================================

Q. 1
===============================================================================

.. code:: c++

    A data structure is required for storing a set of integers such that each of the following operations
    can be done in (log n) time, where n is the number of elements in the set.

     o    Delection of the smallest element 
     o    Insertion of an element if it is not already present in the set

     Which of the following data structures can be used for this purpose?
    (A) A heap can be used but not a balanced binary search tree
    (B) A balanced binary search tree can be used but not a heap
    (C) Both balanced binary search tree and heap can be used
    (D) Neither balanced binary search tree nor heap can be used


    Answer: (B)

    Explanation:
    First we’ll discuss about heap and balanced bst and its time complexities for basic operations like

    insertion, deletion, find.

    Heap:-

    Let us consider it as min heap

    1) Insertion: O(logn)

    2) Delete Min: O(logn) (Just replace root with INT_MAX and heapify)

    3) Find: O(n)

    Balanced BST:-

    1) Insertion: O(logn)

    2) Delete Min: O(logn)

    3) Find: O(logn)

    Statement 1:

    1) Deletion of smallest element can be done in O(logn) in both data structures

    Statement 2:

    1) Insertion of an element if it is not already present in the set

    In heap, we can perform this operation in O(n) because we have to perform linear search here, where as in BST we can perform this in O(logn)
