
.. contents::
   :local:
   :depth: 3

Q.1
===============================================================================

.. code:: c++

    Following is C like pseudo code of a function that takes a Queue as an argument, and uses a stack S to do processing.

    void fun(Queue *Q)
    {
        Stack S;  // Say it creates an empty stack S

        // Run while Q is not empty
        while (!isEmpty(Q))
        {
            // deQueue an item from Q and push the dequeued item to S
            push(&S, deQueue(Q));
        }

        // Run while Stack S is not empty
        while (!isEmpty(&S))
        {
          // Pop an item from S and enqueue the poppped item to Q
          enQueue(Q, pop(&S));
        }
    }

    What does the above function do in general?
    a. Removes the last from Q
    b. Keeps the Q same as it was before the call
    c. Makes Q empty
    d. Reverses the Q        <<<<<<<<<<<<< ANS
