#ifndef AsciiStorage_H
#define AsciiStorage_H

#include "AsciiChar.h"
#include <string>
#include <vector>
#include <map>

class AsciiStorage 
{
public:
    AsciiStorage(int width, int height);
    
    AsciiChar get(char key);
    void set(char key, AsciiChar value);

    int getWidth ();
    int getHeight ();

private:
    std::map<char, AsciiChar*> symbolTable_;
    int width_;
    int height_;
};

#endif
