#include <iomanip>
#include <fstream>
#include "recursion_func.h"

int main()
{
    setlocale(LC_ALL, "russian");
    std::cout << std::boolalpha;
    std::ifstream in;
    std::ofstream out;
    out << std::boolalpha;
    in.open(IN_FILE);
    if (!in)
    {
        std::cerr << "Can not open input file" << IN_FILE << std::endl;
        return EXIT_FAILURE;
    }

    out.open(OUT_FILE);
    if (!out)
    {
        std::cerr << "Can not open output file " << OUT_FILE << std::endl;
        return EXIT_FAILURE;
    }
    std::size_t i = 1;
    while (!in.eof())
    {

        std::string inputString;
        std::getline(in, inputString);
        std::cout << "Число №" << (i) << ": " << inputString << " - " << isRealNumber(inputString) << std::endl;
        out << "Число №" << (i) << ": " << inputString << " - " << isRealNumber(inputString) << std::endl;
        i++;
    }

    // +123.45E+6 True
    // -0.567E-3 True
    // +.789E+2 True
    // 4.321 False
    // 0E+5 False
    // -12E-4 True
    // -9.87 False
    // -42.3EE+4 False
    // +3.2g+4 False
    // +123.45E+6qwerty123 False
}
