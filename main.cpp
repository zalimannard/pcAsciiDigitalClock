#include "AsciiStorage.h"
#include "AsciiChar.h"
#include "AsciiString.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    AsciiStorage storage(13, 7);
    std::ifstream fin("../numbers");
    while (!fin.eof())
    {
        AsciiChar tmp(13, 7);
        fin >> tmp;
        storage.set(tmp.getNonAsciiSymbol(), tmp);
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    std::string phraseToPrint = std::to_string(tm.tm_hour) + ":" + std::to_string(tm.tm_min);
    AsciiString asciiString;
    asciiString.setOutputShift(4);

    for (auto ch : phraseToPrint)
    {
        asciiString += storage.get(ch);
    }
    std::cout << asciiString << std::endl;

    return 0;
}
