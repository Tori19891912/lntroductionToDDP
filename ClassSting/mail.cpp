//String (ClassString)
#include<Windows.h>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------\n"

int StringLlength(const char str[]);
char* ToUpper(char str[]);
char* ToL0wer(char str[]);
//NULL Terminated Linnes
//#define LINES_BASEICS_1

void main()
{
	cout << 'Ё' << "\t" << 'Ё' << endl;
	cout << (int)'Ё' << "\t" << (int)'Ё' << endl;;
	cout << 'A' - 'a' << endl;
	cout << endl;
	setlocale(LC_ALL, "");

#ifdef LINES_BASEICS_1
	//char str[] = { 'H', 'e', 'l','l','o', '\0' };
	//char str[] = { 'H', 'e', 'l','l','o', 0 };
	char str[] = "Hello";
	cout << str << endl;
	cout << sizeof(str) << endl;

#endif // LINES_BASEICS_1

	const int SIZE = 256;
	char str[SIZE] = {};
	cout << "Хорошо живет на свете винипух";
	SetConsoleCP(1251);
	//cin >> str;
	//cin.getline(str, SIZE);
	SetConsoleCP(866);
	cout << str << endl;

	cout << sizeof(str) << endl;
	cout << typeid(str).name() << endl;
	cout << StringLlength(str) << endl;
	//ToUpper(str);
	//cout << str << endl;
	cout << ToUpper(str) << endl;
	cout << ToUpper(str) << endl;
}

int StringLlength(const char str[])
{
	/*cout << delimiter << endl;
	cout << sizeof(str) << endl;
	cout << typeid(str).name() << endl;*/
	int i = 0;
	for (; str[i]; i++);
	return i;
}
char* ToUpper(char str[])
{
	//for (int i = 0; i < 256; i++)cout << i << tab << (char)i << endl;
	for (int i = 0; str[i]; i++)
	{
		/*if (str[i] >= 'a' && str[i] <= 'z')str[i] -= ' ';
		if (str[i] >= 'a' && str[i] <= 'я')str[i] -= ' ';
		if (str[i] == 'ё') str[i] -= 16;*/
		str[i] = tolower(str[i]);
	}
	return str;
}
char* ToLower(char str[])
{
	//for (int i = 0; i < 256; i++)cout << i << tab << (char)i << endl;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')str[i] -= ' ';
		if (str[i] >= 'A' && str[i] <= 'Я')str[i] -= ' ';
		if (str[i] == 'Ё') str[i] += 16;
		str[i] = tolower(str[i]);
	}
	return str;
}