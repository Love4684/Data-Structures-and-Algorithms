
.. contents::
   :local:
   :depth: 3

Indexing
===============================================================================

Indexes allow the database application to find data fast; without reading the whole table

primary Index
----------------

If the index is based on the primary key, it is called the primary index.

Secondary Index
-------------

The secondary index is an index type that helps to reduce the size of mapping by introducing another level of indexing.

At the initial stage, it selects a range for the columns. Therefore, the mapping size of the first level becomes smaller.

Conclusion    
-----------

The main difference between primary and secondary index is that the primary index is an index on a set of fields that 

includes the primary key for the field and does not contain duplicates, while the secondary index is an index that is not 

a primary index and which can contain duplicates.

.. code:: SQL

      CREATE INDEX index_name
      on table_name (column1, column2);

SQL Injection
===============================================================================

SQL injection is one of the most common web hacking techniques.

.. code:: SQL

   SELECT UserId, Name, Password FROM Users WHERE UserId = 105 or 1=1;
   
A hacker might get access to all the user names and passwords in a database, by simply inserting 105 OR 1=1 into the input field.


DELETE command and TRUNCATE command
===============================================================================

DELETE command: DELETE command is used to delete rows from a table based on the condition that we provide in a WHERE clause.

TRUNCATE command: TRUNCATE command is used to remove all rows (complete data) from a table. It is similar to the DELETE command with no WHERE clause.

database languages
===============================================================================

Data Definition Language (DDL) e.g., CREATE, ALTER, DROP, TRUNCATE, RENAME, etc. All these commands are used for updating the data that?s why they are known as Data Definition Language.

Data Manipulation Language (DML) e.g., SELECT, UPDATE, INSERT, DELETE, etc. These commands are used for the manipulation of already updated data that's why they are the part of Data Manipulation Language.

DATA Control Language (DCL) e.g., GRANT and REVOKE. These commands are used for giving and removing the user access on the database. So, they are the part of Data Control Language.

Transaction Control Language (TCL) e.g., COMMIT, ROLLBACK, and SAVEPOINT. These are the commands used for managing transactions in the database. TCL is used for managing the changes made by DML.

Key
===============================================================================

Primary key: The Primary key is an attribute in a table that can uniquely identify each record in a table. It is compulsory for every table.

Candidate key: The Candidate key is an attribute or set of an attribute which can uniquely identify a tuple. The Primary key can be selected from these attributes.

Super key: The Super key is a set of attributes which can uniquely identify a tuple. Super key is a superset of the candidate key.

Foreign key: The Foreign key is a primary key from one table, which has a relationship with another table. It acts as a cross-reference between tables.

LIMIT
===============================================================================

MySQL supports the LIMIT clause to select a limited number of records

.. code:: SQL

      SELECT column_name(s)
      FROM table_name
      WHERE condition
      LIMIT number;

B-Tree
===============================================================================

Following is an example of B-Tree of minimum order 5.

.. image:: https://github.com/Love4684/Machine-Learning/blob/master/DBMS/media/output253.png

 
The B+ tree is a balanced binary search tree. It follows a multi-level index format

Transaction property(ACID properties)
===============================================================================

The transaction has the four properties. These are used to maintain consistency in a database, before and after the transaction.

Atomicity : It states that all operations of the transaction take place at once if not, the transaction is aborted.

Consistency : The integrity constraints are maintained so that the database is consistent before and after the transaction.

Isolation : It shows that the data which is used at the time of execution of a transaction cannot be used by the second transaction until the first one is completed.

Durability : The durability property is used to indicate the performance of the database's consistent state. It states that the transaction made the permanent changes.

Normalization
===============================================================================

Normalization is the process of minimizing redundancy from a relation or set of relations.
Redundancy in relation may cause insertion, deletion and updation anomalies. So, it helps to minimize the redundancy in relations.

.. code:: SQL


      1NF	A relation is in 1NF if it contains an atomic value.
      2NF	A relation will be in 2NF if it is in 1NF and all non-key attributes are fully functional dependent on the primary key.
      3NF	A relation will be in 3NF if it is in 2NF and no transition dependency exists.
      4NF	A relation will be in 4NF if it is in Boyce Codd normal form and has no multi-valued dependency.
      5NF	A relation is in 5NF if it is in 4NF and not contains any join dependency and joining should be lossless.


