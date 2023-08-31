#ifndef UNIVERSITY_STUDENTS_DATABASE_USERCLIENT_H
#define UNIVERSITY_STUDENTS_DATABASE_USERCLIENT_H

#include "Database.h"
#include "Student.h"

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <functional>

class UserClient {
public:
    virtual void run();
    ~UserClient() = default;
//private:
    HANDLE hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    Database database_;
    virtual void showMenu();
    virtual bool addStudent();
    virtual bool editStudent();
    virtual bool findStudent();
    virtual bool saveToFile();
    virtual bool openFromFile();
    virtual bool makeQuery();
};

#endif //UNIVERSITY_STUDENTS_DATABASE_USERCLIENT_H
