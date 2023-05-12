#define _USE_MATH_DEFINES
#include<iostream>
#include<Windows.h>
using namespace std;

namespace Geometry
{
	enum Color //Enum (Перечисление) - это набор целочисленных констант
	{
		//  0xAABBGGRR
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,
		white = 0x00FFFFFF,
		grey = 0x00AAAAAA,

		console_default = 0x07,
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_yellow = 0xEE,
		console_white = 0xFF,
	};
	enum Limitations
	{
		MIN_SIZE = 50,
		MAX_SIZE = 550,
		MIN_START_X = 0,
		MIN_START_Y = 0,
		MAX_START_X = 1000,
		MAX_START_Y = 700,
		MIN_LINE_WIDTH = 3,
		MAX_LINE_WIDTH = 30,

	};

#define SHAPE_TAKE_PARAMETERS  unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color
#define SHAPE_GIVE_PARAMETERS  start_x, start_y, line_width, color

	class Shape
	{
	protected:
		unsigned int start_x;
		unsigned int start_y;
		unsigned int line_width;
		Color color;
	public:

		void set_start_x(int start_x)
		{
			if (start_x > Limitations::MAX_START_X)start_x = Limitations::MAX_START_X;
			this->start_x = start_x;
		}
		void set_start_y(int start_y)
		{
			if (start_y > Limitations::MAX_START_Y)start_y = Limitations::MAX_START_Y;
			this->start_y = start_y;
		}
		void set_line_width(int line_width)
		{
			if (line_width < Limitations::MIN_LINE_WIDTH)line_width = Limitations::MIN_LINE_WIDTH;
			if (line_width > Limitations::MAX_LINE_WIDTH)line_width = Limitations::MAX_LINE_WIDTH;
			this->line_width = line_width;
		}
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		unsigned int get_line_width()const
		{
			return line_width;
		}

