
.. contents::
   :local:
   :depth: 3
   
Spring Boot:
===============================================================================

Copy Constructor
------------

Shallow Copy
------------

Deep Copy
------------

Object Cloning in Java
------------

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


Spring Boot Auto-configuration
------------

Spring Boot auto-configuration automatically configures the Spring application based on the jar dependencies that we have added.


Difference Between @Controller and @RestController 
------------

DispatcherServlet
------------

The DispatcherServlet is the front controller in Spring web applications. It's used to create web applications and REST services in Spring MVC. In a traditional Spring web application, this servlet is defined in the web.xml file.

DispatcherServlet receives all of the HTTP requests and delegates them to controller classes.


Spring bean:
------------

an instance of a class managed by the Spring Container

Spring (IoC) Container: the core part of Spring that is responsible for managing all the beans

Types of controller in web MVC i.e
------------

1. Basic Controller
2. Simple Form Controller
3. Multi Action Controller
4. Wizard Form Controller
5. Abstract Command Controller



.. code:: c++
