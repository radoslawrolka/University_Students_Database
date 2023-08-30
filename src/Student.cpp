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
    , getSetter{&Student::setName, &Student::setLastName, &Student::setAddress, &Student::setCity, &Student::setBirthday, &Student::setPesel, &Student::setGender, &Student::setIndexNumber, &Student::setFaculty, &Student::setFieldOfStudy, &Student::setCurrentSemester}
    , getGetter{&Student::getName, &Student::getLastName, &Student::getAddress, &Student::getCity, &Student::getBirthday, &Student::getPesel, &Student::getGender, &Student::getIndexNumber, &Student::getFaculty, &Student::getFieldOfStudy, &Student::getCurrentSemester}
    , settersName{"Name", "Lastname", "Address", "City", "Birthday", "PESEL", "Gender", "Index number", "Faculty", "Field of study", "Current semester"}
    , getValidator{&Student::valid, &Student::valid, &Student::valid, &Student::valid, &Student::validDate, &Student::validPesel, &Student::valid, &Student::validIndexNumber, &Student::valid, &Student::valid, &Student::valid}
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
void Student::setGender(const std::string& gender) {
    if (gender == "Male") {
        gender_ = Gender::Male;
    }
    else if (gender == "Female") {
    gender_ = Gender::Female;
    }
    else {
        gender_ = Gender::Other;
    }
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

bool Student::valid(const std::string& data) {
    return true;
}

bool Student::validDate(const std::string &date) {
    if (date.length() != 10) {
        return false;
    }
    if (date[4] != '-' || date[7] != '-') {
        return false;
    }
    if (date[0] != '1' && date[0] != '2') {
        return false;
    }
    if (date[0] == '1') {
        if (date[1] != '9') {
            return false;
        }
        if (date[2] < '5' || date[2] > '9') {
            return false;
        }
    }
    if (date[0] == '2') {
        if (date[1] != '0') {
            return false;
        }
        if (date[2] != '0' && date[2] != '1') {
            return false;
        }
    }
    if (date[5] != '0' && date[5] != '1') {
        return false;
    }
    if (date[5] == '0') {
        if (date[6] < '1' || date[6] > '9') {
            return false;
        }
    }
    if (date[5] == '1') {
        if (date[6] != '0' && date[6] != '1' && date[6] != '2') {
            return false;
        }
    }
    if (date[8] != '0' && date[8] != '1' && date[8] != '2' && date[8] != '3') {
        return false;
    }
    if (date[8] == '0') {
        if (date[9] < '1' || date[9] > '9') {
            return false;
        }
    }
    if (date[8] == '1') {
        if (date[9] < '0' || date[9] > '9') {
            return false;
        }
    }
    if (date[8] == '2') {
        if (date[9] < '0' || date[9] > '9') {
            return false;
        }
    }
    if (date[8] == '3') {
        if (date[9] != '0' && date[9] != '1') {
            return false;
        }
    }
    return true;
}

bool Student::validPesel(const std::string &data) {
    return data.length() == 11;
}

bool Student::validIndexNumber(const std::string &data) {
    return data.length() == 6;
}

std::string Student::toString() {
    return name_ + " " + lastName_ + " " + pesel_ + " " + birthday_+ " " + getGender() + "\n" +
           address_ + " " + city_ + "\n" +
           indexNumber_ + " " + faculty_ + " " + fieldOfStudy_ + " " + currentSemester_;
}