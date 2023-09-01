# University_Students_Database
Database project developed using the Scrum methodology, incorporating GoogleTest and TDD in the process.

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

### 1. Log in
Users credentials are stored in a file ```/resources/login.password```. If you don't have an account, admin have to create you one.
<img src="images/login.png">
### 2. Choose the action
Pay attention that some actions are available only for admin.

<img src="images/user_menu.png"> <img src="images/admin_menu.png">

# Functionalities

### 1. Add a student
<img src="images/add_Student.png">

### 2. Edit a student
<img src="images/edit_Student.png">

### 3. Find a student
<img src="images/find_Student.png"> <img src="images/find_Student_error.png">

### 4. Delete a student [admin]
<img src="images/delete_Student.png">

### 5. Save database/query to file
<img src="images/save_to_file.png">

### 6. Open database/query from file
<img src="images/load_from_file.png">
<img src="images/load_from_file_error_1.png">
<img src="images/load_from_file_error_2.png">

### 7. Make new query
<img src="images/make_query.png"> <img src="images/make_query_empty.png">

### 8. Show query
<img src="images/show_query.png">

### 9. Add a user [admin]
<img src="images/add_user.png"> <img src="images/add_user_error.png">