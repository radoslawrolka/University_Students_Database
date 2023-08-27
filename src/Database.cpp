//
// Created by Rad on 24.08.2023.
//

#include "Database.h"

#include <memory>
#include <iostream>

bool Database::addStudent(std::string name,
                          std::string lastname,
                          std::string address,
                          std::string& city,
                          std::string& birthday,
                          std::string& pesel,
                          Gender gender,
                          const std::string& indexNumber,
                          const std::string& faculty,
                          const std::string& fieldOfStudy,
                          int currentSemester) {
    if (findStudent(pesel) || findStudent(indexNumber)) {
        return false;
    }
    else {
        students_.push_back(std::make_shared<Student>(name, lastname, address, city, birthday, pesel, gender, indexNumber, faculty, fieldOfStudy, currentSemester));
        PeselMap_[pesel] = students_.back();
        IndexMap_[indexNumber] = students_.back();
        return true;
    }
}

std::shared_ptr<Student> Database::findStudent(const std::string& key) {
    if (key.length() == 11) {
        return PeselMap_[key];
    } else {
        return IndexMap_[key];
    }
}

bool Database::editStudent(const std::string& oldData, const std::string& newData) {
    for (auto & i : students_) {
        if (i->getPesel() == oldData) {
            i->setPesel(newData);
            return true;
        }
    }
    return false;
}
