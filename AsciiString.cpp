#include "AsciiString.h"
#include "AsciiChar.h"
#include <iostream>
#include <ostream>
#include <string>
#include <vector>


AsciiString AsciiString::operator+=(const AsciiChar& aChar)
{
    this->data_.push_back(aChar);
    return *this;
}

AsciiChar AsciiString::operator[](const int index)
{
    return this->data_[index];
}
    
std::ostream& operator<<(std::ostream& os, AsciiString asciiString)
{
    if (!asciiString.data_.empty())
    {
        int length = asciiString.data_.size() * asciiString.data_[0].getWidth()
            - (asciiString.data_.size() - 1) * asciiString.getOutputShift();
    std::cout << "length: " << length << std::endl;
        std::vector<std::string> asciiAnswer;
        std::string spaceRow (length, ' ');
        for (int i = 0; i < asciiString.data_[0].getHeight(); ++i)
        {
            asciiAnswer.push_back(spaceRow);
        }

        for (int asciiCharNumber = 0; 
                asciiCharNumber < asciiString.data_.size(); ++asciiCharNumber)
        {
    std::cout << "char: " << asciiCharNumber << std::endl;
            for (int rowNumber = 0;
                    rowNumber < asciiString.data_[0].getHeight(); ++rowNumber)
            {
    std::cout << "row: " << rowNumber << std::endl;
                for (int charInRowNumber = 0;
                        charInRowNumber < asciiString.data_[0].getWidth();
                        ++charInRowNumber)
                {
    std::cout << "nCharRow: " << charInRowNumber << std::endl;
                    char currentChar = asciiString.data_[asciiCharNumber]
                        .getData()[rowNumber][charInRowNumber];
    std::cout << "-" << currentChar << "-" << std::endl;
                    if (currentChar != ' ')
                    {
    std::cout << "1" << std::endl;
                        int pos = 
                            asciiCharNumber * asciiString.data_[0].getWidth() -
                            (asciiString.data_.size() - 1) * 
                            asciiString.getOutputShift() + charInRowNumber;
                        asciiAnswer[rowNumber][pos] = currentChar;
                    }
                }
            }
        }

        for (auto row : asciiAnswer)
        {
            os << row << std::endl;
        }
    }

    return os;
}

int AsciiString::getOutputShift()
{
    return outputShift_;
}

void AsciiString::setOutputShift(int value)
{
    outputShift_ = value;
}
