#include "Functions.h"

bool checkBalanceBrackets(const string& text, const size_t stackSize)
{
    for (char c : text)
    {
        Stack<char> stack(stackSize);
        for (char c : text)
        {
            if (c == '(') { stack.push('('); }
            else if (c == ')')
            {
                if (stack.isEmpty() || stack.gettop() != '(') {
                    return false;
                }
                stack.pop();
            }
        }

        return stack.isEmpty();
    }
}

bool check(const string& text)
{
    regex r1("\\+)");
    regex r2("(\\+");
    regex r3("\\-)");
    regex r4("(-");
    regex r5("\\*)");
    regex r6("(\\*");
    regex r7("/)");
    regex r8("(/");
    if (regex_match(text, r1) || regex_match(text, r2) || regex_match(text, r3) || regex_match(text, r4) || regex_match(text, r5)
        || regex_match(text, r6) || regex_match(text, r7) || regex_match(text, r8)) return false;
    else return true;
}

int getPrecedence(char op)
{
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

void getPostfixFromInfix(const string& infix, string& postfix, const size_t stackSize)
{
    Stack<char> operators(stackSize);
    if (checkBalanceBrackets(infix, stackSize)&& check(infix))
    {
        for (char c : infix)
        {
            if (isdigit(c)) { postfix += c; }
            else if (c == '(') { operators.push(c); }
            else if (c == ')')
            {
                while (!operators.isEmpty() && operators.gettop() != '(')
                {
                    postfix += operators.pop();
                }
                if (!operators.isEmpty()) operators.pop();
            }
            else
            {
                while (!operators.isEmpty() && getPrecedence(c) <= getPrecedence(operators.gettop()))
                {
                    postfix += operators.gettop();
                    operators.pop();
                }
                operators.push(c);
            }
        }

        while (!operators.isEmpty()) { postfix += operators.pop(); }
    }
    else throw invalid_argument(ERROR_OF_EXPRESSION);

}
