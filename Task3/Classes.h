#pragma once
#include <iostream>
#define PI 3.14
using namespace std;

class Circle
{
protected:
	double radius;
public:
	Circle() :Circle(1) {}
	Circle(double radius)
	{
		SetRadius(radius);
	}
	void SetRadius(double radius)
	{
		if (radius > 0)
			this->radius = radius;
		else
			this->radius = 1;
	}
	double GetRadius() const
	{
		return radius;
	}
	double Length() const
	{
		return 2 * PI * radius;
	}
	double Area() const
	{
		return PI * radius * radius;
	}
};

class Square
{
protected:
	double side;
public:
	Square() :Square(1) {}
	Square(double side)
	{
		SetSide(side);
	}
	void SetSide(double side)
	{
		if (side > 0)
			this->side = side;
		else
			this->side = 1;
	}
	double GetSide() const
	{
		return side;
	}
	double Length() const
	{
		return 4 * side;
	}
	double Area() const
	{
		return side * side;
	}
};

class SquareInCircle : public Circle, public Square
{
public:
	SquareInCircle() :SquareInCircle(1) {}
	SquareInCircle(int radius) :Circle(radius), Square(CalcSide(radius)) {}
	SquareInCircle(const Square& square) :Circle(CalcRadius(square.GetSide())), Square(square) {}
	SquareInCircle(const Circle& circle) :Circle(circle), Square(CalcSide(circle.GetRadius())) {}
	double CalcRadius(double side)
	{
		return (side * sqrt(2)) / 2;
	}
	double CalcSide(double radius)
	{
		return (2 * radius) / sqrt(2);
	}
	double GetTotalLenght() const
	{
		return Circle::Length() + Square::Length();
	}
	double GetFigureArea() const
	{
		return Circle::Area() - Square::Area();
	}
	void SetSide(double side)
	{
		if (side > 0)
		{
			this->side = side;
			radius = CalcRadius(side);
		}
	}
	void SetRadius(double radius)
	{
		if (radius > 0)
		{
			this->radius = radius;
			side = CalcSide(radius);
		}
	}
	void Print() const
	{
		cout << "Radius: " << radius << "\tSide: " << side << endl;
		cout << "Circle area:\t" << Circle::Area() << endl;
		cout << "Square area:\t" << Square::Area() << endl;
		cout << "Total length:\t" << GetTotalLenght() << endl;
		cout << "Figure area:\t" << GetFigureArea() << endl;
	}
};