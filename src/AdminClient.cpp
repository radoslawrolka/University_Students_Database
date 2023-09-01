#include "AdminClient.h"

void AdminClient::run() {
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
                deleteStudent();
                break;
            case '5':
                saveToFile();
                break;
            case '6':
                openFromFile();
                break;
            case '7':
                makeQuery();
                break;
            case '8':
                showQuery();
                break;
            case '9':
                addUser();
                break;
            case '0':
                return;
            default:
                Display::coutRED("Command does not exist, choose from list below:");
                break;
        }
    }
}

void AdminClient::showMenu() {
    std::cout << "[h] - Show actions" << std::endl;
    std::cout << "[1] - Add Student" << std::endl;
    std::cout << "[2] - Edit Student" << std::endl;
    std::cout << "[3] - Find Student" << std::endl;
    std::cout << "[4] - Delete Student" << std::endl;
    std::cout << "[5] - Save Database/Query to file" << std::endl;
    std::cout << "[6] - Open Database from file" << std::endl;
    std::cout << "[7] - Make new query" << std::endl;
    std::cout << "[8] - Show Query" << std::endl;
    std::cout << "[9] - Add User" << std::endl;
    std::cout << "[0] - Exit" << std::endl;
}

bool AdminClient::deleteStudent() {
    std::string key;
    std::cout << "Enter PESEL/Index number to delete student:";
    Display::getlineBLUE(key);
    if (database_.removeStudent(key)) {
        Display::coutGREEN("Student deleted successfully");
        return true;
    }
    else {
        Display::coutRED("Student not found");
        return false;
    }
}

bool AdminClient::addUser() {
    std::string login;
    std::string password;
    std::string role;
    std::cout << "Enter login:";
    Display::getlineBLUE(login);
    std::fstream userdata;
    userdata.open("../resources/login.password", std::ios::out | std::ios::in);
    if (userdata.is_open()) {
        std::string line;
        getline(userdata, line);
        while (getline(userdata, line, ';')) {
            if (line == login) {
                Display::coutRED("ERROR: User already exists");
                return false;
            }
        }
        std::cout << "Enter password:";
        Display::getlineBLUE(password);
        while (true) {
            std::cout << "Enter role (user/admin):";
            Display::getlineBLUE(role);
            if (role == "admin" || role == "user") {
                break;
            }
            else {
                Display::coutRED("ERROR: Invalid role");
            }
        }
        userdata.clear();
        userdata.seekp(0, std::ios::end);
        userdata << "\n" << login << ";" << password << ";" << role;
        userdata.close();
        Display::coutGREEN("User added successfully");
        return true;
    }
    else {
        Display::coutRED("ERROR: Cannot open file");
        return false;
    }
}