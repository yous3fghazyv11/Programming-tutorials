#include <iostream>
#include <stdexcept>

class Token {
public:
    char kind;
    double value;
    Token(char ch) : kind(ch), value(0) {};
    Token(char ch, double val) : kind(ch), value(val) {};
};

class Token_stream {
public:
    void putback(Token t);
    Token get();
    Token_stream() : full{false}, buffer{0} {}
private:
    bool full = false;
    Token buffer;
};

inline void Token_stream::putback(Token t) {
    buffer = t;
    full = true;
}

inline Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }
    char tmp = '\0';
    std::cin >> tmp;
	if (!std::cin) {
		std::cout << "\nExiting...\n";
		exit(0);
	}
    switch (tmp) {
        case '+':
        case '-':
        case '*':
        case '/':
        case 'q':
        case ';':
        case '(':
        case ')':
        case '!':
        case '^':
        case 'h':
            return Token(tmp);
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '.': {
            std::cin.putback(tmp);
            double val = 0;
            std::cin >> val;
            return Token('8', val);
        }
        default:
            throw std::runtime_error("unrecognized token");
    }
}

inline double fac(double n) {
    double result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

inline void help() {
	std::cout << "Available operations:"
			  << "+, -, *, /, ^, !\n";
}
