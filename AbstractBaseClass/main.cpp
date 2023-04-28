#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
	int capacity;
public:
	virtual void move() = 0;
};

class AirVehicle :public Vehicle
{
	int height;
public:
	virtual void take_off() = 0;
	virtual void land() = 0;
};
class Helicopter :public AirVehicle
{
public:
	void move()
	{
		cout << "Летает на винте" << endl;

	}
	void take_off()
	{
		cout << "Взлетает с места" << endl;
	}
	void land()
	{
		cout << "Где захочу, там и сяду" << endl;
	}
};
class AirPlain :public AirVehicle
{
public:
	void take_off()
	{
		cout << "Для взлета нужен разгон, а для разгона нужна взлетная полоса" << endl;

	}
	void land()
	{
		cout << "Посадка выполняется на высокой скорости, а значит тоже нужна взлетная полоса" << endl;

	}
	void move()
	{
		cout << "Летает на высокой скорости" << endl;

	}
};


void main()
{
	setlocale(LC_ALL, "");
	//Vehicle v;
	//AirVehicle av;
	
	Helicopter apache;
	apache.take_off();
	apache.move();
	apache.land();
	
	AirPlain boeing;
	boeing.take_off();
	boeing.move();
	boeing.land();

}