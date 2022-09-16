
.. contents::
   :local:
   :depth: 3
   
Variables in JavaScript
===============================================================================

.. code:: JavaScript

    var variableName = "Variable-Value;"   // function scoped
    let variableName = "Variable-Value;"  //accessible locally and it is changeable and block scoped
    const variableName = "Variable-Value;" //can’t be reassigned

    <script>
    if (true) {
        let geeks = "GeeksforGeeks";
        console.log(geeks);
        }

        /* This will be error and 
           show geeks is not defined */
        console.log(geeks);
    </script>

Functions in JavaScript
===============================================================================

Function Declaration: 
---------------

.. code:: JavaScript

   function add(a, b) {        
       console.log(a + b);
   }
   add(2, 3);

Function Expression:
---------------

.. code:: JavaScript

   const add = function(a, b) {
      console.log(a+b);
   }
   add(2, 3);

Arrow Functions:
---------------

.. code:: JavaScript

      const great = (a, b) => {
          if (a > b)
              return "a is greater";
          else
              return "b is greater";
      }
      console.log(great(3,5));

difference between the HTTP and HTTPS
--------------------------------

.. code:: JavaScript

      The major difference between the HTTP and HTTPS is the SSL(Secure Sockets Layer) certificate. The HTTPS protocol is an 
      extended version of the HTTP protocol with an additional feature of security.
      
API
===============================================================================

.. code:: JavaScript

   API is the acronym for Application Programming Interface, 
   which is a software intermediary that allows two applications to talk to each other.

The GET method
--------------- 

.. code:: JavaScript

      The GET method is used to retrieve data from the server. This is a read-only method, 
      so it has no risk of mutating or corrupting the data. For example, if we call the get 
      method on our API, we’ll get back a list of all to-dos.
      
The POST method
--------------- 

.. code:: JavaScript  

      The POST method sends data to the server and creates a new resource.

The PUT method
--------------- 

.. code:: JavaScript 

      The PUT method is most often used to update an existing resource.
      
The PATCH method
--------------- 

.. code:: JavaScript 

         The PATCH method is very similar to the PUT method because it also modifies an existing resource. 
         The difference is that for the PUT method, the request body contains the complete new version, 
         whereas for the PATCH method, the request body only needs to contain the specific changes to the resource, 
         specifically a set of instructions describing how that resource should be changed, and the API service will 
         create a new version according to that instruction.
         
The DELETE method
--------------- 

.. code:: JavaScript 

      The DELETE method is used to delete a resource specified by its URI.
         
         
      

      

