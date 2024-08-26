#include<iostream>
#include"functions.h"

int main()
{
	setlocale(LC_ALL, "ru");
	const string EXPRESSION1 = "1+2-7*2/3";	//проверяемаое выражение
	const string EXPRESSION2 = "1+2a-7*2/3";	//проверяемаое выражение
	if (isExpression(EXPRESSION1)) cout << "Выражение 1 соответствует правилу\n";
	else cout << "Выражение  1 не соответствует правилу\n";
	if (isExpression(EXPRESSION2)) cout << "Выражение 2 соответствует правилу\n";
	else cout << "Выражение 2 не соответствует правилу\n";
	return 0;
}
