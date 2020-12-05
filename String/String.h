#ifndef _MY_STRING_H
#define _MY_STRING_H

#include <iostream>
using std::ostream;
using std::istream;

typedef unsigned int u32;
typedef unsigned char u8;

class String
{
    private:
        char *m_str = nullptr;
        u32 space_len;    // space len of this string
        u32 actual_len;   // character length of this string
        static const u32 min_len = 15;
        static u32 num_of_strings;
    public:
    // constructor and destructor
        String();
        String(const char *str);
        String(const String &s);
        String(u32 len);
        ~String();
    // other function
        u32 capacity() const { return space_len; }
        u32 len() const { return actual_len; }
        u32 str_count() const { return num_of_strings; }
        void set_actual_len(u32 alen) { actual_len = alen; }
        void add(const String &str);
        void add(const char *str);
    // overload operator methods
        String & operator=(const String &str);
        String & operator=(const char *s);
        char & operator[](u32 i);
        const char & operator[](u32 i) const;
        String operator+(const String &str);
        String operator+(const char *str);
        String & operator+=(const String &str);
        String & operator+=(const char *str);
        String operator*(const u32 num);
    // overload operator methods friend
        friend bool operator<(const String &str1, const String &str2);
        friend bool operator>(const String &str1, const String &str2);
        friend bool operator==(const String &str1, const String &str2);
        friend ostream & operator<<(ostream &os, const String &str);
        friend istream & operator>>(istream &is, String &str);
        friend String operator+(const char *str1, const String &str2);
        friend String operator*(const u32 num, const String & str);
};

#endif