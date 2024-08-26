#include"Introsort.h"

int main()
{
	std::cout << "___________Introsort for an array of 1000 elements___________\n";
	countTimeOfIntrosort(1000);
	std::cout << "\n___________Introsort for an array of 10000 elements___________\n";
	countTimeOfIntrosort(10000);
	std::cout << "\n___________Introsort for an array of 100000 elements___________\n";
	countTimeOfIntrosort(100000);
	std::cout << "\n___________Introsort for an array of 500000 elements___________\n";
	countTimeOfIntrosort(500000);
	return EXIT_SUCCESS;
}

