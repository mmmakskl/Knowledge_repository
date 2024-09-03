#include <iostream>
#include <string>
#include <vector>

int sum(std::string x, int lenght)
{
    int sum = 0;
    for(std::size_t i = 0; i < lenght; i++)
    {
        sum += x[i] - '0';
    }
    return sum;
}

// std::string generateLuckyNumber(std::string right, std::string left, int n)
// {
//     int sumLeft = sum(left, left.size());
//     int i = n/2-1;
//     while (sumLeft != 0)
//     {
//         int number = std::min(9, sumLeft);
//         right[i] = '0' + number;
//         sumLeft -= number;
//         i--;
//     }
//     return right;
// }

// std::string add(std::string number, int n)
// {
//     number = std::to_string(stoi(number) + 1);

//     while(number.size() < n/2)
//     {
//         number = '0' + number;
//     }

//     return number;
// }

// int main()
// {
//     std::string x;
//     std::cin >> x;
//     int n = x.size();

//     std::string left = x.substr(0, n/2);
//     std::string right = x.substr(n/2, n/2);
//     right = add(right, n);
//     while (sum(left, n/2) != sum(right, n/2))
//     {
//         if (sum(right, right.size()) == (right[right.size()-1] - '0') && sum(left, n/2) > sum(right, right.size()) && right != std::string(n/2, '0'))
//         {
//             right = generateLuckyNumber(right, left, n);
//             break;
//         }
//         if(right.size() > n/2)
//         {
//             left = add(left, n);
//             if(left != std::string(n/2, '0'))
//             {
//                 right = generateLuckyNumber(right, left, n);
//                 break;
//             }
//         }
//         if (left.size() > n/2)
//         {
//             if(right == std::string(n/2, '0'))
//                 right = add(right, n);
//             left = generateLuckyNumber(left, right, n);
//             break;
//         }
//         right = add(right, n);
//     }
//     x = left + right;
//     std::cout << x << std::endl;

//     return 0;
// }


#include <iostream>
#include <string>
#include <vector>

bool isHappy(const std::string& num)
{
    int n = num.size();
    int half = n / 2;
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < half; ++i)
    {
        sum1 += num[i] - '0';
    }
    for (int i = half; i < n; ++i)
    {
        sum2 += num[i] - '0';
    }
    return (sum1 == sum2 && sum1 > 0);
}

std::string findNextHappy(std::string num) {
    int n = num.size();
    std::string minHappy(n, '0');
    minHappy[n/2-1] = minHappy[n-1] = '1';
    std::string current = num;

    while (true)
    {
        bool carry = true;
        for (int i = n - 1; i >= 0 && carry; --i)
        {
            if (current[i] < '9')
            {
                current[i]++;
                carry = false;
            }
            else
            {
                current[i] = '0';
            }
        }

        if (carry)
            return minHappy;

        if (isHappy(current))
            return current;
    }
}

int main()
{
    std::string x;
    std::cin >> x;

    std::cout << findNextHappy(x) << std::endl;
    return 0;
}
