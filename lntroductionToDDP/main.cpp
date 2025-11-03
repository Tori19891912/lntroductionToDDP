#include<iostream>
using namespace std;
using namespace std;
using namespace std;

#define tab "\t"
#define delimiter "\n--------------------------------\n"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		//x = 0;
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	
	void set_y(double x)
	{
		this->y = x;
	}
	
	//         Constructors:
    /*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	//CopyConstructor
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Constructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//       Operators:
    Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Left:\t" << this << endl;
		cout << "Left:\t" << &other << endl;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

    //        Methods:
	double distance(const Point& other)const
	{
		//other.x *= 100;
		//other.y *= 100;
		//this->x *= 100;
		//this->y *= 100;
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << ",\tY = " << y << endl;
	}
};

double distance(const Point A,const Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define FOR_COUNTER_LIFETIME
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define OPERATORS_CHECK
//#define Fraction

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	cout << "Hello OOP" << endl;
	int a;
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE_CHECK
    Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_x() << endl;

	Point B;
	B.set_x(7); 
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << delimiter << endl;
	cout << "–ассто€ние от точки 'A' до точки  'B':" << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "–ассто€ние от точки 'B' до точки  'A':" << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "–ассто€ние между точками 'A' и 'B':   " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "–ассто€ние между точками 'B' и 'A':   " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK

#ifdef FOR_COUNTER_LIFETIME
	for (int i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
#endif //FOR_COUNTER_LIFETIME

 
#ifdef CONSTRUCTORS_CHECK
    Point A;       
	A.print();

	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;
	D.print();

	Point E;
	E = D;
	E.print();
	
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
    int a, b, c;

	a = b = c = 0;

	cout << a << tab << b << tab << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	Point(2, 3).print();
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
	cout << sizeof(Point) << endl;
#endif // ASSIGNMENT_CHECK

#ifdef OPERATORS_CHECK
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(7, 8);
	Point C = A + B;
	C.print();
#endif // OPERATORS_CHECK

#ifdef Fraction
     class Fraction
	{
		public int numerator; // числитель
		public int denominator; // знаменатель

		public Fraction(int num, int den)
		{
			numerator = num;
			denominator = den;
		} // конструктор

		public void reWrite() // вывод в консоль рационального числа.
		{
			Console.WriteLine("numerator: " + numerator);
			Console.WriteLine("denominator: " + denominator);
		}

		public void Sum(int a, int b, int c, int d) // —умма двух дробей (a/b) + (c/d) 
		{
			int denom = 0;
			int num = 0;
			int amult = 0;
			int cmult = 0;

			if (b == d) // одинаковый знаменатель
			{
				num = a + c;
				denom = b;
			}

			else // разные знаменатели
			{
				amult = a * d;
				cmult = c * b;
				num = amult + cmult;
				denom = b * d;

			}

			Console.WriteLine("(a/b - c/d) = " + num + " / " + denom);

		}

		public void Substraction(int a, int b, int c, int d) // –азн двух дробей (a/b) - (c/d) 
		{
			int denom = 0;
			int num = 0;
			int amult = 0;
			int cmult = 0;

			if (b == d) // одинаковый знаменатель
			{
				num = a - c;
				denom = b;
			}

			else // разные знаменатели
			{
				amult = a * d;
				cmult = c * b;
				num = amult - cmult;
				denom = b * d;

			}

			Console.WriteLine("(a/b - c/d) = " + num + " / " + denom);

		}

		public void Multiply(int a, int b, int c, int d) // ”множение двух дробей (a/b) * (c/d) 
		{
			int num = a * c;
			int denom = b * d;
			Console.WriteLine("(a/b * c/d) = " + num + " / " + denom);

		}

		public void Division(int a, int b, int c, int d) // ƒеление двух дробей (a/b) / (c/d) 
		{
			int num = a * d;
			int denom = b * c;
			Console.WriteLine("(a/b * c/d) = " + num + " / " + denom);

		}

		public void Transformation(int a, int b) // ѕреобразовани€ дроби в смешанный вид (правильной)
		{
			int whole = a / b;
			int num = a % b;
			int denom = b;
			Console.WriteLine("Whole = " + whole + ", num = " + num + ", denom = " + denom);

		}

		public void Integer_Part(int a, int b) // ¬ыделение целой части из дроби
		{
			int whole = a / b;
			Console.WriteLine("Whole = " + whole);
		}


	}
#endif // Fraction

}
