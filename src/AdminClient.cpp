#include "AdminClient.h"

void AdminClient::run() {
    while (true) {
        showMenu();
        std::string choice;
        std::getline(std::cin, choice);
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
                std::cout << "Command does not exist, choose from list below:" << std::endl;
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
    getline(std::cin, key);
    if (database_.removeStudent(key)) {
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );
        std::cout << "Student deleted successfully" << std::endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        return true;
    }
    else {
        SetConsoleTextAttribute( hOut, FOREGROUND_RED );
        std::cout << "Student not found" << std::endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        return false;
    }
}

bool AdminClient::addUser() {
    std::string login;
    std::string password;
    std::string role;
    std::cout << "Enter login:";
    getline(std::cin, login);
    std::fstream userdata;
    userdata.open("../resources/login.password", std::ios::out | std::ios::in);
    if (userdata.is_open()) {
        std::string line;
        getline(userdata, line);
        while (getline(userdata, line, ';')) {
            if (line == login) {
                SetConsoleTextAttribute( hOut, FOREGROUND_RED );
                std::cout << "ERROR: User already exists" << std::endl;
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
                return false;
            }
        }
        std::cout << "Enter password:";
        getline(std::cin, password);
        while (true) {
            std::cout << "Enter role (user/admin):";
            getline(std::cin, role);
            if (role == "admin" || role == "user") {
                break;
            }
            else {
                SetConsoleTextAttribute( hOut, FOREGROUND_RED );
                std::cout << "ERROR: Invalid role" << std::endl;
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            }
        }
        userdata.clear();
        userdata.seekp(0, std::ios::end);
        userdata << "\n" << login << ";" << password << ";" << role;
        userdata.close();
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );
        std::cout << "User added successfully" << std::endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        return true;
    }
    else {
        SetConsoleTextAttribute( hOut, FOREGROUND_RED );
        std::cout << "ERROR: Cannot open file" << std::endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        return false;
    }
}