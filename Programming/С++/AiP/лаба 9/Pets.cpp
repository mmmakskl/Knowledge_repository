#include "Pets.h"

std::string Pet::getName()const
{
	return name_;
}

// ����� Cat
Cat::Cat() { name_ = "������ ����������"; }
Cat::Cat(const std::string& name) { name_ = name; }
Cat::~Cat(){}
std::string Cat::voice()const{	return "*����� ����*";}
std::string Cat::name()const { return "CAT"; }


//����� Dog
Dog::Dog() { name_ = "������ �����������"; }
Dog::Dog(const std::string& name) { name_ = name; }
Dog::~Dog(){}
std::string Dog::voice()const { return "*����� ������*"; }
std::string Dog::name()const { return "DOG"; }


//����� FamilyPets
FamilyPets::FamilyPets() { count_ = 0; countMax_ = 0;  }
FamilyPets::FamilyPets(int countMax) { count_ = arr_.size(); countMax_ = countMax; }
FamilyPets::~FamilyPets(){}

void FamilyPets::voice()const
{
	for (Pet *pet : arr_) std::cout<<pet->voice()<<"\n";
}

void FamilyPets::name()const
{
	for (Pet* pet : arr_) std::cout<<pet->name()<<"\n";
	
}

void FamilyPets::operator+(Pet *pet)
{
	if (count_ < countMax_)
	{
		arr_.push_back(pet);
		count_++;
	}
	else throw std::runtime_error(ERROR_OVERFLOW);
}

std::istream& operator>>(std::istream& stream, Pet& pet)
{
	stream >> pet.name_;
	return stream;
}

//������������� ������� ��� ������ FamilyPets
void isPetInFamily(FamilyPets& pets, std::string& name)
{
	bool petInFamily = false;
	for (Pet* pet : pets.arr_)
	{
		if (pet->getName() == name)
		{
			std::cout << pet->name() << "\n";
			petInFamily = true;
		}
	}
	if (!petInFamily) std::cout << "������ � ����� ������ �����������\n";
}

std::ostream& operator<<(std::ostream& stream, FamilyPets& pets)
{
	if (pets.arr_.size() == 0) stream << "������ ����\n";
	else 
	{
		for (Pet* pet : pets.arr_)
			stream << "�����: " << pet->name() << "  ���: " << pet->getName() << "  �����: " << pet->voice() << "\n";
	}
	return stream;
}


int checkInput(std::string& count)
{
	std::regex regular("\\d+,?0*");
	std::regex replace("\\.");
	count = std::regex_replace(count, replace, ",");
	if (std::regex_match(count, regular)) return std::stoi(count);
	else throw std::invalid_argument(ERROR_OF_INPUT);
}
//�������� �������
void testClasses()
{
	try 
	{
		std::cout << "\n\n------------------------------------------------\n";
		std::cout << "������� ������������ ���������� ��������:  ";
		std::string value;
		std::cin >> value;
		FamilyPets pets (checkInput(value));
		FamilyPets emptyPets;
		std::cout << "emptyPets:  " << emptyPets;
		Cat cat1;
		std::cout << "������� ������ ����:  ";
		std::cin >> cat1;
		pets + &cat1;
		Cat cat2;
		pets + &cat2;
		Dog dog1;
		std::cout << "������� ������ ������:  ";
		std::cin >> dog1;
		pets + &dog1;
		Dog dog2;
		pets + &dog2;
		std::cout << "\n���� �������� � pets:\n";
		pets.name();
		std::cout << "\n������ �������� � pets:\n";
		pets.voice();
		std::cout<<"\n\npets:\n" << pets;
		std::cout << "\n\n�������� �������. ������� ������ ���������:  ";
		std::cin >> value;
		isPetInFamily(pets, value);

	}
	catch (std::runtime_error& ex)
	{
		std::cout << ex.what();
		exit(EXIT_FAILURE);
	}
	catch (std::invalid_argument& ex)
	{
		std::cout << ex.what();
		exit(EXIT_FAILURE);
	}
}
