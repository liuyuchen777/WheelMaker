#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(void)
{
    string str1 = "lyc!";
    string str2 = "zzh!";
    string str3 = str1 + str2;
    string str4 = "lyc!" + "zzh!";
    
    printf("str1 = %p, str2 = %p, str3 = %p\n", &str1, &str2, &str3);
    str1 = str1 + str2;
    printf("str1 = %p, str2 = %p, str3 = %p\n", &str1, &str2, &str3);
    cout << str4 << endl;

    return 0;
}