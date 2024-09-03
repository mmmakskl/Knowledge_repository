#include"Stack.h"
#include"Functions.h"

int main() 
{
    setlocale(LC_ALL, "ru");
    try
    {
        string infix = "";
        string postfix = "";
        size_t stackSize = 0;
        cout << "Введите строку для перевода\t";
        cin >> infix;
        cout << "Введите максимальный размер стека: \t";
        cin >> stackSize;
        getPostfixFromInfix(infix, postfix, stackSize);
        cout << "Выражение в обратной польской записи: " << postfix << endl;
    }
    catch (const exception& ex)
    {
        cerr << ex.what();
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
