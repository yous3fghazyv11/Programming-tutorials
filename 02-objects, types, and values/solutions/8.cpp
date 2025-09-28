#include <iostream>

int main() {
	std::cout << "enter a spelled out number: ";
	std::string x;
	std::cin >> x;
	if (x == "one") {
		std::cout << "You typed: 1\n";
	}
	else if (x == "two") {
		std::cout << "You typed: 2\n";
	}
	else if (x == "three") {
		std::cout << "You typed: 3\n";
	}
	else if (x == "four") {
		std::cout << "You typed: 4\n";
	} else {
		std::cout << "not a number i know!\n";
	}

	return 0;
}
