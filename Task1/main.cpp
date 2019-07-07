#include <iostream>
#include <vector>
#include "Animals.h"
using namespace std;

int main()
{
	vector<Animal*> animals;
	animals.push_back(new Dog("Rex", 2, "Hound"));
	animals.push_back(new Cat("Tom", 1, "British", Short));
	animals.push_back(new Parrot("Poly", 1, "Cockatoo"));
	animals.push_back(new Hamster("Fluffy", 1, "Chinese"));

	for (auto elem : animals)
		elem->Print();

	int i = 0;
	for (auto elem : animals)
		delete animals[i++];

	animals.clear();
	cout << "------------- deleted animals ----------\n";

	for (auto elem : animals)
		elem->Print();
	system("pause");
	return 0;
}