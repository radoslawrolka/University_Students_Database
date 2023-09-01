#ifndef UNIVERSITY_STUDENTS_DATABASE_DATABASE_H
#define UNIVERSITY_STUDENTS_DATABASE_DATABASE_H

#include "Student.h"
#include "Display.h"

#include <vector>
#include <memory>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <windows.h>
#include <cstdlib>

class Database {
public:
    //Database();
    bool addStudent(const std::string& name,
                    const std::string& lastname,
                    const std::string& address,
                    const std::string& city,
                    const std::string& birthday,
                    const std::string& pesel,
                    const std::string& gender,
                    const std::string& indexNumber,
                    const std::string& faculty,
                    const std::string& fieldOfStudy,
                    const std::string& currentSemester);
    std::shared_ptr<Student> findStudent(const std::string& key);
    bool removeStudent(const std::string& key);
    bool saveToFile(const std::string& filename);
    bool openFromFile(const std::string& filename);
    bool newQuery(const std::string data[9]);
    bool showQuery();
    ~Database();
private:
    HANDLE hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    std::vector<std::shared_ptr<Student>> students_ = {};
    std::vector<std::shared_ptr<Student>> query_ = {};
    std::unordered_map<std::string, std::shared_ptr<Student>> PeselMap_ = {};
    std::unordered_map<std::string, std::shared_ptr<Student>> IndexMap_ = {};
    std::fstream file;
};


#endif //UNIVERSITY_STUDENTS_DATABASE_DATABASE_H
