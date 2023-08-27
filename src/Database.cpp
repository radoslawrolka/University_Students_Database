#include "Database.h"

#include <memory>
#include <iostream>

Gender toGender(const std::string& gender) {
    if (gender == "Male") return Gender::Male;
    if (gender == "Female") return Gender::Female;
    return Gender::Other;
}

bool Database::addStudent(const std::string& name,
                          const std::string& lastname,
                          const std::string& address,
                          const std::string& city,
                          const std::string& birthday,
                          const std::string& pesel,
                          const std::string& gender,
                          const std::string& indexNumber,
                          const std::string& faculty,
                          const std::string& fieldOfStudy,
                          const std::string& currentSemester) {
    if (findStudent(pesel) || findStudent(indexNumber)) {
        return false;
    }
    else {
        Gender Ggender = toGender(gender);
        students_.push_back(std::make_shared<Student>(name, lastname, address, city, birthday, pesel, Ggender, indexNumber, faculty, fieldOfStudy, currentSemester));
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

bool Database::saveToFile(const std::string& filename) {
    file.open("../resources/"+filename, std::ios::out);
    if (file.is_open()) {
        file << "#Name;Lastname;Address;City;Birthday;Pesel;Gender;IndexNumber;Faculty;FieldOfStudy;CurrentSemester\n";
        for (auto& student : students_) {
            file << student->getName() << ";";
            file << student->getLastName() << ";";
            file << student->getAddress() << ";";
            file << student->getCity() << ";";
            file << student->getBirthday() << ";";
            file << student->getPesel() << ";";
            file << student->getGender() << ";";
            file << student->getIndexNumber() << ";";
            file << student->getFaculty() << ";";
            file << student->getFieldOfStudy() << ";";
            file << student->getCurrentSemester() << "\n";
        }
        file.close();
        return true;
    }
    else {
        return false;
    }
}

bool Database::openFromFile(const std::string &filename) {
    file.open("../resources/"+filename, std::ios::in);
    if (file.is_open()) {
        students_.clear();
        PeselMap_.clear();
        IndexMap_.clear();
        std::string line;
        std::string token[11];
        std::getline(file, line);
        while (std::getline(file, line)) {
            size_t pos = 0;
            int i = 0;
            while ((pos = line.find(';')) != std::string::npos) {
                token[i] = line.substr(0, pos);
                line.erase(0, pos + 1);
                i++;
            }
            addStudent(token[0], token[1], token[2], token[3], token[4], token[5], token[6], token[7], token[8], token[9], token[10]);
        }
        file.close();
        return true;
    }
    else {
        return false;
    }
}

