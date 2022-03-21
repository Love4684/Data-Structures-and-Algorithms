
.. contents::
   :local:
   :depth: 3
   
Variables JavaScript
===============================================================================

.. code:: JavaScript

    var variableName = "Variable-Value;"
    let variableName = "Variable-Value;"  //accessible locally and it is changeable
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
