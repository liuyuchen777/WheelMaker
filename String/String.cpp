#include "String.h"
#include <cstring>
using std::cin;
using std::cout;

u32 String::num_of_strings = 0;

// other function
void String::add(const String & str)
{
    u32 temp_len = str.actual_len;
    if ((temp_len + actual_len) <= space_len)
    {
        actual_len += temp_len;
        std::strcat(m_str, str.m_str);
    }
    else
    {
        char *temp = nullptr;
        space_len = 2 * temp_len;
        temp = new char[space_len + 1];
        memset(temp, 0, space_len + 1);
        std::strcat(temp, m_str);
        delete [] m_str;
        std::strcat(temp, str.m_str);
        m_str = temp;
        actual_len = temp_len;
    }
}

void String::add(const char *str)
{
    if (nullptr == str)
    {
        // do nothing
    }
    else
    {
        u32 temp_len = std::strlen(str);
        if ((temp_len + actual_len) <= space_len)
        {
            actual_len += temp_len;
            std::strcat(m_str, str);
        }
        else
        {
            char *temp = nullptr;
            space_len = 2 * temp_len;
            temp = new char[space_len + 1];
            memset(temp, 0, space_len + 1);
            std::strcat(temp, m_str);
            delete [] m_str;
            std::strcat(temp, str);
            m_str = temp;
            actual_len = temp_len;
        }
    }
}

// class methods
String::String()
{
    space_len = min_len;
    actual_len = 0;
    m_str = new char[space_len + 1];
    memset(m_str, 0, space_len + 1);
    num_of_strings++;
}

String::String(u32 len)
{
    if (len > min_len)
        space_len = len;
    else if (len <= min_len)
        space_len = min_len;
    actual_len = 0;
    m_str = new char[space_len + 1];
    memset(m_str, 0, space_len + 1);
}

String::String(const char *str)
{
    if (nullptr == str)
    {
        actual_len = 0;
        space_len = min_len;
        m_str = new char[space_len + 1];
        memset(m_str, 0, space_len + 1);
    }
    else
    {
        u32 temp_len = std::strlen(str);
        if (temp_len <= min_len)
        {
            space_len = min_len;
            actual_len = temp_len;
        }
        else
        {
            space_len = temp_len;
            actual_len = temp_len;
        }
        m_str = new char[space_len + 1];
        std::strcpy(m_str, str);
        num_of_strings++;
    }
}

String::String(const String &str)
{
    u32 temp_len = str.actual_len;
    if (temp_len <= min_len)
    {
        space_len = min_len;
        actual_len = temp_len;
    }
    else
    {
        space_len = temp_len;
        actual_len = temp_len;
    }
    m_str = new char[space_len + 1];
    std::strcpy(m_str, str.m_str);
    num_of_strings++;
}

String::~String()
{
    --num_of_strings;
    delete [] m_str;
}

// overload operator method
String & String::operator=(const char *str)
{
    if (nullptr == str)
    {
        delete [] m_str;
        actual_len = 0;
        space_len = min_len;
        m_str = new char[space_len + 1];
        memset(m_str, 0, space_len + 1);
        return *this;
    }
    else
    {
        u32 temp_len = std::strlen(str);
        delete [] m_str;
        if (temp_len <= min_len)
        {
            space_len = min_len;
            actual_len = temp_len;
        }
        else
        {
            space_len = temp_len;
            actual_len = temp_len;
        }
        m_str = new char[space_len + 1];
        memset(m_str, 0, space_len + 1);
        std::strcpy(m_str, str);

        return *this;
    }
}

String & String::operator=(const String & str)
{
    u32 temp_len = str.actual_len;
    delete [] m_str;
    if (temp_len <= min_len)
    {
        space_len = min_len;
        actual_len = temp_len;
    }
    else
    {
        space_len = temp_len;
        actual_len = temp_len;
    }
    m_str = new char[space_len + 1];
    memset(m_str, 0, space_len + 1);
    std::strcpy(m_str, str.m_str);

    return *this;
}

char & String::operator[](u32 i)
{
    if ((i > actual_len) || (i < 0))
    {
        // 如何处理不合法的i值
        // 1.抛出异常；2.返回一个逻辑空对象
        return *(char *)nullptr;
    }
    else
    {
        return m_str[i];
    }
}

const char & String::operator[](u32 i) const
{
    if ((i > actual_len) || (i < 0))
    {
        return *(char *)nullptr;
    }
    else
    {
        return m_str[i];
    }
}

String String::operator+(const String &str1)
{
    String str(str1.actual_len + this->actual_len);
    str.add(*this);
    str.add(str1);

    return str;
}

String String::operator+(const char *str1)
{
    String str(this->actual_len + std::strlen(str1));
    str.add(*this);
    str.add(str1);

    return str;
}

String & String::operator+=(const String &str)
{
    int temp_len = str.actual_len + actual_len;

    if (temp_len <= space_len)
    {
        actual_len = temp_len;
        std::strcat(m_str, str.m_str);
    }
    else
    {
        char *temp = nullptr;
        space_len = 2 * temp_len;
        temp = new char[space_len + 1];
        memset(temp, 0, space_len + 1);
        std::strcat(temp, m_str);
        delete [] m_str;
        std::strcat(temp, str.m_str);
        m_str = temp;
        actual_len = temp_len;
    }

    return *this;
}

String & String::operator+=(const char *str)
{
    if (nullptr == str)
    {
        return *this;
    }
    else
    {
        int temp_len = std::strlen(str) + actual_len;

        if (temp_len <= space_len)
        {
            actual_len = temp_len;
            std::strcat(this->m_str, str);
        }
        else
        {
            char *temp = nullptr;
            space_len = 2 * temp_len;
            temp = new char[space_len + 1];
            memset(temp, 0, space_len + 1);
            std::strcat(temp, m_str);
            delete [] m_str;
            std::strcat(temp, str);
            m_str = temp;
            actual_len = temp_len;
        }

        return *this;
    }
}

// overload operator friend
ostream & operator<<(ostream & os, const String & str)
{
    os << str.m_str;
    return os;
}

istream & operator>>(istream & is, const String & str)
{
    // consider how to input char effectively

    return is;
}

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.m_str, st2.m_str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.m_str, st2.m_str) == 0);
}

String operator+(const char *str1, const String &str2)
{
    String str(str2.actual_len + std::strlen(str1));
    str.add(str1);
    str.add(str2);

    return str;
}

String String::operator*(const u32 num)
{
    u32 i = 0, j = 0;
    String mstr(num * actual_len);
    mstr.set_actual_len(num * actual_len);
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < actual_len; j++)
        {
            mstr[(actual_len * i) + j] = m_str[j];
        }
    }

    return mstr;
}

String operator*(const u32 num, const String & str)
{
    u32 i = 0, j = 0;
    String mstr(num * str.len());
    mstr.set_actual_len(num * str.len());
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < str.len(); j++)
        {
            mstr[(str.len() * i) + j] = str[j];
        }
    }

    return mstr;
}