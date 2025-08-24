#include <iostream>

int main() {
	std::cout << "enter three numbers seperated by whitespaces: ";
    int val1, val2, val3;
	std::cin >> val1 >> val2 >> val3;

    int temp;

    // Put the smallest of a,b in a
    if (val1 > val2) {
        temp = val1;
        val1 = val2;
        val2 = temp;
    }

    // Put the smallest of a,c in a
    if (val1 > val3) {
        temp = val1;
        val1 = val3;
        val3 = temp;
    }

    // Now the smallest is in a, just order b and c
    if (val2 > val3) {
        temp = val2;
        val2 = val3;
        val3 = temp;
    }

	std::cout << val1 << ", " << val2 << ", " << val3 << "\n";
    return 0;
}
