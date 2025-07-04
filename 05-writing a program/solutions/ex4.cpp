#include <iostream>
#include "utils.h"

int npr(int a, int b) {
    return fac(a)/fac(a-b);
}

int ncr(int a, int b) {
    return npr(a, b)/fac(b);
}

int main() {
    for(int a, b; std::cout << "> " && std::cin >> a >> b;) {
        std::cout << npr(a, b) << '\n';
        std::cout << ncr(a, b) << '\n';
    }
    return 0;
}
