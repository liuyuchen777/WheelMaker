#include "String.h"
#include "../TestTool/tool.h"
#include <iostream>

using namespace std;

#define CHECK(str) do{\
    cout << str << endl;\
    cout << "len of string: " << str.len() << "\tcapacity of str: " << str.capacity() << endl;\
}while(0)

#define TEST   MULTIPLY
// different test type
#define CONSTRUCTOR 0
#define ADD         1
#define MULTIPLY    2

int main(void)
{
#if TEST == CONSTRUCTOR
    String str1("lyc!");
    String str2 = "zzh!";

    cout << str1 << endl;
    cout << str2 << endl;
#elif TEST == ADD
    String str1 = "lyc!";
    String str2 = "zzh!";
    String str3 = "dddddddddddddddddddddddddddddd";
    str1 += str2;
    CHECK(str1);
    str1 += "ssssssssssssssssssss";
    CHECK(str1);
    str1 += str3;
    CHECK(str1);
    String str4;
    str4 = "lyc!" + str2;
    CHECK(str4);
#elif TEST == INDEX
    String str1 = "lyc";
    cout << str1[0] << endl;
    cout << str1[1] << endl;
    cout << str1[2] << endl;
    cout << str1[3] << endl;
#elif TEST == MULTIPLY
    // overload *
    String str1 = "lyc";
    cout << str1 << endl;
    String str2 = str1 * 2;
    cout << str2 << endl;
    String str3 = str1 * 1;
    cout << str3 << endl;
    String str4 = str1 * 100;
    cout<< str4 << endl;
    // friend *
    String str5 = 8 * str1;
    cout << str5 << endl;
#endif
}