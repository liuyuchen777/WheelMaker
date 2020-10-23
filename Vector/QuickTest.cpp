#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printInt(int & n);

#define CHECK(vec) do{\
    cout << "size of vec is: " << vec.size() << "\tcapacity of vec is: " << vec.capacity() << endl;\
    for_each(vec.begin(), vec.end(), printInt);\
    cout << endl;\
}while(0)

int main(void)
{
    vector<int> vec;
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    // cout << vec[0] << endl; // 未分配空间的时候也会出错
    // STL vector capacity的增加机制很有意思
    vec.push_back(1);
    CHECK(vec);
    vec.push_back(2);
    vec.push_back(3);
    CHECK(vec);
    vec.push_back(4);
    CHECK(vec);
    vec.push_back(5);
    CHECK(vec);
    vector<int> vec2(10);
    CHECK(vec2);

    return 0;
}

void printInt(int & n)
{
    cout << n << "  ";
}