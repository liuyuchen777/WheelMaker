#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <assert.h>

typedef unsigned int u32;

using std::cout;
using std::endl;

template<class T>
class Vector
{
public:
    // type define
    typedef T value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef const value_type* const_iterator;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef size_t size_type;
    typedef value_type* iterator;
private:   
    T*               array;
    u32              theSize;
    u32              theCapacity;
    // when capacity is not enough, increase size
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
    Vector(u32 num);
    // copy constructor
    Vector(const Vector<T> & other);
    // = operator
    Vector<T>& operator=(const Vector<T> & other);
    // deconstructor
    ~Vector();
    // operator reload
    reference operator[](u32 pos) 
    { 
        assert(pos < theSize);
        return array[pos];
    }
    // other function
    u32 size() const { return theSize; }
    u32 capacity() const { return theCapacity; }
    bool empty() const { return theSize == 0; } // judege the vector is blank or not
    void clear(); // clear element in array, but not clear capacity
    bool push_back(const T & t);
    bool push_front(const T & t);
    void erase(u32 pos);    // earse one element
    bool inster_after(u32 pos, const T & t) { return insert_before(pos + 1, t); }
    bool insert_before(u32 pos, const T & t);
    void vec_state();
};

template <class T>
Vector<T>::Vector(u32 num)
{
    std::cout << "I am in Vector(int num)" << std::endl;
    this->array = allocator(num);
    this->theSize = num;
    this->theCapacity = num;
}

template <typename T>
Vector<T>::~Vector()
{
    std::cout << "I am in ~Vector()" << std::endl;
    deallocator(array);
    this->array = nullptr;
    this->theSize = 0;
    this->theCapacity = 0;
}

// = overload
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> & other)
{

}

// copy constructor
template <class T>
Vector<T>::Vector(const Vector<T> & other)
{
    int count = 0;

    std::cout << "I am in copy constructor" << std::endl;
    array = allocator(other.capacity());
    this->theSize = other.size();
    this->theCapacity = other.capacity();
    // copy elements in other to this
    for (count = 0; count < other.size(); count++)
    {  
        array[count] = other[count];
    }
}

template <typename T>
void Vector<T>::vec_state()
{
    std::cout << "Capacity: " << theCapacity << ", Size: " << theSize << std::endl;
}


#endif