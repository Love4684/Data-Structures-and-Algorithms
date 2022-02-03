
.. contents::
   :local:
   :depth: 3

operating system
===============================================================================

.. code:: c++


      The operating system is a software program that facilitates computer hardware to communicate and operate with the 
      computer software. It is the most important part of a computer system without it computer is just like a box.

process
===============================================================================

.. code:: c++

      An executing program is known as process.
      For example, a Web Browser is a process, a shell (or command prompt) is a process.

      1. Start : This is the initial state when a process is first started/created.
      2. Ready : The process is waiting to be assigned to a processor.
      3. Runing : The process is chosen by CPU for execution.
      4. Waiting : Process moves into the waiting state if it needs to wait for a resource.
      5. Completion or termination : When a process finishes its execution, it comes in the termination state.

kernel
===============================================================================

.. code:: c++


      A kernel is the central component of an operating system that manages the operations of computers and hardware.

Difference between Multiprocessing and Multithreading
===============================================================================

Multiprocessing : A multiprocessing system has more than two processors. The CPUs are added to the system 
that helps to increase the computing speed of the system.

Multithreading: Multi-threaded applications are applications that have two or more threads that run concurrently. 

A multiprocessing system has more than two processors whereas Multithreading is a program execution technique that allows a single process to have multiple code segments

Multiprocessing helps you to increase computing power whereas multithreading helps you create computing threads of a single process

Thread
===============================================================================

A thread is a path of execution within a process. A process can contain multiple threads.
