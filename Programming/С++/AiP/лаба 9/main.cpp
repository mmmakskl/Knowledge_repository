#include"Pets.h"

int main()
{
	setlocale(LC_ALL , "ru");
	Cat cat;
	std::cout << "Объект класса: " << cat.name() << "  Голос: " << cat.voice()<<"\n";
	Dog dog;
	std::cout << "Объект класса: " << dog.name() << "  Голос: " << dog.voice() << "\n";
	Cat* pCat = &cat;
	std::cout << "Указатель на объект класса Cat\n Класс: " << pCat->name() << "  Голос: " << pCat->voice() << "\n";
	Dog* pDog = &dog;
	std::cout << "Указатель на объект класса Dog\n Класс: " << pDog->name() << "  Голос: " << pDog->voice() << "\n";
	Pet* pPet;
	pPet = &cat;
	std::cout << "Указатель на объект класса Pet\n Класс: " << pPet->name() << "  Голос: " << pPet->voice() << "\n";
	pPet = &dog;
	std::cout << "Указатель на объект класса Pet\n Класс: " << pPet->name() << "  Голос: " << pPet->voice() << "\n";
	testClasses();
	return 0;
}