#include <iostream>

// there's no way to exit this program without entering invalid operator or number

int main()
{
    char op;
    float num1, num2;
    while (true) {
        std::cin >> op;
        if (op != '+' && op != '-' && op != '*' && op != '/') {
            std::cout << "invalid operator\n";
            return -1; // indicating failure
        }
        std::cin >> num1 >> num2;
        if (op == '+') {
            std::cout << num1 + num2 << '\n';
        }
        if (op == '-') {
            std::cout << num1 - num2 << '\n';
        }
        if (op == '*') {
            std::cout << num1 * num2 << '\n';
        }
        if (op == '/') {
            std::cout << num1 / num2 << '\n';
        }
    }
    return 0;
}
