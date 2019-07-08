#include <iostream>
#include <Windows.h>
#include <vector>
#include "Animals.h"
using namespace std;

int main()
{
	cout << "Task1 --------------------------------------\n";
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
	for (auto elem : animals)
		elem->Print();

	system("pause");
	system("cls");

	cout << "Task1.1 --------------------------------------\n";

	int selection;
	HomeZoo zoo;
	do
	{
		system("cls");
		zoo.Show();
		cout << "Zoo menu:\n";
		cout << "1 - Add animal.\n";
		cout << "2 - Add few \"random\" animals.\n";
		cout << "3 - Edit animal.\n";
		cout << "4 - Sell animal.\n";
		cout << "5 - Sell all animals.\n";
		cout << "0 - Exit.\n";
		cout << "Make your selection: ";
		cin >> selection;
		switch (selection)
		{
		case 1:
			zoo.AddAnimal();
			break;
		case 2:
			zoo.AddRandom();
			break;
		case 3:
			zoo.Edit();
			break;
		case 4:
			zoo.Sell();
			break;
		case 5:
			zoo.SellAll();
			break;
		case 0:
			cout << "Have a nice day.\n";
			break;
		default:
			cout << "Invalid input. Try again.\n";
			system("pause");
			break;
		}
	} while (selection != 0);

	system("pause");
	return 0;
}