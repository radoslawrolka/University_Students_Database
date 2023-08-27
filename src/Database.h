#ifndef UNIVERSITY_STUDENTS_DATABASE_DATABASE_H
#define UNIVERSITY_STUDENTS_DATABASE_DATABASE_H

#include "Student.h"

#include <vector>
#include <memory>
#include <unordered_map>
#include <fstream>

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
    ~Database();
//private:
    std::vector<std::shared_ptr<Student>> students_ = {};
    std::unordered_map<std::string, std::shared_ptr<Student>> PeselMap_ = {};
    std::unordered_map<std::string, std::shared_ptr<Student>> IndexMap_ = {};
    std::fstream file;
};


#endif //UNIVERSITY_STUDENTS_DATABASE_DATABASE_H
