#include "Student.h"

#include <string>
#include <utility>

Student::Student(std::string name,
                 std::string lastName,
                 std::string address,
                 std::string city,
                 std::string birthday,
                 std::string pesel,
                 Gender gender,
                 std::string indexNumber,
                 std::string faculty,
                 std::string fieldOfStudy,
                 int currentSemester)
    : name_(std::move(name))
    , lastName_(std::move(lastName))
    , address_(std::move(address))
    , city_(std::move(city))
    , birthday_(std::move(birthday))
    , pesel_(std::move(pesel))
    , gender_(gender)
    , indexNumber_(std::move(indexNumber))
    , faculty_(std::move(faculty))
    , fieldOfStudy_(std::move(fieldOfStudy))
    , currentSemester_(currentSemester)
{}

std::string Student::getName() {
    return name_;
}

std::string Student::getLastName() {
    return lastName_;
}

std::string Student::getAddress() {
    return address_;
}

std::string Student::getCity() {
    return city_;
}

std::string Student::getBirthday() {
    return birthday_;
}

std::string Student::getPesel() {
    return pesel_;
}

std::string Student::getGender() {
    switch (gender_) {
        case Gender::Male: {return "Male";}
        case Gender::Female: {return "Female";}
        case Gender::Other: {return "Other";}
    }
}

std::string Student::getIndexNumber() {
    return indexNumber_;
}

std::string Student::getFaculty() {
    return faculty_;
}

std::string Student::getFieldOfStudy() {
    return fieldOfStudy_;
}

std::string Student::getCurrentSemester() const {
    return std::to_string(currentSemester_);
}

std::string Student::toString() {
    return name_ + " " + lastName_ + " " + pesel_ + " " + birthday_+ " " + getGender() + "\n" +
           address_ + " " + city_ + "\n" +
           indexNumber_ + " " + faculty_ + " " + fieldOfStudy_ + " " + std::to_string(currentSemester_);
}