DELETE
===============================================================================

The DELETE statement is used to delete existing records in a table.

.. code:: SQL

   DELETE FROM Customers WHERE CustomerName='Alfreds Futterkiste'; 
   
GROUP BY
===============================================================================

The GROUP BY statement groups rows that have the same values into summary rows, like "find the number of customers in each country".

.. code:: SQL

      SELECT COUNT(CustomerID), Country
      FROM Customers
      GROUP BY Country;
      
HAVING
===============================================================================      

The HAVING clause was added to SQL because the WHERE keyword cannot be used with aggregate functions.

.. code:: SQL

      SELECT COUNT(CustomerID), Country
      FROM Customers
      GROUP BY Country
      HAVING COUNT(CustomerID) > 5;
   

CREATE TABLE - Count the Number of Rows
===============================================================================

.. code:: SQL

      CREATE TABLE geeks(
          id int(20) , 
          name varchar(200));

      INSERT INTO geeks(id,name) values(1,'nikhil');
      INSERT INTO geeks(id,name) values(2,'kartik');

      SELECT COUNT(id) as id_count FROM geeks

SQL query to find second highest salary?
===============================================================================

.. code:: SQL

    select FirstName, max(Salary) from employees
    where Salary not in (select max(Salary) from employees)
    
    or
    
    select FirstName, max(Salary) from employees 
    where Salary < (select max(Salary) from employees)

SQL query to find Nth highest salary?
===============================================================================

.. code:: SQL

      SELECT name, salary 
      FROM #Employee e1 
      WHERE N-1 = (SELECT COUNT(DISTINCT salary) FROM #Employee e2 
      WHERE e2.salary > e1.salary)


SQL Query to Find the Highest Salary of Each Department
===============================================================================

`Geeks <https://www.geeksforgeeks.org/sql-query-to-find-the-highest-salary-of-each-department/>`_

.. code:: SQL

      SELECT DEPT_ID, MAX(SALARY) FROM department GROUP BY DEPT_ID;

How to get the alternate rows or records from table in sql server
===============================================================================

.. code:: SQL

      select ID, NAME from department where mod(ID, 2) = 0;
      
      
Find Duplicate Values in a SQL 
===============================================================================

.. code:: SQL

      SELECT username, email, COUNT(*)
      FROM users
      GROUP BY username, email
      HAVING COUNT(*) > 1
      

`group by on two tables and apply aggregate functions (blood req) <https://onecompiler.com/mysql/3xebztaqv>`_
===============================================================================

.. code:: SQL      

      /*
      Question 1 : 
      There is a blood bank which maintains two tables

      Donor: the people who are willing to donate blood
      Acceptor: the people who are in need of blood.
      Bank needs to query their database and get the blood groups whose total amount
      that donors can give is less than the total amount of blood the acceptors need.

      */
      create table donor(id int,name varchar(255),amount int, bg varchar(5));
      create table acceptor(id int,name varchar(255),amount int, bg varchar(5));

      insert into donor values(1,'pallavi',50,'A');
      insert into donor values(2,'El',20,'AB');
      insert into donor values(3,'Shinchan',100,'AB');

      insert into acceptor values(1,'monika',80,'A');
      insert into acceptor values(2,'Phoebe',10,'AB');
      insert into acceptor values(3,'damon',500,'B');

      select * from donor;
      select * from acceptor;

      select a.bg, a.acceptor_amount - COALESCE(b.donor_amount,0) as BloodNeeded
      from
      (
          select bg,sum(amount) as acceptor_amount from acceptor
          group by bg
      )a
      left join
      (
          select bg,sum(amount) as donor_amount from donor
          group by bg
      )b
      on a.bg = b.bg
      where (a.acceptor_amount - COALESCE(b.donor_amount,0)) > 0
      
      --output
      id	name	amount	bg
      1	pallavi	50	A
      2	El	20	AB
      3	Shinchan	100	AB
      id	name	amount	bg
      1	monika	80	A
      2	Phoebe	10	AB
      3	damon	500	B
      bg	BloodNeeded
      A	30
      B	500
      
