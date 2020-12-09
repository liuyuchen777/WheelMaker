#ifndef _VECTOR_H_
#define _VECTOR_H_

#define TT_LEVEL			(1)

#include <iostream>
#include <assert.h>
#if TT_LEVEL > 0
    #include <stdio.h>
#endif

typedef unsigned int u32;

using std::cout;
using std::endl;

// debug print function
#if TT_LEVEL > 0
	#define TT_PRINT(format, args...) do {\
				printf("[%s: %d] "format"\n", __FUNCTION__, __LINE__, ##args);\
				getchar();\
			} while(0)
#else
	#define TT_PRINT(format, args...)
#endif

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
    pointer          start;
    pointer          end;
    u32              theSize;
    u32              theCapacity;
    // when capacity is not enough, increase size
    static const int WALK_LENGTH = 32;  
    pointer allocator(u32 size) { return new T[size]; }
    void deallocator(T* arr)
    {
        if (arr)
            delete [] arr;
    }
public:
    // default constructor
    Vector();
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
        return start[pos];
    }
    // other function
    u32 size() const { return theSize; }
    u32 capacity() const { return theCapacity; }
    bool empty() const { return theSize == 0; } // judege the vector is blank or not
    void clear(); // clear element in array, but not clear capacity
    void push_back(const reference t); // qdd one new element at the end
    void push_front(const reference t); // add one new element at the start
    void erase(u32 pos);    // earse one element
    void inster_after(u32 pos, const reference t) { return insert_before(pos + 1, t); }
    void insert_before(u32 pos, const reference t);
    void vec_status();  // print the size and capacity of vector
};

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
        array[count] = other[count];
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
        array[count] = other[count];
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
        temp = allocator(this->theSize + WALk_LENGTH);
        for (count = 0; count < theSzie; count++)
        {
            // move all the elements from old pointer to new pointer
            
        }
        this->theSize += 1;
        this->theCapacity += WALk_LENGTH;
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

#endif