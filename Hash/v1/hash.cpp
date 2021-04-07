/*
 * @Author: Liu Yuchen
 * @Date: 2021-04-07 18:37:04
 * @LastEditors: Liu Yuchen
 * @LastEditTime: 2021-04-08 01:46:32
 * @Description: 
 * @FilePath: /Local_Lab/WheelMaker/Hash/hash.cpp
 * @GitHub: https://github.com/liuyuchen777
 */

#include "./hash.h"
#include <iostream>
#include <string>

Hash::Hash() {
    for (int i = 0; i < tableSize; i++) {
        HashTable[i] = new item;
        HashTable[i] -> key = pattern;
        HashTable[i] -> content = pattern;
        HashTable[i] -> next = nullptr;
    }
}

// hash function to compute index
int Hash::hashFunction(string key) {
    int sum = 0;
    int index = 0;

    for (int i = 0; i < key.length(); i++) {
        sum += static_cast<int>(key[i]); // static_cast用于转换类型
    }

    index = sum % tableSize;
    
    return index;
}

// add item to hash table
void Hash::AddItem(string key, string content) {
    int index = hashFunction(key);

    if (HashTable[index]->key == pattern) {
        HashTable[index]->key = key;
        HashTable[index]->content = content;
    } else {
        item *ptr = HashTable[index];

        item *new_item = new item;
        new_item->key = key;
        new_item->content = content;
        new_item->next = nullptr;

        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }

        ptr->next = new_item;
    }
}

// print whole hash table
void Hash::PrintTable() {
    for (int i = 0; i < tableSize; i++)
    {
        item *ptr = HashTable[i];
        cout << ptr->key << ":" << ptr->content << "->";
        while (ptr->next != nullptr) {
            ptr = ptr->next;
            cout << ptr->key << ":" << ptr->content << "->";
        }
        cout << endl << "  |  " << endl;
    }
}

// hash return content by key
string Hash::FindContent(string key) {
    int index = hashFunction(key);
    item *ptr = HashTable[index];

    while (ptr->next != nullptr) {
        if (ptr->key == key) {
            return ptr->content;
        }
        ptr = ptr->next;
    }

    return "";
}

// delete an element
void Hash::RemoveItem(string key) {
    int index = hashFunction(key);
    item *ptr = new item;
    ptr->next = HashTable[index];

    while (ptr->next != nullptr) {
        if (ptr->next->key == key) {
            item *del = ptr->next;
            ptr->next = ptr->next->next;
            delete del;
            break;
        }
        ptr = ptr->next;
    }
}