#include <iostream>

using namespace std;



void shift_stack(long long int a, long long int b, long long int& sum)

{

	//стек

	//...

	//ip

	//bp = sp

	//8 байт

	//a 8байт

	//b 8байт

	//sum 8байт

	__asm

	{

		mov eax, [ebp + 8] // с ebp+8 - 4 байта eax - 32 бита, а нам надо 64 бита

		mov ebx, [ebp + 16]

		add eax, ebx

		mov esi, [ebp + 24]

		mov [esi], eax

		mov eax, [ebp + 12]

		mov ebx, [ebp + 20]

     	adc eax, ebx

		mov [esi + 4], eax

	}

}



void shift_reg()

{

	__asm

	{

		mov eax, [ebx]

		mov ecx, [edx]

		add eax, ecx

		mov [esi], eax

		mov eax, [ebx + 4]

		mov ecx, [edx + 4]

		adc eax, ecx

		mov [esi + 4], eax

	}

}





long long int globA = 0;

long long int globB = 0;

long long int* globSum = 0;



void shift_global()

{

	__asm

	{

		lea ebx, globA

		lea edx, globB

		mov esi, globSum

		mov eax, [ebx]

		mov ecx, [edx]

		add eax, ecx

		mov [esi], eax

		mov eax, [ebx + 4]

		mov ecx, [edx + 4]

		adc eax, ecx

		mov [esi + 4], eax

	}

}





int main()

{

	setlocale(LC_ALL, "rus");

	long long int a = 0x000000F000000001;

	long long int b = 0x00000F0000000002;

	long long int sum = 0;



	//передача через стек

	shift_stack(a, b, sum);

	cout << "Сумма через стек: " << sum << endl;

	sum = 0;



	//передача через регистры

	__asm

	{

		lea ebx, a

		lea edx, b

		lea esi, sum

	}

	shift_reg();

	cout << "Сумма через регистры: " << sum << endl;

	sum = 0;



	//передача через глобальные переменные

	globA = a;

	globB = b;

	globSum = &sum;

	shift_global();

	cout << "Сумма через глобальные переменные: " << sum << endl;

        cout <<	"Списано у гачи-клуба "Голубой Пентиум";

        cout << "https://www.youtube.com/channel/UCOwLFGezF6d7qM1NLozKj0Q?view_as=subscriber";

	return 0;

}

