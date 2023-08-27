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
                 std::string currentSemester)
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
    , currentSemester_(std::move(currentSemester))
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
        default: {return "Other";}
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
std::string Student::getCurrentSemester() {
    return currentSemester_;
}

void Student::setName(const std::string& name) {
    name_ = name;
}
void Student::setLastName(const std::string& lastName) {
    lastName_ = lastName;
}
void Student::setAddress(const std::string& address) {
    address_ = address;
}
void Student::setCity(const std::string& city) {
    city_ = city;
}
void Student::setBirthday(const std::string& birthday) {
    birthday_ = birthday;
}
void Student::setPesel(const std::string& pesel) {
    pesel_ = pesel;
}
void Student::setGender(Gender gender) {
    gender_ = gender;
}
void Student::setIndexNumber(const std::string& indexNumber) {
    indexNumber_ = indexNumber;
}
void Student::setFaculty(const std::string& faculty) {
    faculty_ = faculty;
}
void Student::setFieldOfStudy(const std::string& fieldOfStudy) {
    fieldOfStudy_ = fieldOfStudy;
}
void Student::setCurrentSemester(const std::string& currentSemester) {
    currentSemester_ = currentSemester;
}

std::string Student::toString() {
    return name_ + " " + lastName_ + " " + pesel_ + " " + birthday_+ " " + getGender() + "\n" +
           address_ + " " + city_ + "\n" +
           indexNumber_ + " " + faculty_ + " " + fieldOfStudy_ + " " + currentSemester_;
}