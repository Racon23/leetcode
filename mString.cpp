#include "mString.h"

string buildString(string in)
{
    auto values = in.substr(1, in.length() - 2);
    return values;
}

void printString(string str)
{
    cout << str << endl;
}
