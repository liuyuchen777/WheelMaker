#include "String.h"
#include "../TestTool/tool.h"
#include <iostream>

using namespace std;

#define CHECK(str) do{\
    cout << str << endl;\
    cout << "len of string: " << str.len() << "\tcapacity of str: " << str.capacity() << endl;\
}while(0)

#define TEST   ADD
// different test type
#define CONSTRUCTOR 0
#define ADD         1

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
#endif
}