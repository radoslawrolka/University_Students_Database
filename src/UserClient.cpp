#include "UserClient.h"

bool valid(const std::string& data);
bool validDate(const std::string& date);
bool validPesel(const std::string& data);
bool validIndexNumber(const std::string& data);
typedef bool (*validators)(const std::string&);
std::string settersName[11] = {"Name", "Lastname", "Address", "City", "Birthday", "PESEL", "Gender", "Index number", "Faculty", "Field of study", "Current semester"};
validators getValidator[11] = {valid, valid, valid, valid, validDate, validPesel, valid, validIndexNumber, valid, valid, valid};

void UserClient::run() {
    while (true) {
        showMenu();
        std::string choice;
        Display::getlineBLUE(choice);
        switch (choice[0]) {
            case 'h':
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
            case '6':
                makeQuery();
                break;
            case '7':
                showQuery();
                break;
            case '0':
                return;
            default:
                Display::coutRED("Command does not exist, choose from list below:");
                break;
        }
    }
}

void UserClient::showMenu() {
    std::cout << "[h] - Show actions" << std::endl;
    std::cout << "[1] - Add Student" << std::endl;
    std::cout << "[2] - Edit Student" << std::endl;
    std::cout << "[3] - Find Student" << std::endl;
    std::cout << "[4] - Save Database/Query to file" << std::endl;
    std::cout << "[5] - Open Database from file" << std::endl;
    std::cout << "[6] - Make new query" << std::endl;
    std::cout << "[7] - Show Query" << std::endl;
    std::cout << "[0] - Exit" << std::endl;
}

bool UserClient::addStudent() {
    std::string data[11];
    for (int i=0; i<11; i++) {
        while (true) {
            std::cout << "Enter " << settersName[i] << ":";
            Display::getlineBLUE(data[i]);
            if ((getValidator[i])(data[i])) {
                break;
            }
            else {
                Display::coutRED("Invalid " + settersName[i]);
            }
        }
    }
    if (database_.addStudent(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7],
                             data[8], data[9], data[10])) {
        Display::coutGREEN("Student added");
        return true;
    }
    else {
        Display::coutRED("ERROR: Student with same PESEL/Index already exists");
        return false;
    }
}

bool UserClient::editStudent() {
    std::string key;
    std::string data;
    std::cout << "Enter PESEL or IndexNumber of student to edit: ";
    Display::getlineBLUE(key);
    std::shared_ptr<Student> student = database_.findStudent(key);
    if (!student) {
        Display::coutRED("Student not found");
        return false;
    }
    std::cout << "[Press 'Enter' to ommit editing data field]" << std::endl;
    for (int i = 0; i < 11; i++) {
        if (settersName[i] == "PESEL" || settersName[i] == "Index number") {
            continue;
        }
        while (true) {
            std::cout << "Current " << settersName[i] << ": " << (student.get()->*student->getGetter[i])()
                      << "\nNew " << settersName[i] << ":";
            Display::getlineBLUE(data);
            if (data.empty()) {
                break;
            }
            else if (getValidator[i](data)) {
                (student.get()->*student->getSetter[i])(data);
                break;
            }
            else {
                Display::coutRED("Invalid " + settersName[i]);
            }
        }
    }
    Display::coutGREEN("Student edited");
    return true;
}

bool UserClient::findStudent() {
    std::string key;
    std::cout << "Enter PESEL or IndexNumber of student to find: ";
    Display::getlineBLUE(key);
    std::shared_ptr<Student> student = database_.findStudent(key);
    if (student) {
        Display::coutGREEN(student->toString());
        return true;
    }
    else {
        Display::coutRED("Student not found");
        return false;
    }
}

bool UserClient::saveToFile() {
    std::cout << "Enter filename: ";
    std::string filename;
    Display::getlineBLUE(filename);
    if (database_.saveToFile(filename)) {
        Display::coutGREEN("Database saved");
        return true;
    }
    else {
        Display::coutRED("ERROR: Cannot save database");
        return false;
    }
}

bool UserClient::openFromFile() {
    std::cout << "Enter filename: ";
    std::string filename;
    Display::getlineBLUE(filename);
    if (database_.openFromFile(filename)) {
        Display::coutGREEN("Database loaded");
        return true;
    }
    else {
        Display::coutRED("ERROR: Cannot load database");
        return false;
    }
}

bool UserClient::makeQuery() {
    std::string data[9];
    int j = 0;
    for (int i=0; i<11; i++) {
        if (i == 2 || i==4 || i==5 || i==7) {
            continue;
        }
        while (true) {
            std::cout << "Enter " << settersName[i] << ":";
            Display::getlineBLUE(data[j]);
            if ((getValidator[i])(data[j])) {
                break;
            }
            else {
                Display::coutRED("Invalid " + settersName[i]);
            }
        }
        j++;
    }
    if (database_.newQuery(data)) {
        Display::coutGREEN("Query created");
        return true;
    }
}

bool UserClient::showQuery() {
    if (!database_.showQuery()) {
        Display::coutRED("Query does not exist");
        return false;
    }
    return true;
}
bool valid(const std::string& data) {
    return true;
}

bool validDate(const std::string &date) {
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

bool validPesel(const std::string &data) {
    return data.length() == 11;
}

bool validIndexNumber(const std::string &data) {
    return data.length() == 6;
}