#include "AsciiStorage.h"
#include "AsciiChar.h"
#include "AsciiString.h"
#include <unistd.h>
#include <cstdlib>
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
    std::ifstream fin("pctime.txt");
    while (!fin.eof())
    {
        AsciiChar tmp(13, 7);
        fin >> tmp;
        storage.set(tmp.getNonAsciiSymbol(), tmp);
    }

    bool isDotsVisible = true;
    while (true)
    {
        system("clear");
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
    
        std::string hours = std::to_string(tm.tm_hour);
        if (hours.length() == 1)
        {  
            hours = "0" + hours;
        }
        std::string minutes = std::to_string(tm.tm_min);
        if (minutes.length() == 1)
        {
            minutes = "0" + minutes;
        }

        std::string phraseToPrint;

        if (isDotsVisible)
        {
            phraseToPrint = hours + ":" + minutes;
        }
        else
        {
            phraseToPrint = hours + "_" + minutes;
        }
        AsciiString asciiString;
        asciiString.setOutputShift(4);

        for (auto ch : phraseToPrint)
        {
            asciiString += storage.get(ch);
        }
        std::cout << asciiString << std::endl;

        if (isDotsVisible)
        {
            usleep(500 * 1000);
        }
        else
        {
            usleep(500 * 1000);
        }

        isDotsVisible = !isDotsVisible;
    }

    return 0;
}
