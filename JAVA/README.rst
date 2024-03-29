
.. contents::
   :local:
   :depth: 3
   


Find Second largest element in an array
------------

.. code:: java


   import java.io.*;
   import java.util.*;

   class JavaProgramming {
         static int print2largest(int arr[], int n) {
            int i, first, second;
         first = second = Integer.MIN_VALUE;
         for (i = 0; i < n; i++) {
            if (arr[i] > first) {
               second = first;
               first = arr[i];
            }
            else if (arr[i] > second && arr[i] != first)
               second = arr[i];
         }
         if (second == Integer.MIN_VALUE)
            return -1;
         else
            return second;
       }

      public static void main(String[] args)
      {
         int arr[] = { 12, 35, 1, 10, 34, 1 };
         int n = arr.length;
         System.out.print(print2largest(arr, n));
      }
   }

Find the first repeated word in a string
------------

.. code:: java

      import java.util.HashMap;
      import java.util.Map;
      public class Main {
          public static String firstRepeatedWord(String sentence)
          {
              String[] lis = sentence.split(" ");
              Map<String, Integer> frequency = new HashMap<>();
              for (int i = 0; i < lis.length; i++)
              {
                  String word = lis[i];
                  if (!frequency.containsKey(word))
                  {
                      frequency.put(word, 1);
                  }
                  else
                  {
                      return word;
                  }
              }

              return "No repeated word found";
          }
          public static void main(String[] args) {
              String sentence = "hello hello word word hello";
              System.out.println(firstRepeatedWord(sentence));
          }
      }
