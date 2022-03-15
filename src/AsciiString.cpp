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
        std::vector<std::string> asciiAnswer;
        std::string spaceRow (length, ' ');
        for (int i = 0; i < asciiString.data_[0].getHeight(); ++i)
        {
            asciiAnswer.push_back(spaceRow);
        }

        for (int asciiCharNumber = 0; 
                asciiCharNumber < asciiString.data_.size(); ++asciiCharNumber)
        {
            for (int rowNumber = 0;
                    rowNumber < asciiString.data_[0].getHeight(); ++rowNumber)
            {
                for (int charInRowNumber = 0;
                        charInRowNumber < asciiString.data_[0].getWidth();
                        ++charInRowNumber)
                {
                    char currentChar = asciiString.data_[asciiCharNumber]
                        .getData()[rowNumber][charInRowNumber];
                    if (currentChar != ' ')
                    {
                        int pos = 
                            asciiCharNumber * asciiString.data_[0].getWidth() 
                            - asciiCharNumber * asciiString.getOutputShift()
                            + charInRowNumber;
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
