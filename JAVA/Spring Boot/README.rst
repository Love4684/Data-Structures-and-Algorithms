
.. contents::
   :local:
   :depth: 3
   
   
Project:
===============================================================================

.. code:: c++

      L1 l2 l3

      The time when inspection was booked (scheduled) needs to be shown on the CRM. 

      Inspection Type I1
      Inspection Status cancelled
      Date of Inspection 10-Jun-22
      Inspector Name
      Scheduled Time
      Start Time
      Inspection Completion Time

      Milestone:
      Reschedule Cancelled Inspection



.. code:: c++

      @Entity
      public class Product {
          @Id
          @GeneratedValue(strategy = GenerationType.AUTO)
          private Long productId;
          private String productImage;
          private String productTitle;
          private String productDescription;
          private Integer productPrice;
          private Date createdAt;
          private Date updatedAt;

      @PostMapping("/products")
      public ProductResponse createProduct(@Validated @RequestBody ProductForm productForm) {
          Product product = productForm.asProduct();
          Product createdProduct = productRepository.save(product);
          return new ProductResponse(createdProduct, "Product created");
      }

      @MappedSuperclass
      @EntityListeners(AuditingEntityListener.class)
      public abstract class DateAudit implements Serializable {
          @CreatedDate
          @Column(name = "created_at", nullable = false, updatable = false)
          private Date createdAt;

          @LastModifiedDate
          @Column(name = "updated_at")
          private LocalDateTime updatedAt;
      }
    
    

   
JAVA:
===============================================================================

Encapsulation in Java
===============================================================================

Encapsulation in Java is a process of wrapping code and data together into a single unit

Advantages:

It provides you the control over the data. Suppose you want to set the value of id which should be greater than 100 only, you can write the logic inside the setter method. You can write the logic not to store the negative numbers in the setter methods.

It is a way to achieve data hiding in Java because other class will not be able to access the data through the private data members.

By providing only a setter or getter method, you can make the class read-only or write-only. In other words, you can skip the getter or setter methods.

Convert in Singleton and immutable class
===============================================================================

.. code:: c++

    public class Employee {
        Long id;
        String name;
        Date dateOfBirth;

        public Long getId() {
            return id;
        }
        public void setId(Long id) {
            this.id = id;
        }

        public String getName() {
            return name;
        }
        public void setName(String name) {
            this.name = name;
        }

        public Date getDateOfBirth() {
            return dateOfBirth;
        }
        public void setDateOfBirth(Date dateOfBirth) {
            this.dateOfBirth = dateOfBirth;
        }
    }

JPA Transient Annotation
===============================================================================  

@Transient annotation is used to mark a field to be transient for the mapping framework, which means the field marked with @Transient is ignored by mapping framework and the field not mapped to any database column (in RDBMS) or Document property (in NOSQL).


What is serializable interface
===============================================================================  

Serialization is the process of converting an object into a byte stream, which can be transmitted over a network or saved in a file, and later deserialized to recreate the object.

.. code:: c++

      import java.io.Serializable;

      public class MyClass implements Serializable {
          // class implementation
      }
      
HashMap Java 8 implementation
===============================================================================    

Java 8 introduced a new implementation of HashMap that uses a different data structure called a balanced tree (specifically, a red-black tree) to store key-value pairs within buckets, instead of linked lists.

Java 8 also introduced the method forEach in HashMap, which allows iterating over the key-value pairs using lambda expressions or method references, making it more convenient to perform operations on the elements.

Marker interface in Java
===============================================================================

In Java, a marker interface is an interface that does not declare any methods. 

Serializable: The Serializable interface is a marker interface in Java used to indicate that a class can be serialized. Classes that implement Serializable can be converted into a byte stream and written to a file or transmitted over a network.

Cloneable: The Cloneable interface is a marker interface that indicates that a class can be cloned using the clone() method. It allows objects to create a copy of themselves.
    
Explain about java8 features.
===============================================================================

forEach() method in Iterable interface

default and static methods in Interfaces

Functional Interfaces
------------

An Interface that contains exactly one abstract method is known as functional interface.

.. code:: c++

      @FunctionalInterface  
      interface sayable{  
          void say(String msg);  
      }  
      public class FunctionalInterfaceExample implements sayable{  
          public void say(String msg){  
              System.out.println(msg);  
          }  
          public static void main(String[] args) {  
              FunctionalInterfaceExample fie = new FunctionalInterfaceExample();  
              fie.say("Hello there");  
          }  
      }  


Lambda Expressions
------------

A lambda expression is a short block of code which takes in parameters and returns a value.

Syntax: parameter -> expression

.. code:: c++

      import java.util.*;  
      public class LambdaExpressionExample7{  
          public static void main(String[] args) {  

              List<String> list=new ArrayList<String>();  
              list.add("ankit");  
              list.add("mayank");  
              list.add("irfan");  
              list.add("jai");  

              list.forEach(  
                  (n)->System.out.println(n)  
              );  
          }  
      }  


Java Time API
------------

Java StringJoiner
------------

StringJoiner Example: Merge Two StringJoiner

.. code:: c++

      // importing StringJoiner class  
      import java.util.StringJoiner;  
      public class StringJoinerExample {  
          public static void main(String[] args) {  

              StringJoiner joinNames = new StringJoiner(",", "[", "]");   // passing comma(,) and square-brackets as delimiter   

              // Adding values to StringJoiner  
              joinNames.add("Rahul");  
              joinNames.add("Raju");  

              // Creating StringJoiner with :(colon) delimiter  
              StringJoiner joinNames2 = new StringJoiner(":", "[", "]");  // passing colon(:) and square-brackets as delimiter   

              // Adding values to StringJoiner  
              joinNames2.add("Peter");  
              joinNames2.add("Raheem");  

              // Merging two StringJoiner  
              StringJoiner merge = joinNames.merge(joinNames2);   
              System.out.println(merge);  
          }  
      }  



Copy Constructor
===============================================================================

A copy constructor is a member function that initializes an object using another object of the same class.

abstract & interface class
===============================================================================


abstract class
------------

Abstract class can have abstract and non-abstract methods.

Abstract class doesn't support multiple inheritance.

An abstract class can be extended using keyword "extends".

Abstract class can have final, non-final, static and non-static variables.


interface
------------

In simple words, Interface is a blueprint of the class. It contains static constants and abstract methods.

Interface supports multiple inheritance.

An interface can be implemented using keyword "implements".

The interface has only static and final variables.

It helps you to achieve loose coupling.

abstract and interface calss example
------------

.. code:: c++

      //Creating interface that has 4 methods  
      interface A{  
      void a();//bydefault, public and abstract  
      void b();  
      void c();  
      void d();  
      }  

      //Creating abstract class that provides the implementation of one method of A interface  
      abstract class B implements A{  
      public void c(){System.out.println("I am C");}  
      }  

      //Creating subclass of abstract class, now we need to provide the implementation of rest of the methods  
      class M extends B{  
      public void a(){System.out.println("I am a");}  
      public void b(){System.out.println("I am b");}  
      public void d(){System.out.println("I am d");}  
      }  

      //Creating a test class that calls the methods of A interface  
      class Test5{  
      public static void main(String args[]){  
      A a=new M();  
      a.a();  
      a.b();  
      a.c();  
      a.d();  
      }}  
      
Exemple 2

.. code:: c++


      // Java program to demonstrate How Diamond Problem
      // Is Handled in case of Default Methods

      // Interface 1
      interface GPI {

         // Default method
         default void show()
         {

            // Print statement
            System.out.println("Default GPI");
         }
      }

      // Interface 2
      // Extending the above interface
      interface PI1 extends GPI {
      }

      // Interface 3
      // Extending the above interface
      interface PI2 extends GPI {
      }

      // Main class
      // Implementation class code
      class TestClass implements PI1, PI2 {

         // Main driver method
         public static void main(String args[])
         {

            // Creating object of this class
            // in main() method
            TestClass d = new TestClass();

            // Now calling the function defined in interface 1
            // from whom Interface 2and 3 are deriving
            d.show();
         }
      }





Shallow & Deep Copy
===============================================================================



Object Cloning in Java
===============================================================================

The object cloning is a way to create exact copy of an object. The clone() method of Object class is used to clone an object.

The java.lang.Cloneable interface must be implemented by the class whose object clone we want to create. If we don't implement Cloneable interface, clone() method generates CloneNotSupportedException.

Java Garbage Collection
===============================================================================

In java, garbage means unreferenced objects. In other words, it is a way to destroy the unused objects.

in java it is performed automatically. So, java provides better memory management.

Mutable in Java
===============================================================================

We can change the value of mutable objects after initialization.

It supports get() and set() methods to dela with the object.

Immutable in Java
------------

Once an immutable object is initiated; We can not change its values.

It only supports get() method to pass the value of the object.

The essentials for creating an immutable class are final class, private fields, final mutable objects.

Detail discussion on Collections.
===============================================================================

Array vs ArrayList in Java
===============================================================================

Array is a fixed length data structure whereas ArrayList is a variable length Collection class.

We cannot change length of array once created in Java but ArrayList can be changed.

We cannot store primitives in ArrayList, it can only store objects. But array can contain both primitives and objects in Java.


.. code:: c++

      // Array
      import java.util.Scanner;   
      public class ArrayInputExample2  
      {   
      public static void main(String args[])   
      {   
      int m, n, i, j;   
      Scanner sc=new Scanner(System.in);   
      System.out.print("Enter the number of rows: ");   
      //taking row as input  
      m = sc.nextInt();   
      System.out.print("Enter the number of columns: ");   
      //taking column as input  
      n = sc.nextInt();   
      // Declaring the two-dimensional matrix   
      int array[][] = new int[m][n];   
      // Read the matrix values   
      System.out.println("Enter the elements of the array: ");   
      //loop for row  
      for (i = 0; i < m; i++)   
      //inner for loop for column  
      for (j = 0; j < n; j++)   
      array[i][j] = sc.nextInt();   
      //accessing array elements   
      System.out.println("Elements of the array are: ");   
      for (i = 0; i < m; i++)   
      {   
      for (j = 0; j < n; j++)   
      //prints the array elements  
      System.out.print(array[i][j] + " ");   
      //throws the cursor to the next line  
      System.out.println();   
      }   
      }   
      }  

      // ArrayList

      // Java Program to Change elements in ArrayList

      // Importing all utility classes
      import java.util.*;

      // main class
      class GFG {

         // Main driver method
         public static void main(String args[])
         {
            // Creating an Arraylist object of string type
            ArrayList<String> al = new ArrayList<>();

            // Adding elements to Arraylist
            // Custom input elements
            al.add("Geeks");
            al.add("Geeks");

            // Adding specifying the index to be added
            al.add(1, "Geeks");

            // Printing the Arraylist elements
            System.out.println("Initial ArrayList " + al);

            // Setting element at 1st index
            al.set(1, "For");

            // Printing the updated Arraylist
            System.out.println("Updated ArrayList " + al);
         }
      }


HashMap, LinkedHashMap and TreeMap
===============================================================================

HashMap Internal Working.
------------

It uses an array and LinkedList data structure internally for storing Key and Value.

HashMap is faster than TreeMap because it provides constant-time performance that is O(1) for the basic operations like get() and put().

.. code:: c++

      // Java Program to illustrate the Hashmap Class

      // Importing required classes
      import java.util.*;

      // Main class
      public class GFG {

         // Main driver method
         public static void main(String[] args)
         {

            // Creating an empty HashMap
            Map<String, Integer> map = new HashMap<>();

            // Inserting entries in the Map
            // using put() method
            map.put("vishal", 10);
            map.put("sachin", 30);
            map.put("vaibhav", 20);

            // Iterating over Map
            for (Map.Entry<String, Integer> e : map.entrySet())

               // Printing key-value pairs
               System.out.println(e.getKey() + " "
                           + e.getValue());
         }
      }


Set in Java
------------

.. code:: c++

      // Java Program Demonstrating Operations on the Set
      // such as Union, Intersection and Difference operations

      // Importing all utility classes
      import java.util.*;

      // Main class
      public class SetExample {

         // Main driver method
         public static void main(String args[])
         {
            // Creating an object of Set class
            // Declaring object of Integer type
            Set<Integer> a = new HashSet<Integer>();

            // Adding all elements to List
            a.addAll(Arrays.asList(
               new Integer[] { 1, 3, 2, 4, 8, 9, 0 }));

         // Again declaring object of Set class
         // with reference to HashSet
            Set<Integer> b = new HashSet<Integer>();

         b.addAll(Arrays.asList(
               new Integer[] { 1, 3, 7, 5, 4, 0, 7, 5 }));


            // To find union
            Set<Integer> union = new HashSet<Integer>(a);
            union.addAll(b);
            System.out.print("Union of the two Set");
            System.out.println(union);

            // To find intersection
            Set<Integer> intersection = new HashSet<Integer>(a);
            intersection.retainAll(b);
            System.out.print("Intersection of the two Set");
            System.out.println(intersection);

            // To find the symmetric difference
            Set<Integer> difference = new HashSet<Integer>(a);
            difference.removeAll(b);
            System.out.print("Difference of the two Set");
            System.out.println(difference);
         }
      }


Java 8 Stream API
===============================================================================

Java Stream Example: Find Max and Min Product Price

.. code:: c++

      import java.util.*;    
      class Product{    
          int id;    
          String name;    
          float price;    
          public Product(int id, String name, float price) {    
              this.id = id;    
              this.name = name;    
              this.price = price;    
          }    
      }    
      public class JavaStreamExample {    
          public static void main(String[] args) {    
              List<Product> productsList = new ArrayList<Product>();    
              //Adding Products    
              productsList.add(new Product(1,"HP Laptop",25000f));    
              productsList.add(new Product(2,"Dell Laptop",30000f));    
              productsList.add(new Product(3,"Lenevo Laptop",28000f));    
              productsList.add(new Product(4,"Sony Laptop",28000f));    
              productsList.add(new Product(5,"Apple Laptop",90000f));    
              // max() method to get max Product price     
              Product productA = productsList.stream().max((product1, product2)->product1.price > product2.price ? 1: -1).get();    
              System.out.println(productA.price);    
              // min() method to get min Product price    
              Product productB = productsList.stream().min((product1, product2)->product1.price > product2.price ? 1: -1).get();    
              System.out.println(productB.price);    

          }    
      }    


operating system
===============================================================================

.. code:: c++


      The operating system is a software program that facilitates computer hardware to communicate and operate with the 
      computer software. It is the most important part of a computer system without it computer is just like a box.

process
------------

.. code:: c++

      An executing program is known as process.
      For example, a Web Browser is a process, a shell (or command prompt) is a process.

      1. Start : This is the initial state when a process is first started/created.
      2. Ready : The process is waiting to be assigned to a processor.
      3. Runing : The process is chosen by CPU for execution.
      4. Waiting : Process moves into the waiting state if it needs to wait for a resource.
      5. Completion or termination : When a process finishes its execution, it comes in the termination state.

kernel
------------

.. code:: c++


      A kernel is the central component of an operating system that manages the operations of computers and hardware.

Difference between Multiprocessing and Multithreading
------------

Multiprocessing : A multiprocessing system has more than two processors. The CPUs are added to the system 
that helps to increase the computing speed of the system.

Multithreading: Multi-threaded applications are applications that have two or more threads that run concurrently. 

A multiprocessing system has more than two processors whereas Multithreading is a program execution technique that allows a single process to have multiple code segments

Multiprocessing helps you to increase computing power whereas multithreading helps you create computing threads of a single process

Thread
------------

A thread is a path of execution within a process. A process can contain multiple threads.


Multithreading
===============================================================================


It is a process of executing multiple threads simultaneously.

Threads can be created by using two mechanisms : 

Extending the Thread class 

.. code:: c++

      // Java code for thread creation by extending
      // the Thread class
      class MultithreadingDemo extends Thread {
         public void run()
         {
            try {
               // Displaying the thread that is running
               System.out.println(
                  "Thread " + Thread.currentThread().getId()
                  + " is running");
            }
            catch (Exception e) {
               // Throwing an exception
               System.out.println("Exception is caught");
            }
         }
      }

      // Main Class
      public class Multithread {
         public static void main(String[] args)
         {
            int n = 8; // Number of threads
            for (int i = 0; i < n; i++) {
               MultithreadingDemo object
                  = new MultithreadingDemo();
               object.start();
            }
         }
      }


Implementing the Runnable Interface

.. code:: c++

      // Java code for thread creation by implementing
      // the Runnable Interface
      class MultithreadingDemo implements Runnable {
         public void run()
         {
            try {
               // Displaying the thread that is running
               System.out.println(
                  "Thread " + Thread.currentThread().getId()
                  + " is running");
            }
            catch (Exception e) {
               // Throwing an exception
               System.out.println("Exception is caught");
            }
         }
      }

      // Main Class
      class Multithread {
         public static void main(String[] args)
         {
            int n = 8; // Number of threads
            for (int i = 0; i < n; i++) {
               Thread object
                  = new Thread(new MultithreadingDemo());
               object.start();
            }
         }
      }
      
What is the ExecutorService interface?
------------

synchronized
------------


Serialization
===============================================================================

Serialization in Java is a mechanism of writing the state of an object into a byte-stream.

For serializing the object, we call the writeObject() method of ObjectOutputStream class.



Spring Boot:
===============================================================================


Spring Boot Auto-configuration
------------

Spring Boot auto-configuration automatically configures the Spring application based on the jar dependencies that we have added.

Autowiring in Spring
------------

Spring bean:
------------

In Spring, the objects are the backbone of our application,

an instance of a class managed by the Spring IoC container are called beans.

Spring (IoC) Container: the core part of Spring that is responsible for managing all the beans

Bean Scopes
------------

singleton

prototype

request

session

global-session

Difference Between @Controller and @RestController 
------------

@Controller is used to mark classes as Spring MVC Controller.

@RestController is a convenience annotation that does nothing more than adding the @Controller and @ResponseBody annotations

.. code:: c++

      @Controller
      @ResponseBody
      public class MyController { }

      @RestController
      public class MyRestController { }

DispatcherServlet
------------

The DispatcherServlet is the front controller in Spring web applications. It's used to create web applications and REST services in Spring MVC. In a traditional Spring web application, this servlet is defined in the web.xml file.

DispatcherServlet receives all of the HTTP requests and delegates them to controller classes.


Spring Dependency Injection
------------

Dependency Injection is a fundamental aspect of the Spring framework, through which the Spring container “injects” objects into other objects or “dependencies”.

Spring framework provides two ways to inject dependency

By Constructor

By Setter method

Types of controller in web MVC i.e
------------

1. Basic Controller
2. Simple Form Controller
3. Multi Action Controller
4. Wizard Form Controller
5. Abstract Command Controller

Spring Boot to the database using JPA
------------

Spring Boot provides spring-boot-starter-data-jpa starter to connect Spring application with relational database efficiently.

we can use it into project POM (Project Object Model) file.

CRUD Operations Using Hibernate
------------

.. code:: c++
