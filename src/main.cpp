#include "UserClient.h"
#include "AdminClient.h"
#include "Display.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <vector>
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
    std::ifstream file;
    file.open("../resources/login.password");
    if (!file.is_open()) {
        Display::coutRED("System Error (No user data file)");
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
            std::cout << "Login: ";
            Display::getlineBLUE(login);
            std::cout << "Password: ";
            Display::getlineBLUE(password);
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
            Display::coutRED("Wrong login or password.");
            std::cout << "Press Y to try again or N to exit." << std::endl;
            Display::getlineBLUE(line);
            if (line == "N" || line == "n") {
                exit(0);
            }
        }
    }
}