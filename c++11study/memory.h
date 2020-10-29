#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>

using namespace std;

char *GetString2(void)
{
    char *p = "hello world";
    return p;
}

void Test5(void)
{
    char *str = NULL;
    str = GetString2();
    cout << str << endl;
}


#endif // MEMORY_H
