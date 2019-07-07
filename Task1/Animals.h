#pragma once
#include <iostream>
#include <string>
using namespace std;

class Animal abstract
{
protected:
	string name;
	int age;
public:
public:
	Animal() : Animal("Unknown", 0) {}
	Animal(string name, int age)
	{
		SetName(name);
		SetAge(age);
	}
	void SetAge(int age)
	{
		if (age >= 0)
			this->age = age;
	}
	void SetName(string name)
	{
		if (name.size() > 0)
			this->name = name;
	}
	virtual string Sound() const abstract;

	virtual string Type() const abstract;

	int GetAge() const
	{
		return age;
	}
	string GetName() const
	{
		return name;
	}
	virtual void Print() const
	{
		cout << "Name: " << name << "\tAge: " << age << "\tType: " << Type() << "\tSays: " << Sound() << endl;
	}
};

class Dog : public Animal
{
private:
	string breed;
public:
	Dog(string name = "Noname dog", int age = 0, string breed = "Unknown") :
		Animal(name, age)
	{
		SetBreed(breed);
	}
	void SetBreed(string breed)
	{
		if (breed.size() >= 0)
			this->breed = breed;
	}
	void Print() const override
	{
		cout << "Name: " << name << "\tAge: " << age << "\tType: " << Type() << "\tBreed: " << breed << "\tSays: " << Sound() << endl;
	}
	string Type() const override
	{
		return "Dog";
	}
	string Sound() const override
	{
		return "Woof!";
	}
};

enum Fur { Short, Medium, Long };

class Cat : public Animal
{
private:
	string breed;
	Fur fur;
public:
	Cat(string name = "Noname cat", int age = 0, string breed = "Unknown", Fur fur = Short) :
		Animal(name, age)
	{
		SetBreed(breed);
		SetFur(fur);
	}
	void SetFur(Fur fur)
	{
		this->fur = fur;
	}

	string GetFur() const
	{
		switch (fur)
		{
		case Short:
			return "short";
			break;
		case Medium:
			return "medium";
			break;
		case Long:
			return "long";
			break;
		}
		return "Unknown";
	};
	void SetBreed(string breed)
	{
		if (breed.size() >= 0)
			this->breed = breed;
	}
	void Print() const override
	{
		cout << "Name: " << name << "\tAge: " << age << "\tType: " << Type() << "\tBreed: " << breed << "\tSays: " << Sound() << "\tFur: " << GetFur() << endl;
	}
	string Type() const override
	{
		return "Cat";
	}
	string Sound() const override
	{
		return "Meow!";
	}
};

class Parrot : public Animal
{
private:
	string breed;
public:
	Parrot(string name = "Noname cat", int age = 0, string breed = "Unknown") :
		Animal(name, age)
	{
		SetBreed(breed);
	}
	void SetBreed(string breed)
	{
		if (breed.size() >= 0)
			this->breed = breed;
	}
	void Print() const override
	{
		cout << "Name: " << name << "\tAge: " << age << "\tType: " << Type() << "\tBreed: " << breed << "\tSays: " << Sound() << endl;
	}
	string Type() const override
	{
		return "Parrot";
	}
	string Sound() const override
	{
		return "Polly wants some cracker!";
	}
};
class Hamster : public Animal
{
private:
	string breed;
public:
	Hamster(string name = "Noname cat", int age = 0, string breed = "Unknown") :
		Animal(name, age)
	{
		SetBreed(breed);
	}
	void SetBreed(string breed)
	{
		if (breed.size() >= 0)
			this->breed = breed;
	}
	void Print() const override
	{
		cout << "Name: " << name << "\tAge: " << age << "\tType: " << Type() << "\tBreed: " << breed << "\tSays: " << Sound() << endl;
	}
	string Type() const override
	{
		return "Hamster";
	}
	string Sound() const override
	{
		return "Frr Frr";
	}
};

class HomeZoo
{
private:
	vector <Animal*> zoo;
public:
	//конструктор(зоопарк  пустий)
	HomeZoo() {}
	//деструктор, вилучити всі тваринки з вектору
	//(спочатку слід вилучити динамічні об’єкти тваринок, потім можна  очищати елементи вектору zoo.clear())
	~HomeZoo()
	{
		for (int i = 0; i < zoo.size(); i++)
			delete zoo[i];
		zoo.clear();
	}
	//додавання певної тваринки у Зоопарк на замовлення користувача(запитати тип тваринки, кличку, вік, додаткові характеристики, створити динамічний екземпляр тваринки та додати до вектору
	void AddAnimal()
	{
		int animal, age;
		string name, breed;
		do
		{
			cout << "Choose animal to add:\n";
			cout << "1 - Dog.\n";
			cout << "2 - Cat.\n";
			cout << "3 - Parrot.\n";
			cout << "4 - Hamster.\n";
			cin >> animal;
			if (animal < 1 || animal > 4)
				cout << "Error. Invalid input.";
		} while (animal < 1 || animal > 4);
		do
		{
			cout << "Enter animal breed:";
			cin >> breed;
			if (name.size() == 0)
				cout << "Error. Invalid input.";
		} while (name.size() == 0);
		do
		{
			cout << "Enter animal name:";
			cin >> name;
			if (name.size() == 0)
				cout << "Error. Invalid input.";
		} while (name.size() == 0);
		do
		{
			cout << "Enter animal age:\n";
			cin >> age;
			if (age < 0)
				cout << "Error. Invalid input.";
		} while (age < 0);
		switch (animal)
		{
		case 1:
			zoo.push_back(new Dog(name, age, breed));
			break;
		case 2:
			Fur fur;
			int selection;
			do
			{
				cout << "Enter fur length:\n";
				cout << "1 - Short.\n";
				cout << "2 - Medium.\n";
				cout << "3 - Long.\n";
				cin >> selection;
			} while (selection < 1 || selection > 3);
			switch (selection)
			{
			case 1:
				fur = Short;
				break;
			case 2:
				fur = Medium;
				break;
			case 3:
				fur = Long;
				break;
			}
			zoo.push_back(new Cat(name, age, breed, fur));
			break;
		case 3:
			zoo.push_back(new Parrot(name, age, breed));
			break;
		case 4:
			zoo.push_back(new Hamster(name, age, breed));
			break;
		default:
			break;
		}
	}
	//метод автоматичного додавання кількох "випадкових" тваринок у зоопарк
	//метод виведення усіх  тваринок зоопарку
	void Show() const
	{
		cout << "HomeZoo:\n";
		for (int i = 0; i < zoo.size(); i++)
		{
			cout << "#" << i + 1 << " ";
			zoo[i]->Print();
		}
	}
	//метод редагування тваринки(редагується назва чи вік, не тип тваринки)
	//метод вилучення(продажу) тваринки з зоопарку
	void Sell()
	{
		if (zoo.size() == 0)
		{
			cout << "There's noone to sell.\n";
			return;
		}
		int selection;
		do
		{
			cout << "Enter number of animal to sell: ";
			cin >> selection;
			if (selection < 1 || selection > zoo.size())
				cout << "Error. Invalid input.\n";
		} while (selection < 1 || selection > zoo.size());
		zoo.erase(zoo.begin() + selection - 1);
	}
	//метод вилучення(продажу) всіх тваринок
	void SellAll()
	{
		if (zoo.size() > 0)
		{
			for (int i = 0; i < zoo.size(); i++)
				delete zoo[i];
			zoo.clear();
		}
	}
};