
.. contents::
   :local:
   :depth: 3
   
   
Word Split
===============================================================================

.. image:: https://github.com/Love4684/Data-Structures-and-Algorithms/blob/master/JAVA/Coderbyte/wordsplit.png


.. code:: JAVA

      import java.io.*;
      import java.util.*;
      import java.util.stream.Collectors;
      class JavaProgramming
      {
       public static String arrayChallenge(String[] strArr) {

          String wordToSplit = strArr[0];
          Set<String> dictionaryWords = Arrays.stream(strArr[1].split(",")).collect(Collectors.toSet());

          for (int i = wordToSplit.length() - 1; i > 0; i--) {
              String firstWord = wordToSplit.substring(0, i);
              String lastWord = wordToSplit.substring(i);

              if (dictionaryWords.contains(firstWord) && dictionaryWords.contains(lastWord)) {
                  return firstWord + "," + lastWord;
              }
          }
          return "not possible";
      }
      public static void main(String args[])
      {
          String arr[] = { "baseball", "a,all,b,ball,bas,base,cat,code,d,e,quit,z"};
          System.out.println(arrayChallenge(arr));
      }
      }


