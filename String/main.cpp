#include <iostream>

using namespace std;
/* Разработать класс String_ для работы со строками, в классе должны быть:
0) поле char*, в котором будет храниться нультерминированная строка как динамический массив;
1) конструктор по умолчанию, создающий пустую строку;
2) конструктор, принимающий в качестве параметра нультерминированную строку (const char*);
3) конструктор копирования;
4) конструктор перемещения;
5) деструктор;
6) копирующий оператор присваивания;
7) перемещающий оператор присваивания;
8) оператор + для двух String_, возвращающий новый объект, содержащий результат конкатенации строк.
9) оператор == и != для двух String_ */

void str_copy(char* dest, const char* source)
{
    for (; *source; *dest++ = *source++);
    *dest = 0;
}

size_t str_len(const char* source)
{
    size_t len = 0;
    while (*source++) len++;
    return len;
}

class String
{
private:
    size_t size;
    char* str;  //0) поле char*, в котором будет храниться нультерминированная строка как динамический массив;

    void swap(String& other)
    {
        std::swap(size, other.size);
        std::swap(str, other.str);
    }

    String(size_t sz, char* st) :size(sz), str(st) {}
public:
    //1) конструктор по умолчанию, создающий пустую строку;
    String() : size(0), str(new char[1]) { *str = 0; }
    //2) конструктор, принимающий в качестве параметра нультерминированную строку(const char*);
    String(const char* source) : size(str_len(source)), str(new char[size + 1])
    {
        str_copy(str, source);
    }
    //3) конструктор копирования;
    String(const String& other) :String(other.str) {}
    //4) конструктор перемещения;
    String(String&& other) :String()
    {
        swap(other);
    }
    //5) деструктор;
    ~String()
    {
        delete[] str;
    }
    //6) копирующий оператор присваивания;
    String& operator=(const String& other)
    {
        if (this == &other) return *this;
        return *this = String(other);
    }
    //7) перемещающий оператор присваивания;
    String& operator=(String&& other)
    {
        swap(other);
    }
    //8) оператор + для двух String, возвращающий новый объект, содержащий результат конкатенации строк.
    String operator+(const String& rh) const
    {
        size_t new_size = size + rh.size;
        char* new_str = new char[new_size + 1];

        str_copy(new_str, str);
        str_copy(new_str + size, rh.str);

        return String(new_size, new_str);
    }
    //9) оператор == и != для двух String
    bool operator==(const String& other) const
    {
        const char* lh = str;
        const char* rh = other.str;
        for (; *lh && *rh; ++lh, ++rh)
        {
            if (*lh != *rh) return false;
        }
        if (*lh || *rh) return false;
        return true;
    }
};