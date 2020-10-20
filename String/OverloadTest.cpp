#include <iostream>
#include <stdio.h>

using namespace std;

class Box
{
private:
    int m_x, m_y;
public:
    Box() { m_x = 0; m_y = 0; }
    Box(int x, int y) : m_x(x), m_y(y) {}
    Box operator+(const Box &box2);
    Box & operator=(const Box &box);
};

Box & Box::operator=(const Box &box)
{
    cout << "I am in =" << endl;
    this->m_x = box.m_x;
    this->m_y = box.m_y;

    return *this;
}

Box Box::operator+(const Box &box2)
{
    cout << "I am in +" << endl;
    Box m_box;
    m_box.m_x = this->m_x + box2.m_x;
    m_box.m_y = this->m_y + box2.m_y;
    
    return m_box; 
}

int main(void)
{
    Box box1(1, 2);
    Box box2(1000, 2000);
    Box box3;

    printf("box1 = %p, box2 = %p, box3 = %p\n", &box1, &box2, &box3);
    box1 = box1 + box2;
    printf("box1 = %p, box2 = %p, box3 = %p\n", &box1, &box2, &box3);

    return 0;
}