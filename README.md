# University_Students_Database
Database project developed using the Scrum methodology, incorporating GoogleTest and TDD in the process.
[TODO: Finish the description, add images]

# Student
This class represents a student in the database. It contains the following attributes:
- name
- lastname
- address
- city
- PESEL (personal identification number: unique 11 digits)
- gender (Male/Female/Other)
- index number (student identification number: unique 6 digits)
- faculty
- field of study
- current semester

# Database
Database is protected with loging system. To log in, you need to provide a username and a password. If you don't have an account, admin have to create you one. The database is stored in a file, so it is possible to save the changes and load them later. The database functionalities differ depending on the user's permissions.

# User
Regular user have access to the following functionalities:
- add a student
- edit a student
- find a student
- save database/query to file
- open database/query from file
- make new query
- show query

# Admin
Admin have additonal functionalities:
- delete a student
- add a user

# Tests
Tests are performed using GoogleTest. They are divided into two categories: unit tests and integration tests. Unit tests are performed on individual methods, while integration tests are performed on the entire class.

# How to work with the database?

## 1. Log in
## 2. Choose the option you want to use
## 3. Follow the instructions