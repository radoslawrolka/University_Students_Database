//
// Created by Rad on 24.08.2023.
//

#include "Database.h"

bool Database::addStudent(Student& student) {
    for (auto & i : students_) {
        if (i.getPesel() == student.getPesel()) {
            return false;
        }
    }
    students_.push_back(student);
    return true;
}

std::string Database::findStudent(const std::string& pesel) {
    for (auto & i : students_) {
        if (i.getPesel() == pesel) {
            return i.toString();
        }
    }
    return "Student not found";
}

bool Database::editStudent() {
    return false;
}