#ifndef MYSTRING
#define MYSTRING

typedef unsigned int uint;

class MyString
{
    private:
        char *m_str = nullptr;
        uint str_len = 0;
    public:
        MyString(void);
        MyString(char *str);
        ~MyString(void);
        uint my_str_len(void);
        // reload operator
};

#endif