.. contents::
   :local:
   :depth: 3
   
JAVA

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

