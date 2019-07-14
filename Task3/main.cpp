#include <iostream>
#include "Classes.h"
using namespace std;

int main()
{
	Square sq(3);
	SquareInCircle obj2(sq);
	SquareInCircle obj(10);
	obj2.Print();
	cout << "Circle area:\t" << obj2.Circle::Area() << endl;
	cout << "Total length:\t" << obj2.GetTotalLenght() << endl;
	cout << "Figure area:\t" << obj2.GetFigureArea() << endl;
	obj.Print();
	cout << "Circle area:\t" << obj.Circle::Area() << endl;
	cout << "Total length:\t" << obj.GetTotalLenght() << endl;
	cout << "Figure area:\t" << obj.GetFigureArea() << endl;
	obj.SetRadius(5);
	obj.Print();
	cout << "Circle area:\t" << obj.Circle::Area() << endl;
	cout << "Total length:\t" << obj.GetTotalLenght() << endl;
	cout << "Figure area:\t" << obj.GetFigureArea() << endl;
	system("pause");
	return 0;
}