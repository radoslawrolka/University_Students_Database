#include "UserClient.h"
#include "AdminClient.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <vector>
#include <windows.h>
#include <cstdlib>

void greet();
UserClient* login();


int main() {
    greet();
    UserClient* user = login();
    user->run();
    delete user;
    return 0;
}





void greet() {
    std::cout << "Welcome to the University Students Database." << std::endl;
    std::cout << "(Press any key to continue)" << std::endl;
    getch();
}

UserClient* login() {
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    std::ifstream file;
    file.open("../resources/login.password");
    if (!file.is_open()) {
        SetConsoleTextAttribute( hOut, FOREGROUND_RED );
        std::cout << "System Error (No user data file)" << std::endl;
        exit(1);
    }
    else {
        struct userData {
            std::string login;
            std::string password;
            std::string role;
        };
        std::vector<userData> loginData;
        std::string line;
        std::getline(file, line);
        while (std::getline(file, line)) {
            std::istringstream ss(line);
            userData data;
            std::getline(ss, data.login, ';');
            std::getline(ss, data.password, ';');
            std::getline(ss, data.role, ';');
            loginData.push_back(data);
        }
        file.close();
        std::string login;
        std::string password;
        while (true) {
            std::cout << "Login:";
            getline(std::cin, login);
            std::cout << "Password:";
            getline(std::cin, password);

            for (auto &data : loginData) {
                if (login == data.login && password == data.password) {
                    if (data.role == "admin") {
                        std::cout<< "Hello " << login << "! (admin account)" <<std::endl;
                        return new AdminClient();
                    }
                    else {
                        std::cout<< "Hello " << login << "! (user account)"<<std::endl;
                        return new UserClient();
                    }
                }
            }
            SetConsoleTextAttribute( hOut, FOREGROUND_RED );
            std::cout << "Wrong login or password." << std::endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            std::cout << "Press Y to try again or N to exit." << std::endl;
            std::getline(std::cin, line);
            if (line == "N" || line == "n") {
                exit(0);
            }
        }
    }
}