#include <iostream>
#include <vector>
#include "Shape.h"
using namespace std;

int main()
{
	vector<Shape*> shapes;
	shapes.push_back(new Point);
	shapes.push_back(new Circle);
	shapes.push_back(new Cylinder);

	for (auto elem : shapes)
		elem->Print();

	for (int i = 0; i < shapes.size(); i++)
		delete shapes[i];
	shapes.clear();

	system("pause");
	return 0;
}