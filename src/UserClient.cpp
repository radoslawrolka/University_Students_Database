#include "UserClient.h"

bool validDate(std::string date);

void UserClient::run() {
    while (true) {
        showMenu();
        std::string choice;
        std::getline(std::cin, choice);
        switch (choice[0]) {
            case 'h':
                showMenu();
                break;
            case '1':
                addStudent();
                break;
            case '2':
                editStudent();
                break;
            case '3':
                findStudent();
                break;
            case '4':
                saveToFile();
                break;
            case '5':
                openFromFile();
                break;
            case '0':
                return;
            default:
                std::cout << "Wrong choice, press 'h' to show actions" << std::endl;
                break;
        }
    }
}

void UserClient::showMenu() {
    std::cout << "[h] - Show actions" << std::endl;
    std::cout << "[1] - Add Student" << std::endl;
    std::cout << "[2] - Edit Student" << std::endl;
    std::cout << "[3] - Find Student" << std::endl;
    std::cout << "[4] - Save Database to file" << std::endl;
    std::cout << "[5] - Open Database from file" << std::endl;
    std::cout << "[0] - Exit" << std::endl;
}

bool UserClient::addStudent() {
    std::string name;
    std::string lastname;
    std::string address;
    std::string city;
    std::string birthday;
    std::string pesel;
    std::string gender;
    std::string indexNumber;
    std::string faculty;
    std::string fieldOfStudy;
    std::string currentSemester;

    std::cout<<"Enter name: ";
    getline(std::cin, name);
    std::cout<<"Enter lastname: ";
    getline(std::cin, lastname);
    std::cout<<"Enter address: ";
    getline(std::cin, address);
    std::cout<<"Enter city: ";
    getline(std::cin, city);
    std::cout<<"Enter birthday [YYYY-MM-DD]: ";
    getline(std::cin, birthday);
    if (!validDate(birthday)) {
        std::cout << "Invalid date" << std::endl;
        return false;
    }
    std::cout<<"Enter pesel (11 digits): ";
    getline(std::cin, pesel);
    if (pesel.length() != 11) {
        std::cout << "Invalid PESEL" << std::endl;
        return false;
    }
    std::cout<<"Enter gender (Male/Female/Other): ";
    getline(std::cin, gender);
    std::cout<<"Enter index number (6 digits): ";
    getline(std::cin, indexNumber);
    if (indexNumber.length() != 6) {
        std::cout << "Invalid index number" << std::endl;
        return false;
    }
    std::cout<<"Enter faculty: ";
    getline(std::cin, faculty);
    std::cout<<"Enter field of study: ";
    getline(std::cin, fieldOfStudy);
    std::cout<<"Enter current semester: ";
    getline(std::cin, currentSemester);
    if (database_.addStudent(name, lastname, address, city, birthday, pesel, gender, indexNumber, faculty, fieldOfStudy, currentSemester)) {
        std::cout << "Student added" << std::endl;
        return true;
    }
    else {
        std::cout << "ERROR: Student with same PESEL/Index already exists" << std::endl;
        return false;
    }
}

bool UserClient::editStudent() {
    std::string key;
    std::string data;
    std::cout << "Enter PESEL or IndexNumber of student to edit: ";
    getline(std::cin, key);
    std::shared_ptr<Student> student = database_.findStudent(key);
    if (!student) {
        std::cout << "Student not found" << std::endl;
        return false;
    }
    std::cout << "[Press 'Enter' to ommit editing data field]" << std::endl;
    for (int i = 0; i < sizeof(student->settersName)/sizeof(std::string); i++) {
        while (true) {
            std::cout << "Current " << student->settersName[i] << ": " << (student.get()->*student->getGetter[i])()
                      << "\nNew " << student->settersName[i] << ":";
            getline(std::cin, data);
            if (data.empty()) {
                break;
            }
            else if ((student.get()->*student->getValidator[i])(data)) {
                (student.get()->*student->getSetter[i])(data);
                break;
            }
            else {
                std::cout << "Invalid " << student->settersName[i] << std::endl;
            }
        }
    }
    return true;
}

bool UserClient::findStudent() {
    std::string key;
    std::cout << "Enter PESEL or IndexNumber of student to find: ";
    getline(std::cin, key);
    std::shared_ptr<Student> student = database_.findStudent(key);
    if (student) {
        std::cout << student->toString() << std::endl;
        return true;
    }
    else {
        std::cout << "Student not found" << std::endl;
        return false;
    }
}

bool UserClient::saveToFile() {
    std::cout << "Enter filename: ";
    std::string filename;
    getline(std::cin, filename);
    if (database_.saveToFile(filename)) {
        std::cout << "Database saved" << std::endl;
        return true;
    }
    else {
        std::cout << "ERROR: Cannot save database" << std::endl;
        return false;
    }
}

bool UserClient::openFromFile() {
    std::cout << "Enter filename: ";
    std::string filename;
    getline(std::cin, filename);
    if (database_.openFromFile(filename)) {
        std::cout << "Database loaded" << std::endl;
        return true;
    }
    else {
        std::cout << "ERROR: Cannot load database" << std::endl;
        return false;
    }
}

bool validDate(std::string date) {
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