//
// Created by Rad on 24.08.2023.
//

#ifndef UNIVERSITY_STUDENTS_DATABASE_DATABASE_H
#define UNIVERSITY_STUDENTS_DATABASE_DATABASE_H

#include "Student.h"

#include <vector>


class Database {
public:
    //Database();
    bool addStudent(Student& student);
    std::string findStudent(const std::string& pesel);
    bool editStudent(std::string oldData, std::string newData);
private:
    std::vector<Student> students_ = {};
};


#endif //UNIVERSITY_STUDENTS_DATABASE_DATABASE_H
