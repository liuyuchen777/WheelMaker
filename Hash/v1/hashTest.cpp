/*
 * @Author: Liu Yuchen
 * @Date: 2021-04-07 18:37:11
 * @LastEditors: Liu Yuchen
 * @LastEditTime: 2021-04-08 01:45:54
 * @Description: 
 * @FilePath: /Local_Lab/WheelMaker/Hash/hashTest.cpp
 * @GitHub: https://github.com/liuyuchen777
 */

#include <gtest/gtest.h>
#include "./hash.h"

TEST(add, basic)
{
    Hash myHash;
    myHash.AddItem("lyc", "king");
    myHash.AddItem("zzh", "student");
    myHash.AddItem("xxl", "engineer");
    myHash.AddItem("dth", "student");
    cout << "lyc" << ":" << myHash.FindContent("lyc") << endl;
    cout << "------------------------------------------" << endl;
    myHash.RemoveItem("zzh");
    myHash.PrintTable();
}