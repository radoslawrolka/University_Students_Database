#ifndef UNIVERSITY_STUDENTS_DATABASE_ADMINCLIENT_H
#define UNIVERSITY_STUDENTS_DATABASE_ADMINCLIENT_H

#include "UserClient.h"

class AdminClient : public UserClient {
public:
    void run() override;
    void showMenu() override;
    bool deleteStudent();
    bool addUser();
};

#endif //UNIVERSITY_STUDENTS_DATABASE_ADMINCLIENT_H
