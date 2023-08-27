#include "Database.h"
#include "Student.h"
#include "UserClient.h"
#include "AdminClient.h"

#include <iostream>
#include <fstream>

void greet();
void login(UserClient*& user);

int main() {
    UserClient* user;

    greet();
    login(user);
    user->run();
    user->close();
    return 0;
}

void greet() {
    std::cout << "Welcome to the University Students Database." << std::endl;
    std::cout << R"(Write "login" to login or "exit" to exit.)" << std::endl;
    std::string command;
    while (command != "login" && command != "exit") {
        std::cin >> command;
        if (command == "exit") {
            exit(0);
        }
        else if (command != "login") {
            std::cout << "Wrong command." << std::endl;
            std::cout << R"(Write "login" to login or "exit" to exit.)" << std::endl;
        }
    }
}

void login(UserClient*& user) {
    std::string login;
    std::string password;
    while (true) {
        std::cout << "Login: ";
        std::cin >> login;
        std::cout << "Password: ";
        std::cin >> password;
        if (login == "admin" && password == "admin") {
            user = new AdminClient();
            break;
        }
        else if (login == "user" && password == "user") {
            user = new UserClient();
            break;
        }
        else {
            std::cout << "Wrong login or password." << std::endl;
            std::cout << "Press Y to try again or N to exit." << std::endl;
            char c;
            std::cin >> c;
            if (c == 'N' || c == 'n') {
                exit(0);
            }
        }
    }
}