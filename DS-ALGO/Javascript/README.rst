
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

