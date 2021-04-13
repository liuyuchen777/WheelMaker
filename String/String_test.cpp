//
// Created by liuyu on 2021/4/13.
//

#include <iostream>
#include "String.h"
#include <gtest/gtest.h>

using namespace std;

TEST(basic, overload) {
    String str1 = "lyc";
    cout << str1 << endl;
    String str2 = str1 * 2;
    cout << str2 << endl;
}