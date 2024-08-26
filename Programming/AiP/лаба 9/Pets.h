#pragma once
#include<iostream>
#include<regex>
#include<vector>

const std::string ERROR_OVERFLOW = "Достигнуто максимальное значение,объект не может быть добавлен\n";
const std::string ERROR_OF_INPUT = "Некорректный ввод\n";

class Pet
{
	friend std::istream& operator >> (std::istream& stream, Pet &pet);
public:
	virtual std::string voice()const = 0;
	virtual std::string name()const = 0;
	std::string getName()const;
protected:
	std::string name_;
};

class Cat :public Pet
{
public:
	Cat();
	Cat(const std::string& name);
	~Cat();
	std::string voice()const override;
	std::string name()const override;
};

class Dog :public Pet
{
public:
	Dog();
	Dog(const std::string& name);
	~Dog();
	std::string voice()const override;
	std::string name()const override;
};

class FamilyPets
{
	friend void isPetInFamily(FamilyPets &pets,std::string& name);
	friend std::ostream& operator << (std::ostream& stream, FamilyPets& pets);
public:
	FamilyPets();
	FamilyPets(int countMax);
	~FamilyPets();
	void voice()const;
	void name()const;
	void operator + (Pet *pet);
private:
	int count_, countMax_;
	std::vector <Pet*> arr_;
};

void testClasses();
int checkInput(std::string& count);