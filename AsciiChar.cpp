#include "AsciiChar.h"
#include <string>
#include <vector>

AsciiChar::AsciiChar(int width, int height)
{
    width_ = width;
    height_ = height;
}

AsciiChar::AsciiChar(std::vector<std::string> data, char nonAsciiSymbol,
        int width, int height)
{
    data_ = data;
    nonAsciiSymbol_ = nonAsciiSymbol;
    width_ = width;
    height_ = height;
}

std::vector<std::string> AsciiChar::getData()
{
    return data_;
}

char AsciiChar::getNonAsciiSymbol()
{
    return nonAsciiSymbol_;
}

int AsciiChar::getWidth()
{
    return width_;
}

int AsciiChar::getHeight()
{
    return height_;
}

std::string makeLength(const std::string& str, int length)
{
    std::string answer;
    for (int i = 0; i < length; ++i)
    {
        if (i < str.length())
        {
            answer += str[i];
        }
        else
        {
            answer += ' ';
        }
    }
    return answer;
}

std::istream& operator>>(std::istream& is, AsciiChar& asciiChar)
{
    asciiChar.data_.clear();
    
    std::string nonAsciiStringWithChar;
    std::getline(is, nonAsciiStringWithChar);
    asciiChar.nonAsciiSymbol_ = nonAsciiStringWithChar[0];

    for (int i = 0; i < asciiChar.getHeight(); ++i)
    {
        std::string row;
        std::getline(is, row);
        row = makeLength(row, asciiChar.width_);
        asciiChar.data_.push_back(row);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const AsciiChar& asciiChar)
{
    for (auto row : asciiChar.data_)
    {
        os << row << std::endl;
    }
    return os;
}
