/*
 * @Author: Liu Yuchen
 * @Date: 2021-04-08 09:43:45
 * @LastEditors: Liu Yuchen
 * @LastEditTime: 2021-04-08 02:06:41
 * @Description: try to use operator overload to reconstruct code
 * @FilePath: /Local_Lab/WheelMaker/Hash/v2/mapTest.cpp
 * @GitHub: https://github.com/liuyuchen777
 */

#include <map>
#include <iostream>

using namespace std;

int main() {
    map<string, string> myMap;
    myMap["lyc"] = "king";
    cout << myMap["lyc"] << endl;

    return 0;
}