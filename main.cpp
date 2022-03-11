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

    std::string phraseToPrint = "11:23";
    AsciiString asciiString;
    asciiString.setOutputShift(0);

    for (auto ch : phraseToPrint)
    {
        asciiString += storage.get(ch);
    }
    std::cout << asciiString << std::endl;

    std::cout << "asdi" << std::endl;
    return 0;
}
