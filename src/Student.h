#ifndef UNIVERSITY_STUDENTS_DATABASE_STUDENT_H
#define UNIVERSITY_STUDENTS_DATABASE_STUDENT_H


#include <string>
enum Gender {
    Male,
    Female,
    Other
};

class Student {
public:
    Student(std::string name,
            std::string lastName,
            std::string address,
            std::string city,
            std::string birthday,
            std::string pesel,
            Gender gender,
            std::string indexNumber,
            std::string faculty,
            std::string fieldOfStudy,
            int currentSemester);
    std::string getName();
    std::string getLastName();
    std::string getAddress();
    std::string getCity();
    std::string getBirthday();
    std::string getPesel();
    std::string getGender();
    std::string getIndexNumber();
    std::string getFaculty();
    std::string getFieldOfStudy();
    [[nodiscard]] std::string getCurrentSemester() const;
private:
    std::string name_;
    std::string lastName_;
    std::string address_;
    std::string city_;
    std::string birthday_;
    std::string pesel_;
    Gender gender_;
    std::string indexNumber_;
    std::string faculty_;
    std::string fieldOfStudy_;
    int currentSemester_;
};


#endif //UNIVERSITY_STUDENTS_DATABASE_STUDENT_H