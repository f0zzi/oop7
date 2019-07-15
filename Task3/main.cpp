#include <iostream>
#include "Classes.h"
using namespace std;

int main()
{
	Square sq(3);
	cout << "Square sq(3)" << endl;
	SquareInCircle obj2(sq);
	cout << "SquareInCircle obj2(sq)" << endl;
	obj2.Print();
	cout << endl;
	Circle cr(3);
	cout << "Circle cr(3)" << endl;
	SquareInCircle obj3(cr);
	cout << "SquareInCircle obj3(cr)" << endl;
	obj3.Print();
	cout << endl;
	SquareInCircle obj(10);
	cout << "SquareInCircle obj(10)" << endl;
	obj.Print();
	cout << endl;
	cout << "obj.SetRadius(5)" << endl;
	obj.SetRadius(5);
	obj.Print();
	system("pause");
	return 0;
}