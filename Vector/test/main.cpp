#include <iostream>
#include "complex.hpp"
using namespace std;


int main()
{
    Complex<int> c1(1,2);
    Complex<int> c2(3,4);
    
    Complex<int> c = c1 + c2;
    
    cout << c << endl;
    
    return 0;
}


