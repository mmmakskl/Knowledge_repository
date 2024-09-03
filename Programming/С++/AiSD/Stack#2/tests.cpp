#include "Queue.hpp"
#include "Stack.hpp"

void test()
{
    std::cout << "Stack class test: " << std::endl << std::endl;
    {
        StackArray<int> stack(5);

        std::cout << "Stack creation" << std::endl;
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        std::cout << "stack: " << stack << std::endl;

        std::cout << "Stack copying" << std::endl;
        StackArray<int> copy;
        copy = stack;
        std::cout << "copy: " << copy;

        stack.pop();
        stack.pop();
        std::cout << "stack: " << stack << std::endl;

        std::cout << "Stack movement" << std::endl;
        StackArray<int> move(std::move(stack));
        std::cout << "move: " << move;
        std::cout << "stack: " << stack << std::endl;

        std::cout << "Empty stack creation" << std::endl;
        StackArray<int> test1;
        std::cout << "Empty stack: "<< test1 << std::endl;
    }

    std::cout << "===================================" << std::endl << std::endl;

    std::cout << "Queue class test: " << std::endl << std::endl;
    {
        std::cout << "Queue creation " << std::endl;
        QueueArray<int> queue(5);
        queue.enQueue(1);
        queue.enQueue(2);
        queue.enQueue(3);
        queue.enQueue(4);
        queue.enQueue(5);

        std::cout << "queue: " << queue << std::endl;

        std::cout << "Queue copying" << std::endl;
        QueueArray<int> copy;
        copy = queue;
        std::cout << "copy: " << copy << std::endl;
        std::cout << "queue: " << queue << std::endl;

        std::cout << "Deleting an item " << std::endl;
        queue.deQueue();
        queue.deQueue();
        std::cout << "queue: " << queue << std::endl;

        std::cout << "Stack movement" << std::endl;
        QueueArray<int> move(std::move(queue));
        std::cout << "move: " << move;
        std::cout << "queue: " << queue << std::endl;

        std::cout << "Empty queue creation " << std::endl;
        QueueArray<int> test;
        std::cout << "Empty queue: " << test << std::endl;
    }

    std::cout << "===================================" << std::endl << std::endl;

    std::cout << "Test of checkBalanceBrackets function: " << std::endl << std::endl;
    {
        const std::string text1 = ""; // Yes
        const std::string text2 = "a(b[c]d)e"; // Yes
        const std::string text3 = "a(b[c)d]e"; // No
        const std::string text4 = "((({}{{}{{[][]]}}})))"; // No
        const std::string text5 = "[(({([fs{da}])}))]"; // Yes
        std::cout << "Empty" << text1 << " : " << (checkBalanceBrackets(text1, 1) ? "Yes" : "No" ) << std::endl;
        std::cout << text2 << " : " << (checkBalanceBrackets(text2, 10) ? "Yes" : "No" ) << std::endl;
        std::cout << text3 << " : " << (checkBalanceBrackets(text3, 10) ? "Yes" : "No" ) << std::endl;
        std::cout << text4 << " : " << (checkBalanceBrackets(text4, 22) ? "Yes" : "No" ) << std::endl;
        std::cout << text5 << " : " << (checkBalanceBrackets(text5, 21) ? "Yes" : "No" ) << std::endl;
    }
    return;

}

bool checkBalanceBrackets(const std::string& text, const std::size_t maxDeep)
{
    StackArray<char> brackets(maxDeep);
    for(char c : text)
    {
        switch (c)
        {
            case '(':
                brackets.push(c);
                break;
            case '[':
                brackets.push(c);
                break;
            case '{':
                brackets.push(c);
                break;
            case ')':
                if(brackets.isEmpty() || brackets.top() != '(')
                    return false;
                brackets.pop();
                break;
            case ']':
                if(brackets.isEmpty() || brackets.top() != '[')
                    return false;
                brackets.pop();
                break;
            case '}':
                if(brackets.isEmpty() || brackets.top() != '{')
                    return false;
                brackets.pop();
                break;
            default:
                break;
        }
    }
    return brackets.isEmpty();
}