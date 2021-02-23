#include "Mystring.h"
#include <string>


void Mystring::tolower()
{
    for (int i = 0; i < static_cast<int>(this->length()); i++)
    {
        char a = this->at(i);
        this->at(i) = std::tolower(a);
    }
}

void Mystring::removePunctuation()
{
    int count = 0;
    while (!((this->at(count) > 64 && this->at(count) < 91) || (this->at(count) > 96 && this->at(count) < 123))) {
        this->erase(0, 1);
    }
    for (int i = 0; i < static_cast<int>(this->length()); i++) {
        if (!((this->at(i) > 64 && this->at(i) < 91) || (this->at(i) > 96 && this->at(i) < 123))) {
            this->at(i) = '\0';
            this->resize(i);
            break;
        }
    }
}

Mystring::operator unsigned()
{
    unsigned result = 0;
    for (int i = 0; i < static_cast<int>(this->length()); i++) {
        char a = this->at(i);
        result += static_cast<unsigned>(a);
    }
    return result;
}

