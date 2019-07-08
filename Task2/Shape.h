#pragma once
#include <iostream>
#define PI 3.14
using namespace std;

class Shape abstract
{
public:
	//чисті віртуальні функції print(), printShapeName() – без реалізації
	virtual void Print() const abstract;
	virtual void PrintShapeName() const abstract;
	//віртуальні функції аrea(), volume(), що повертають нульове значення.
	virtual double Area() const
	{
		return 0;
	}
	virtual double Volume() const
	{
		return 0;
	}
};

class Point : public Shape
{
public:
	void Print() const override
	{
		PrintShapeName();
		cout << "Area: " << Area() << "\tVolume: " << Volume() << endl;
	}
	void PrintShapeName() const override
	{
		cout << "Point" << endl;
	}
};

class Circle : public Point
{
private:
	int radius;
public:
	Circle() :Circle(1) {}
	Circle(int radius)
	{
		SetRadius(radius);
	}
	void SetRadius(int radius)
	{
		if (radius > 0)
			this->radius = radius;
	}
	double Area() const override
	{
		return PI * radius * radius;
	}
	void PrintShapeName() const override
	{
		cout << "Circle" << endl;
	}
};

class Cylinder : public Circle
{
private:
	int length;
public:
	Cylinder(int radius = 1, int length = 2) :Circle(radius)
	{
		SetLength(length);
	}
	void SetLength(int length)
	{
		if (length > 0)
			this->length = length;
	}
	double Volume() const override
	{
		return Area() * length;
	}
	void PrintShapeName() const override
	{
		cout << "Cylinder" << endl;
	}
};