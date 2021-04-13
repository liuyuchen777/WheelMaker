#ifndef _VECTOR_H_
#define _VECTOR_H_

#define TT_LEVEL			(0)

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

#endif