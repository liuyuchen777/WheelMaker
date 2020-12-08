#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>
using namespace std;

template <typename T>
class Complex 
{
public:

    friend ostream & operator<<(ostream &out, Complex<T> const &c)
    {
        out << c.a << " + " << c.b << "i" << endl;
        out << "I am here anyway";
        return out;
    }
    
public:
    Complex(T a, T b);
    
    //运算符重载+
    Complex<T> operator+(Complex<T> &c);
    
    //普通加法函数
    Complex<T> myAdd(Complex<T> &c1, Complex<T> &c2);
    
private:
    T a;
    T b;
};

template <typename T>
Complex<T>::Complex(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <typename T>
Complex<T> Complex<T>::operator+(Complex<T> &c)
{
    Complex temp(this->a + c.a, this->b + c.b);
    return temp;
}

template <typename T>
Complex<T> Complex<T>::myAdd(Complex<T> &c1, Complex<T> &c2)
{
    Complex temp(c1.a + c2.a, c1.b + c2.b);
    return temp;
}

#endif