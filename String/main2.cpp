#include <iostream>
#include <string>
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

class String_
{
public:
    char* str[]; //поле char*, в котором будет храниться нультерминированная строка как динамический массив;

    String_() //конструктор по умолчанию, создающий пустую строку
    {
        cout << "str" << endl;
        *str = new char[10];
    }

    String_(const char* str) //конструктор, принимающий в качестве параметра нультерминированную строку (const char*);
    {
        str = new char[1];
    }

    String_(const String_& s) // конструктор копирования;
    {
        cout << "copy" << endl;
        *str = new char[10];

        for (int i = 0; i < 10; i++)
        {
            *s.str[i] = *s.str[i];
        }
    }

    String_(String_&& s) // конструктор перемещения;
    {
        cout << "перемещение" << endl;
        delete[]str;
        *str = new char[10];
        *str = *s.str;
        *s.str = nullptr;
    }

    ~String_()
    {
        cout << "~str~" << endl;
        delete[]str;
    }

    String_& operator = (const String_& a) // копирующий оператор присваивания
    {
        cout << "=копирование";
        delete[]str;
        *str = new char[10];

        for (int i = 0; i < 10; i++)
        {
            *a.str[i] = *a.str[i];
            return *this;
        }
    }

    String_& operator=(String_&& a) // перемещающий оператор присваивания
    {
        if (&a == this)
        {
            return *this;
        }
        delete[]str;
        *str = *a.str;
        *a.str = nullptr;
        return *this;
    }

    String_ operator + (String_& s)  //оператор + для двух String_, возвращающий новый объект, содержащий результат конкатенации
    {
        char str1[10] = "wadaw";
        char str2[10] = "cxvcx";
        for (int i = 0; i < 10; i++)
        {
            s.str[i] = str1 + str2[i];
        }
        return *s.str;
    }

    String_ operator ==(String_& s) //оператор == и != для двух String_
    {
        char str1[10] = "wadaw";
        char str2[10] = "cxvcx";
        for (int i = 0; i < 10; i++)
        {
            s.str[i] = str1 + str2[i];
        }
        return *s.str;
    }

    String_ operator !=(String_& s) //оператор == и != для двух String_
    {
        char str1[10] = "wadaw";
        char str2[10] = "cxvcx";
        for (int i = 0; i < 10; i++)
        {
            s.str[i] = str1 + str2[i];
        }
        return *s.str;
    }
private:

};

String_ f()
{
    String_ A;
    return A;
}

int main()
{
    setlocale(0, "");

    String_ a;
    a = a;
}