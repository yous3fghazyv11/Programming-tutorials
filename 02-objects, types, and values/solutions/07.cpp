#include <iostream>

int main() {
	std::cout << "enter a number: ";
	int num;
	std::cin >> num;

	if (num % 2 == 0) std::cout << "the number " << num << " is even\n";
	if (num % 2 == 1) std::cout << "the number " << num << " is odd\n";

	return 0;
}
