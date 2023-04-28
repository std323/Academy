#include<iostream>
using namespace std;


class Figure
{

public:
	virtual void square() = 0;
	virtual void perimeter() = 0;

};

class Square : public Figure
{
private:
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
		cout << 3,14 * r * r;
	}

	void perimeter() const 
	{            
		cout << 2 * 3,14 * r;
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
	void calc_perimeter() const 
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

	cout << "Прямоугольник: ";
	figure[1] = new Rectangle(6, 7);
	cout << "Площадь: ";
	figure[1]->square();
	cout << "Периметр: ";
	figure[1]->perimeter();

	cout << "Круг: ";
	figure[2] = new Circle(6);
	cout << "Площадь: ";
	figure[2]->square();
	cout << "Периметр: ";
	figure[2]->perimeter();

	cout << "Треугольник: ";
	figure[2] = new Triangle(3, 5, 6);
	cout << "Площадь: ";
	figure[2]->square();
	cout << "Периметр: ";
	figure[2]->perimeter();


}