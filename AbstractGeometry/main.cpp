#include<iostream>
#include<Windows.h>
using namespace std;

namespace Geometry
{
	enum Color //Enum (Перечисление) - это набор целочисленных констант
	{
		console_default = 0x07,
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_yellow = 0xEE,
		console_white = 0xFF,
	};
	enum Dimensions
	{
		MIN_SIZE = 5,
		MAX_SIZE = 15,
	};

	class Shape
	{
	protected:
		Color color;
	public:
		Shape(Color color) :color(color) {}
		virtual ~Shape() {}

		Color get_color()const
		{
			return color;
		}
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;

		virtual void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Площадь фигуры: " << get_area() << endl;
			cout << "Периметр фигуры: " << get_perimeter() << endl;
			draw();
		}
	};

	/*class Square : public Shape
	{
		double side;
	public:
		void set_side(double side)
		{
			if (side < Dimensions::MIN_SIZE)side = Dimensions::MIN_SIZE;
			if (side > Dimensions::MAX_SIZE)side = Dimensions::MAX_SIZE;
			this->side = side;
		}
		double get_side()const
		{
			return side;
		}
		double get_area()const override
		{
			return side * side;
		}
		double get_perimeter()const override
		{
			return side * 4;
		}
		void draw()const override
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << side << endl;
			Shape::info();
		}
		Square(double side, Color color) :Shape(color)
		{
			set_side(side);
		}

	};*/

	class Rectangle :public Shape
	{
		double side1, side2;
	public:
		void set_side1(double side1)
		{
			if (side1 < Dimensions::MIN_SIZE)side1 = Dimensions::MIN_SIZE;
			if (side1 > Dimensions::MAX_SIZE)side1 = Dimensions::MAX_SIZE;
			this->side1 = side1;
		}
		void set_side2(double side2)
		{
			if (side2 < Dimensions::MIN_SIZE)side2 = Dimensions::MIN_SIZE;
			if (side2 < Dimensions::MAX_SIZE)side2 = Dimensions::MAX_SIZE;
			this->side2 = side2;
		}
		double get_side1()const
		{
			return side1;
		}
		double get_side2()const
		{
			return side2;
		}
		double get_area()const override
		{
			return side1 * side2;
		}
		double get_perimeter()const
		{
			return 2 * (side1 + side2);
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd); //Кекст устройства oкна консоли.
			                       //Контекст устройства (Device context) - это то на чем мы рисуем
			//Далее идет то, чем мы рисуем:
 			HPEN hPen = CreatePen(PS_SOLID, 5, color);//Pen - карандаш, рисует контурную линию
			HBRUSH hBrush = CreateSolidBrush(color); //Brush - кисть, рисует заливку



			//Выбираем, чем и на чем будем рисовать:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//Выполняем рисование:
			//::Rectangle(hdc, start_x, start_y, end_x, end_y);
			::Rectangle(hdc, 400, 400, 700, 500);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);


		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Сторона 1: " << side1 << endl;
			cout << "Сторона 2: " << side2 << endl;
			Shape::info();
		}
		Rectangle(double side1, double side2, Color color) : Shape(color)
		{
			set_side1(side1);
			set_side2(side2);
		}
	~Rectangle() {}
	};

	class Square :public Rectangle
	{
	public:
		Square(double side, Color color):Rectangle(side, side, color) {}
		~Square() {}
		
	};

	class Circle :public Shape
	{
		double radius;
	public:
		void set_radius(double radius)
		{
			if (radius < Dimensions::MIN_SIZE)radius = Dimensions::MIN_SIZE;
			if (radius > Dimensions::MAX_SIZE)radius = Dimensions::MAX_SIZE;
			this->radius = radius;
		}
		double get_radius()const
		{
			return radius;
		}
		double get_area()const override
		{
			return 3.14 * radius * radius;
		}
		double get_perimeter()const override
		{
			return 2 * 3.14 * radius;
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			Ellipse(hdc, 200, 200, 400, 400);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);

		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Радиус круга: " << radius << endl;
			Shape::info();
		}
		Circle(double radius, Color color) : Shape(color)
		{
			set_radius(radius);
			
		}
		~Circle() {}

	};
}

void main()
{
	setlocale(LC_ALL, "");

	//Shape shape;

	//Geometry::Square square(5, Geometry::Color::console_red);
	/*cout << "Длина стороны квадрата: " << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	square.draw();*/
	//square.info();

	//Geometry::Rectangle rect(8, 5, Geometry::Color::console_blue);
	//rect.info();

	Geometry::Circle circle(7, Geometry::Color::console_green);
	circle.info();


}
/*class Figure
{

public:
	virtual void square() const = 0;
	virtual void perimeter() const = 0;

};

class Square : public Figure
{
	double a;
public:
	Square(double side_a): a(side_a) {}
	void square() const
	{
		cout << a * a;
	}
	void perimeter() const
	{
		cout << 4 * a;
	}
	
};

class Rectangle : public Figure
{
private:
	double a, b;
public:
	Rectangle(double side_a, double side_b)	: a(side_a), b(side_b) {}
	void square() const
	{
		cout << a * b;
	}
	void perimeter() const
	{
		cout << 2 * (a + b);
	}
};

class Circle : public Figure
{
private:

	double r;
public:
	Circle(double radius): r(radius) {}
	
	void square() const 
	{          
		cout << 3.14 * r * r;
	}

	void perimeter() const 
	{            
		cout << 2 * 3.14 * r;
	}

};

class Triangle : public Figure
{
private:
	double a, b, c;
public:
	Triangle(double side_a, double side_b, double side_c)
	: a(side_a), b(side_b), c(side_c) {}

	void square() const 
	{          
		double p = a + b + c;
		cout << sqrt(p * (p - a) * (p - b) * (p - c));
	}
	void perimeter() const 
	{           
		cout << a + b + c;
	}
};


void main()
{
	setlocale(LC_ALL, "");

	Figure** figure = new Figure* [4];
	
	cout << "Квадрат: ";
	figure[0] = new Square(4);
	cout << "Площадь: ";
	figure[0]->square();
	cout << "Периметр: ";
	figure[0]->perimeter();
	delete figure[0];

	cout << "Прямоугольник: ";
	figure[1] = new Rectangle(6, 7);
	cout << "Площадь: ";
	figure[1]->square();
	cout << "Периметр: ";
	figure[1]->perimeter();
	delete figure[1];

	cout << "Круг: ";
	figure[2] = new Circle(6);
	cout << "Площадь: ";
	figure[2]->square();
	cout << "Периметр: ";
	figure[2]->perimeter();
	delete figure[2];

	cout << "Треугольник: ";
	figure[3] = new Triangle(3, 5, 6);
	cout << "Площадь: ";
	figure[3]->square();
	cout << "Периметр: ";
	figure[3]->perimeter();
	delete figure[3];

	delete[] figure;*/




