#include "Display.h"

void Display::coutRED(const std::string& text) {
    SetConsoleTextAttribute( hOut, FOREGROUND_RED );
    std::cout << text << std::endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
}

void Display::coutGREEN(const std::string& text) {
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );
    std::cout << text << std::endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
}

void Display::getlineBLUE(std::string& text) {
    SetConsoleTextAttribute( hOut, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    getline(std::cin, text);
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
}