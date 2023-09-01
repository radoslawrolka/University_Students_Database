#ifndef UNIVERSITY_STUDENTS_DATABASE_DISPLAY_H
#define UNIVERSITY_STUDENTS_DATABASE_DISPLAY_H

#include <iostream>
#include <windows.h>
#include <cstdlib>

class Display {
public:
    static void coutRED(const std::string& text);
    static void coutGREEN(const std::string& text);
    static void getlineBLUE(std::string& text);
private:
    static inline HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE );
};


#endif //UNIVERSITY_STUDENTS_DATABASE_DISPLAY_H
