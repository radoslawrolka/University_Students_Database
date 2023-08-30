#ifndef UNIVERSITY_STUDENTS_DATABASE_USERCLIENT_H
#define UNIVERSITY_STUDENTS_DATABASE_USERCLIENT_H

#include "Database.h"
#include "Student.h"

#include <iostream>

class UserClient {
public:
    virtual void run();
    ~UserClient() = default;
//private:
    Database database_;
    virtual void showMenu();
    virtual bool addStudent();
    virtual bool editStudent();
    virtual bool findStudent();
    virtual bool saveToFile();
    //virtual bool openFromFile();
};

#endif //UNIVERSITY_STUDENTS_DATABASE_USERCLIENT_H
