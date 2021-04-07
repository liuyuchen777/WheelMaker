/*
 * @Author: Liu Yuchen
 * @Date: 2021-04-07 18:36:59
 * @LastEditors: Liu Yuchen
 * @LastEditTime: 2021-04-08 01:40:07
 * @Description: 
 * @FilePath: /Local_Lab/WheelMaker/Hash/hash.h
 * @GitHub: https://github.com/liuyuchen777
 */
#ifndef _HASH_H_
#define _HASH_H_

#include <iostream>
#include <string>

using namespace std;

struct item {
    string key;
    string content;
    item *next;
};

const string pattern = "empty";

class Hash {
private:
    static const int tableSize = 10;
    item *HashTable[tableSize];
public:
    // construct function
    Hash();
    // fun
    int hashFunction(string key);
    void AddItem(string key, string content);
    void PrintTable();
    string FindContent(string key);
    void RemoveItem(string key);
};

#endif