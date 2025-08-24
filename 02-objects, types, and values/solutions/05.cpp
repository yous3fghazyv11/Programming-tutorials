#include <iostream>

int main() {
	double val1, val2;
	std::cout << "first number: ";
	std::cin >> val1;
	std::cout << "second number: ";
	std::cin >> val2;

	if (val1 > val2) {
		std::cout << "the smaller value is " << val2 << '\n';
		std::cout << "the larger value is " << val1 << '\n';
	}
	if (val1 < val2) {
		std::cout << "the smaller value is " << val1 << '\n';
		std::cout << "the larger value is " << val2 << '\n';
	}

	std::cout << "the sum is " << val1 + val2 << '\n';
	std::cout << "the difference is " << val1 - val2 << '\n';
	std::cout << "the product is " << val1 * val2 << '\n';
	std::cout << "the ratio is " << val1/val2 << '\n'; // now 5/2 gives 2.5 not 2. but what if val2 is zero?

	return 0;
}
