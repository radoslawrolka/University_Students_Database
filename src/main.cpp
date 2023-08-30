#include "UserClient.h"
#include "AdminClient.h"

#include <iostream>
#include <fstream>
#include <sstream>

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
    std::string command;
    while (command != "login" && command != "exit") {
        std::cout << R"((Write "login" to login or "exit" to exit.))" << std::endl;
        getline(std::cin, command);
        if (command == "exit") {
            exit(0);
        }
        else if (command != "login") {
            std::cout << "Wrong command." << std::endl;
        }
    }
}

UserClient* login() {
    std::ifstream file;
    file.open("../resources/login.password");
    if (!file.is_open()) {
        std::cout << "System Error (No user data file)" << std::endl;
        exit(1);
    }
    else {
        int counter = 0;
        std::string line;
        while (std::getline(file, line)) {
            counter++;
        }
        std::string data[counter][3];
        counter = 0;
        file.clear();
        file.seekg(std::ios::beg);
        std::getline(file, line);
        while (std::getline(file, line)) {
            std::istringstream ss(line);
            std::string field;
            for (int i=0; i<3; i++) {
                std::getline(ss, data[counter][i], ';');
            }
            counter++;
        }
        file.close();
        std::string login;
        std::string password;
        while (true) {
            std::cout << "Login:";
            getline(std::cin, login);
            std::cout << "Password:";
            getline(std::cin, password);

            for (int i = 0; i < counter; i++) {
                if (login == data[i][0] && password == data[i][1]) {
                    if (data[i][2] == "admin") {
                        std::cout<<"Hello "<<login<<"! (admin account)"<<std::endl;
                        return new AdminClient();
                    }
                    else if (data[i][2] == "user") {
                        std::cout<<"Hello "<<login<<"! (user account)"<<std::endl;
                        return new UserClient();
                    }
                }
            }
            std::cout << "Wrong login or password." << std::endl;
            std::cout << "Press Y to try again or N to exit." << std::endl;
            std::getline(std::cin, line);
            if (line == "N" || line == "n") {
                exit(0);
            }
        }
    }
}