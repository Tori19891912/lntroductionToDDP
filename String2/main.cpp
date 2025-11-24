#include <iostream>  
#include <cstring> 
class String {
private:
	char* data;
	size_t length;

public:
	// Конструктор  
	String(const char* str = "")
	{
		if (str == nullptr)
		{
			data = new char; [1] ;
			data = '\0';
			length = 0;
		}
		else
		{
			length = std::strlen(str);
			data = new char[length + 1];
			std::strcpy(data, str);
		}
	}

	// Деструктор  
	~String()
	{
		delete data;
	}

	// Оператор присваивания  
	String& operator=(const String& other)
	{
		// Проверка на самоприсваивание  
		if (this == &other)
		{
			return *this;
		}

		// Освобождаем старую память  
		delete data;

		// Копируем новую строку  
		length = other.length;
		data = new char[length + 1];
		std::strcpy(data, other.data);

		return *this;
	}

	// Метод для вывода строки  
	void print() const {
		std::cout << data << std::endl;
	}
};

// Тестирование  

