//
// Created by liuyu on 2021/4/13.
//

#include "Vector.h"

template <typename T>
Vector<T>::Vector()
{
    u32 actual_len = 0;

    TT_PRINT("%s", "I am in Vector().");
    actual_len = WALK_LENGTH;
    this->start = allocator(actual_len);
    this->end = this->start;
    this->theSize = 0;
    this->theCapacity = actual_len;
}

template <typename T>
Vector<T>::Vector(u32 num)
{
    u32 actual_len = 0;

    TT_PRINT("%s", "I am in Vector(u32 num).");
    if (num < WALK_LENGTH)
        actual_len = WALK_LENGTH;
    else
        actual_len = num;
    this->start = allocator(actual_len);
    this->end = this->start;
    this->theSize = 0;
    this->theCapacity = actual_len;
}

template <typename T>
Vector<T>::~Vector()
{
    TT_PRINT("%s", "I am in ~Vector().");
    deallocator(start);
    this->start = nullptr;
    this->end = nullptr;
    this->theSize = 0;
    this->theCapacity = 0;
}

// = overload
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> & other)
{
    int count = 0;

    TT_PRINT("%s", "I am in operator=(const Vector<T> & other).");
    this->strart = allocator(other.capacity());
    this->end = this->start + other.size();
    this->theSize = other.size();
    this->theCapacity = other.capacity();
    // copy elements in other to this
    for (count = 0; count < other.size(); count++)
    {
        start[count] = other[count];
    }
}

// copy constructor
template <class T>
Vector<T>::Vector(const Vector<T> & other)
{
    int count = 0;

    TT_PRINT("%s", "I am in Vector(const Vector<T> & other).");
    this->start = allocator(other.capacity());
    this->end = this->start + other.size();
    this->theSize = other.size();
    this->theCapacity = other.capacity();
    // copy elements in other to this
    for (count = 0; count < other.size(); count++)
    {
        start[count] = other[count];
    }
}

template <typename T>
void Vector<T>::vec_status()
{
    TT_PRINT("%s", "I am in vec_status().");
    std::cout << "Capacity: " << theCapacity << ", Size: " << theSize << std::endl;
}

template <typename T>
void Vector<T>::clear()
{
    TT_PRINT("%s", "I am in clear()");
    this->theSize = 0;
    this->end = this->start;
}

template <typename T>
void Vector<T>::push_back(const reference t)
{
    int count = 0;
    pointer temp = nullptr;

    if ((this->theSize + 1) > this->theCapacity)
    {
        temp = allocator(this->theSize + WALK_LENGTH);
        for (count = 0; count < theSize; count++)
        {
            // move all the elements from old pointer to new pointer

        }
        this->theSize += 1;
        this->theCapacity += WALK_LENGTH;
        deallocator(this->start);
        this->start = temp;
        this->end = this->start + this->theSize;
    }
    else
    {
        *(this->end + 1) = t;
        this->end += 1;
        this->theSize += 1;
    }
}

template <typename T>
void Vector<T>::push_front(const reference t)
{

}

template <typename T>
void Vector<T>::erase(u32 pos)
{

}

template <typename T>
void Vector<T>::insert_before(u32 pos, const reference t)
{

}