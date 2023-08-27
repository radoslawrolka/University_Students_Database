//
// Created by Rad on 24.08.2023.
//

#include "Database.h"

#include <memory>
#include <iostream>

bool Database::addStudent(const std::string& name,
                          const std::string& lastname,
                          const std::string& address,
                          const std::string& city,
                          const std::string& birthday,
                          const std::string& pesel,
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

bool Database::removeStudent(const std::string& key) {
    if (key.length() == 11) {
        Student* student = PeselMap_[key].get();
        if (student) {
            PeselMap_.erase(key);
            IndexMap_.erase(student->getIndexNumber());
            for (auto it = students_.begin(); it != students_.end(); ++it) {
                if (it->get() == student) {
                    students_.erase(it);
                    return true;
                }
            }
        }
        return false;
    }
    else {
        Student* student = IndexMap_[key].get();
        if (student) {
            IndexMap_.erase(key);
            PeselMap_.erase(student->getPesel());
            for (auto it = students_.begin(); it != students_.end(); ++it) {
                if (it->get() == student) {
                    students_.erase(it);
                    return true;
                }
            }
        }
        return false;
    }
}