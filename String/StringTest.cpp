#include "String.h"
#include "../TestTool/tool.h"
#include <iostream>

using namespace std;

#define TEST_TYPE   CONSTRUCTOR
// different test type
#define CONSTRUCTOR 0
int main(void)
{
#if TEST_TYPE == CONSTRUCTOR
    String str1("lyc!");
    String str2 = "zzh!";

    cout << str1 << endl;
    cout << str2 << endl;
#else

#endif
}