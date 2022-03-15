#include "AsciiStorage.h"
#include "AsciiChar.h"
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

AsciiStorage::AsciiStorage(int width, int height)
{
    width_ = width;
    height_ = height;
}

AsciiChar AsciiStorage::get(char key)
{
    return *symbolTable_[key];
}

void AsciiStorage::set(char key, AsciiChar value)
{
    symbolTable_[key] = new AsciiChar(value.getData(),
            value.getNonAsciiSymbol(), value.getWidth(), value.getHeight());
}

int AsciiStorage::getWidth()
{
    return width_;
}

int AsciiStorage::getHeight()
{
    return height_;
}
