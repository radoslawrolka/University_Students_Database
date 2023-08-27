//
// Created by Rad on 24.08.2023.
//

#ifndef UNIVERSITY_STUDENTS_DATABASE_DATABASE_H
#define UNIVERSITY_STUDENTS_DATABASE_DATABASE_H

#include "Student.h"

#include <vector>
#include <memory>
#include <unordered_map>

class Database {
public:
    //Database();
    bool addStudent(const std::string& name,
                    const std::string& lastname,
                    const std::string& address,
                    const std::string& city,
                    const std::string& birthday,
                    const std::string& pesel,
                    Gender gender,
                    const std::string& indexNumber,
                    const std::string& faculty,
                    const std::string& fieldOfStudy,
                    int currentSemester);
    std::shared_ptr<Student> findStudent(const std::string& key);
    bool removeStudent(const std::string& key);

//private:
    std::vector<std::shared_ptr<Student>> students_ = {};
    std::unordered_map<std::string, std::shared_ptr<Student>> PeselMap_ = {};
    std::unordered_map<std::string, std::shared_ptr<Student>> IndexMap_ = {};

};


#endif //UNIVERSITY_STUDENTS_DATABASE_DATABASE_H
