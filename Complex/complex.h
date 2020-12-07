#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>
#include <cmath>

using namespace std;

typedef int u32;
typedef double f32;

class Complex{
	private:
		f32 m_real;
		f32 m_image;
	public:
		// construct function
		Complex() : m_real(0.0), m_image(0.0) {}
		Complex(double r, double i) : m_real(r), m_image(i) {}
		Complex(const Complex &c);
		~Complex() {};
		// other function
		Complex conj(void);
		f32 real(void) const { return m_real; }
		f32 image(void) const { return m_image; }
		void set_real(f32 r) { m_real = r; }
		void set_image(f32 i) { m_image = i; }
		void set(f32 r, f32 i) { m_real = r; m_image = i; }
		void set(const Complex &c) { m_real = c.real(); m_image = c.image(); }
		f32 norm();
		// operator overload
		Complex & operator=(const Complex c);
		Complex operator+(const Complex c);
		Complex operator-(const Complex c);
		Complex & operator+=(const Complex c);
		Complex & operator-=(const Complex c);
		Complex operator*(const Complex c);
		Complex operator*(const u32 num);
		Complex operator*(const f32 num);
		// friend overload
		friend ostream & operator<<(ostream &os, const Complex &c);
		friend Complex operator*(u32 num, const Complex & c);
		friend Complex operator*(f32 num, const Complex & c);
		friend f32 distance(const Complex &c1, const Complex &c2);
};

#endif