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
    bool addStudent(std::string name,
                    std::string lastname,
                    std::string address,
                    std::string& city,
                    std::string& birthday,
                    std::string& pesel,
                    Gender gender,
                    const std::string& indexNumber,
                    const std::string& faculty,
                    const std::string& fieldOfStudy,
                    int currentSemester);
    std::shared_ptr<Student> findStudent(const std::string& key);
    bool editStudent(const std::string& oldData, const std::string& newData);

//private:
    std::vector<std::shared_ptr<Student>> students_ = {};
    std::unordered_map<std::string, std::shared_ptr<Student>> PeselMap_ = {};
    std::unordered_map<std::string, std::shared_ptr<Student>> IndexMap_ = {};
};


#endif //UNIVERSITY_STUDENTS_DATABASE_DATABASE_H
