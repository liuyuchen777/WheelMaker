#include "Vector.h"
#include <iostream>

template <class T>
Vector<T>::Vector(u32 num)
{
    std::cout << "I am in Vector(int num)" << std::endl;
    array = allocator(num);
}