#include <iostream>

int main() {
	double mtkm = 1.609; // miles to kilometers conversion ratio

	double miles = 0;
	std::cout << "miles: ";
	std::cin >> miles;
	std::cout << "kms: " << miles * mtkm << '\n';
	return 0;
}