		Color get_color()const
		{
			return color;
		}
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		
		Shape(SHAPE_TAKE_PARAMETERS) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		virtual ~Shape() {}

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
			if (side1 < Limitations::MIN_SIZE)side1 = Limitations::MIN_SIZE;
			if (side1 > Limitations::MAX_SIZE)side1 = Limitations::MAX_SIZE;
			this->side1 = side1;
		}
		void set_side2(double side2)
		{
			if (side2 < Limitations::MIN_SIZE)side2 = Limitations::MIN_SIZE;
			if (side2 > Limitations::MAX_SIZE)side2 = Limitations::MAX_SIZE;
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
			HDC hdc = GetDC(hwnd); //Контекст устройства oкна консоли.
			//Контекст устройства (Device context) - это то на чем мы рисуем
//Далее идет то, чем мы рисуем:
			HPEN hPen = CreatePen(PS_SOLID, 5, color);//Pen - карандаш, рисует контурную линию
			HBRUSH hBrush = CreateSolidBrush(color); //Brush - кисть, рисует заливку



			//Выбираем, чем и на чем будем рисовать:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//Выполняем рисование:
			//::Rectangle(hdc, start_x, start_y, end_x, end_y);
			::Rectangle(hdc, start_x, start_y, start_x + side1, start_y + side2);


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
		Rectangle(double side1, double side2, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_side1(side1);
			set_side2(side2);
		}
		~Rectangle() {}
	};

	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {}
		~Square() {}
	};

	class Circle :public Shape
	{
		double radius;
	public:
		void set_radius(double radius)
		{
			if (radius < Limitations::MIN_SIZE)radius = Limitations::MIN_SIZE;
			if (radius > Limitations::MAX_SIZE)radius = Limitations::MAX_SIZE;
			this->radius = radius;
		}
		double get_radius()const
		{
			return radius;
		}
		double get_area()const override
		{
			return M_PI * radius * radius;
		}
		double get_perimeter()const override
		{
			return 2 * M_PI * radius;
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Ellipse(hdc, start_x, start_y, start_x + 2 * radius, start_y + 2 * radius);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);

		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Radius: " << radius << endl;
			Shape::info();
		}
		Circle(double radius, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_radius(radius);

		}
		~Circle() {}

	};
	class Triangle : public Shape
	{
	public:
		virtual double get_height()const = 0;

		Triangle(SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS) {}
		~Triangle() {}
		void info()const
		{
			cout << "Высота треугольника: " << get_height() << endl;
			Shape::info();
		}
	};
	class EquilateralTriangle : public Triangle
	{
		double side;
	public:
		EquilateralTriangle(double side, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_side(side);
		}
		~EquilateralTriangle() {}
		void set_side(double side)
		{
			if (side < Limitations::MIN_SIZE)side = Limitations::MIN_SIZE;
			if (side > Limitations::MAX_SIZE)side = Limitations::MAX_SIZE;
			this->side = side;
		}
		double get_side()const
		{
			return side;
		}
		double get_height()const override
		{
			return sqrt(pow(side, 2) - pow(side / 2, 2));
		}
		double get_area()const override
		{
			return side * get_height() / 2;
		}
		double get_perimeter()const override
		{
			return 3 * side;
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT vertex[] =
			{
				{start_x, start_y + side},  //vertex_1
				{start_x + side, start_y + side}, //vertex_2
				{start_x + side / 2, start_y + side - get_height()} // vertex_3
			};

			::Polygon(hdc, vertex, 3);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << side << endl;
			Triangle::info();
		}

	};
		

	/*class Triangle : public Shape
	{
	 public:
		 virtual double get_height()const = 0;

		Triangle(double height, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS) {}
		~Triangle() {}
	};

	class IsoscelesTriangle : public Triangle
	{
	public:
		double side1, side2;
		void set_side1(double side1)
		{
			if (side1 < Limitations::MIN_SIZE)side1 = Limitations::MIN_SIZE;
			if (side1 > Limitations::MAX_SIZE)side1 = Limitations::MAX_SIZE;
			this->side1 = side1;
		}
		void set_side2(double side)
		{
			if (side2 < Limitations::MIN_SIZE)side2 = Limitations::MIN_SIZE;
			if (side2 > Limitations::MAX_SIZE)side2 = Limitations::MAX_SIZE;
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
		double get_height()const override
		{
			return sqrt(side1 * side1 - ((side2 / 2) * (side2 / 2)));
		}
		double get_area()const override
		{
			return 0.5 * side2 * get_height();
		}
		double get_perimeter()const override
		{
			return 2 * side1 + side2;

		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Polygon(hdc, start_x, start_y, start_x + side1, start_y + side2);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Боковые стороны: " << side1 << endl;
			cout << "Основание: " << side2 << endl;
			Triangle::info();
		}
		IsoscelesTriangle(double side1, double side2, SHAPE_TAKE_PARAMETERS) :Triangle(height, SHAPE_GIVE_PARAMETERS)
		{
			set_side1(side1);
			set_side2(side2);
		}
		~IsoscelesTriangle() {}

	};

	class EquilateralTriangle : public Triangle
	{
	public:
		double side;
		void set_side(double side)
		{
			if (side < Limitations::MIN_SIZE)side = Limitations::MIN_SIZE;
			if (side > Limitations::MAX_SIZE)side = Limitations::MAX_SIZE;
			this->side = side;
		}
		double get_side()const
		{
			return side;
		}
		double get_height()const override
		{
			return (side * sqrt(3))/2;
		}
		double get_area()const override
		{
			return 0.5 * side * get_height();
		}
		double get_perimeter()const override
		{
			return 3 * side;
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Polygon(hdc, start_x, start_y, start_x + side);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Стороны треугольника: " << get_side() << endl;
			Triangle::info();
		}
		EquilateralTriangle(double side, SHAPE_TAKE_PARAMETERS) :Triangle(height, SHAPE_GIVE_PARAMETERS)
		{
			set_side(side);
		}
		~EquilateralTriangle() {}
	};

	class ScaleneTriangle :public Triangle
	{
		double side1, side2, side3;
		void set_side1(double side1)
		{
			if (side1 < Limitations::MIN_SIZE)side1 = Limitations::MIN_SIZE;
			if (side1 > Limitations::MAX_SIZE)side1 = Limitations::MAX_SIZE;
			this->side1 = side1;
		}
		void set_side2(double side)
		{
			if (side2 < Limitations::MIN_SIZE)side2 = Limitations::MIN_SIZE;
			if (side2 > Limitations::MAX_SIZE)side2 = Limitations::MAX_SIZE;
			this->side2 = side2;
		}
		void set_side3(double side)
		{
			if (side3 < Limitations::MIN_SIZE)side3 = Limitations::MIN_SIZE;
			if (side3 > Limitations::MAX_SIZE)side3 = Limitations::MAX_SIZE;
			this->side3 = side3;
		}
		double get_side1()const
		{
			return side1;
		}
		double get_side2()const
		{
			return side2;
		}
		double get_side3()const
		{
			return side3;
		}
		double get_height()const override
		{
			return 2 / side3 * sqrt(((side1 + side2 + side3) / 2) * (((side1 + side2 + side3) / 2) - side3) * (((side1 + side2 + side3) / 2) - side1) * (((side1 + side2 + side3) / 2) - side2));
		}
		double get_area()const override
		{
			return 0.5 * side3 * get_height();
		}
		double get_perimeter()const override
		{
			return side1 + side2+ side3;

		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Polygon(hdc, start_x, start_y, start_x + side1, start_y + side2);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Боковые стороны: " << side1 << ", " << side2 << endl;
			cout << "Основание: " << side3 << endl;
			Triangle::info();
		}
		ScaleneTriangle(double side1, double side2, double side3, SHAPE_TAKE_PARAMETERS) :Triangle(height, SHAPE_GIVE_PARAMETERS)
		{
			set_side1(side1);
			set_side2(side2);
			set_side3(side3);
		}
		~ScaleneTriangle() {}

	};*/
}


void main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {};
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &coord);
	setlocale(LC_ALL, "");

	//Shape shape;

	Geometry::Square square(150, 100, 400, 25, Geometry::Color::red);
	/*cout << "Длина стороны квадрата: " << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	square.draw();*/
	square.info();

	Geometry::Rectangle rect(250, 80, 360, 370, 5, Geometry::Color::blue);
	rect.info();

	Geometry::Circle circle(55, 710, 345, 5, Geometry::Color::yellow);
	circle.info();

	Geometry::EquilateralTriangle t_eq(300, 700, 100, 25, Geometry::Color::green);
	t_eq.info();

	/*Geometry::IsoscelesTriangle isosceles(Geometry::Color::grey);
	isosceles.info();

	Geometry::EquilateralTriangle  equilateral(Geometry::Color::white);
	equilateral.info();

	Geometry::ScaleneTiangle  scalene(Geometry::Color::blue);
	scalene.info();*/



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




