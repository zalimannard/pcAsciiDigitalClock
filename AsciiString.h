#ifndef AsciiString_H
#define AsciiString_H

#include "AsciiChar.h"
#include <vector>

class AsciiString
{
public:
    AsciiString operator+=(const AsciiChar& aChar);
    AsciiChar operator[](const int index);
    
    friend std::ostream& operator<<(std::ostream& os, AsciiString asciiString);

    int getOutputShift();
    void setOutputShift(int value);

private:
    std::vector<AsciiChar> data_;
    int outputShift_ = 0;
};

#endif
