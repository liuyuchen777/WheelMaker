#ifndef _VECTOR_H
#define _VECTOR_H

#include <iostream>
#include <assert.h>

typedef unsigned int u32;

template<typename T>
class Vector
{
private:   
    T*      array;
    u32     theSize;
    u32     theCapacity;
    static const int WALK_LENGTH = 32;
    T* allocator(u32 size) { return new T[size]; }
    void deallocator(T* arr)
    {
        if (arr)
            delete [] arr;
    }
public:
    // default constructor
    Vector() : theSize(0), theCapacity(0), array(nullptr) {}
    Vector(u32 n);
    // copy constructor
    Vector(const Vector<T> & other);
    // = operator
    Vector<T>& operator=(const Vector<T> & other);
    // deconstructor
    ~Vector();
    // operator reload
    T & operator[](u32 pos) 
    { 
        assert(pos < theSize);
        return array[pos];
    }
    // other function
    u32 size() { return theSize; }
    u32 capacity() { return theCapacity; }
    bool empty() { return theSize == 0; }
    void clear(); // clear element in array, but not clear capacity
    void push_back(const T & t);
    void push_front(const T & t);
    void erase(u32 pos);    // earse one element
    void inster_after(u32 pos, const T & t) { insert_before(pos + 1, t); }
    void insert_before(u32 pos, const T & t);
};

#endif