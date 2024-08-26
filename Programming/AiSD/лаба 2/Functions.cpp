#include "Functions.h"

bool checkBalanceBrackets(const std::string& text, const int maxDeep)
{
    StackArray <char> stack(std::to_string(2*maxDeep));
    for (char symbol : text)
        stack.push(symbol);
    int round_brackets = 0;
    int square_brackets = 0;
    int figure_brackets = 0;
    char symbol = ' ';
    while (!stack.isEmpty())
    {
        symbol = stack.pop();
        switch (symbol)
        {
        case')':
            if (square_brackets < 0 || figure_brackets < 0) return false;
            else { round_brackets++; break; }
        case'(':
            if (round_brackets == 0) return false;
            else 
            { 
                round_brackets--; 
                if (round_brackets == 0 && (square_brackets != 0 || figure_brackets != 0)) return false;
                break;
            }
        case ']': 
            if (round_brackets < 0 || figure_brackets < 0) return false;
             else { square_brackets++; break; }
        case'[':
            if (square_brackets == 0) return false;
            else 
            { 
                square_brackets--; 
                if (square_brackets == 0 && (round_brackets != 0 || figure_brackets != 0)) return false;
                break; 
            }
        case'}':
            if (square_brackets < 0 || round_brackets < 0) return false;
            else { figure_brackets++; break; }
        case'{':
            if (figure_brackets == 0) return false;
            else 
            {
                figure_brackets--; 
                if (figure_brackets == 0 && (round_brackets != 0 || square_brackets != 0)) return false;
                break; 
            }
        default: break;
        }
    }
    return round_brackets ==0 && square_brackets==0 && figure_brackets ==0;
}

bool checkInput(const std::string& value)
{
        std::regex regular("-?\\d+");
        return std::regex_match(value, regular) ? true : false;
}
