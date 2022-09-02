
.. contents::
   :local:
   :depth: 3
   
JAVA:
===============================================================================

Explain about java8 features.
------------

forEach() method in Iterable interface

default and static methods in Interfaces

Functional Interfaces and Lambda Expressions

Java Stream API for Bulk Data Operations on Collections

Java Time API

Collection API improvements

Concurrency API improvements

Java IO improvements

Copy Constructor
------------

A copy constructor is a member function that initializes an object using another object of the same class.

Shallow Copy
------------

Deep Copy
------------

Object Cloning in Java
------------

The object cloning is a way to create exact copy of an object. The clone() method of Object class is used to clone an object.

The java.lang.Cloneable interface must be implemented by the class whose object clone we want to create. If we don't implement Cloneable interface, clone() method generates CloneNotSupportedException.

Java Garbage Collection
------------

In java, garbage means unreferenced objects. In other words, it is a way to destroy the unused objects.

in java it is performed automatically. So, java provides better memory management.

Mutable in Java
------------

We can change the value of mutable objects after initialization.

It supports get() and set() methods to dela with the object.

Immutable in Java
------------

Once an immutable object is initiated; We can not change its values.

It only supports get() method to pass the value of the object.

The essentials for creating an immutable class are final class, private fields, final mutable objects.

Detail discussion on Collections.
------------

Array vs ArrayList in Java
------------

Array is a fixed length data structure whereas ArrayList is a variable length Collection class.

We cannot change length of array once created in Java but ArrayList can be changed.

We cannot store primitives in ArrayList, it can only store objects. But array can contain both primitives and objects in Java.

HashMap Internal Working.
------------

It uses an array and LinkedList data structure internally for storing Key and Value.

HashMap is faster than TreeMap because it provides constant-time performance that is O(1) for the basic operations like get() and put().

Java 8 Stream API
------------

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



Multithreading
------------

It is a process of executing multiple threads simultaneously.

Threads can be created by using two mechanisms : 

Extending the Thread class 

Implementing the Runnable Interface



Spring Boot:
===============================================================================


Spring Boot Auto-configuration
------------

Spring Boot auto-configuration automatically configures the Spring application based on the jar dependencies that we have added.

Spring bean:
------------

an instance of a class managed by the Spring Container

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

Types of controller in web MVC i.e
------------

1. Basic Controller
2. Simple Form Controller
3. Multi Action Controller
4. Wizard Form Controller
5. Abstract Command Controller


CRUD Operations Using Hibernate
------------

.. code:: c++
