#ifndef AsciiChar_H
#define AsciiChar_H

#include <istream>
#include <ostream>
#include <string>
#include <vector>

class AsciiChar 
{
public:
    AsciiChar(int width, int height);
    AsciiChar(std::vector<std::string> data, char nonAsciiSymbol,
            int width, int height);

    std::vector<std::string> getData();
    char getNonAsciiSymbol();
    int getWidth();
    int getHeight();

    friend std::istream& operator>>(std::istream& is,
            AsciiChar& asciiChar);
    friend std::ostream& operator<<(std::ostream& os,
            const AsciiChar& asciiChar);

private:
    std::vector<std::string> data_;
    char nonAsciiSymbol_;
    int width_;
    int height_;

    friend std::string makeLength(const std::string& str, int length);

};

#endif
