#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Book
{
    string UDK;
    string autor;
    string name;
    int year;
    int amount;
    Book* next;
};

void add(Book** beg, Book** end);
void add(char* str, Book** beg, Book** end);
void show(Book* beg, Book* end);
void search(Book* beg, Book** a = 0, const int n = 100);


int main()
{
    // 1) Определение и инициализация:

    setlocale(0, "rus");

    char answear;
    Book* beg = 0;
    Book* end = beg;



    // 2) Создание базы:

    cout << "Загрузить данные из файла? (y/n)" << endl;
    cin >> answear;

    switch (answear)
    {
    case 'y':
    {
        ifstream fin("base.txt");
        if (!fin)
        {
            cout << "Файл не найден. Без обид, я просто его не вижу." << endl;
            return 0;
        }
        const int n = 80;
        char buf[n];
        while (!fin.eof())
        {
            fin.getline(buf, sizeof(buf));
            add(buf, &beg, &end);
        }
        break;
    }
    case 'n': break;
    default: cout << "Неправильный ввод" << endl;
    }

    // 3) Главное меню:

    cout << "Добро пожаловать в библиотеку!" << endl;
    while (true)
    {
        system("cls");
        cout << "Выберите ваши  действия:" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "| 1) Найти книги                                      |" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "| 2) Добавить новую книгу                             |" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "| 3) Списать книгу                                    |" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "| 4) Вывести список книг                              |" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "| 5) Выйти                                            |" << endl;
        cout << "-------------------------------------------------------" << endl;
        cin >> answear;
        switch (answear)
        {
        case '1': search(beg); break;
        case '2': add(&beg, &end); break;
        case '3': /*clear()*/; break;
        case '4': show(beg, end); break;
        case '5': return 0;
        default: cout << "Неправильно" << endl;
        }
    }
    system("pause");
    return 0;

}

.........


void search(Book* beg, Book** a = 0, const int n = 100)
{
    int i = 0;
    string UDK;
    string autor;
    string name;
    int year;
    int amount;

    cout << "Укажите ключи:" << endl;
    cout << "Введите УДК:....."; cin >> UDK;
    cout << "Год издания:....."; cin >> year;
    cout << "Автор:..........."; getline(cin, autor);
    cout << "Название книги:.."; getline(cin, name);

    while (beg && i != n)
    {
        if (UDK == beg->UDK ||
            year == beg->year ||
            autor == beg->autor ||
            name == beg->name)
        {
            a[i] = beg;

        }

        beg++;
        i++;
    }

    Book* buf;
    year = a[0]->year;
    for (i = 0; a[i]; i++)
    {
        for (int j = 1; a[i]; j++)
            if (a[i]->year < year)
            {
                buf = a[i];
                a[i] = a[j];
                a[j] = buf;
            }
    }

    for (i = 0; a[i]; i++)
    {
        cout << endl << "УДК:............." << a[i]->UDK;
        cout << endl << "Год издания:....." << a[i]->year;
        cout << endl << "Автор:..........." << a[i]->autor;
        cout << endl << "Название книги:.." << a[i]->name;
        cout << endl << "Количество:......" << a[i]->amount;
        cout << endl << endl;
    }

    return;
}

void search(Book* beg, Book** a = 0, const int n = 100)


void search(Book* beg, Book** a, const int n)