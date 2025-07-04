/* Simple calculator program
 * Grammar:
 * Expression:
 *   Term
 *   Term + Term*
 *   Term - Term*
 * Term:
 *   Primary
 *   Primary * Primary*
 *   Primary / Primary*
 *   Primary ^ Primary
 * Primary:
 *   Number
 *   Number!
 *   (Expression)
 *   (Expression)!
 */


#include "utils.h"
#include <cmath>
#include <stdexcept>

Token_stream ts;

double expression();
double term();
double primary();

double expression() {
    double left = term();
    Token next = ts.get();
    while (true) {
        switch (next.kind) {
        case '+':
            left += term();
            next = ts.get();
            break;
        case '-':
            left -= term();
            next = ts.get();
            break;
        default:
            ts.putback(next);
            return left;
        }
    }
}

double term() {
    double left = primary();
    Token next = ts.get();
    while (true) {
        switch (next.kind) {
        case '*':
            left *= primary();
            next = ts.get();
            break;
        case '/': {
            double d = primary();
            if (d == 0) {
                throw std::runtime_error("division by zero");
            }
            left /= d;
            next = ts.get();
            break;
        }
        case '^':
            left = std::pow(left, primary());
            next = ts.get();
            break;
        default:
            ts.putback(next);
            return left;
        }
    }
}

double primary() {
    Token t = ts.get();
    switch (t.kind) {
        case '8': {
            Token next = ts.get();
            if (next.kind == '!') {
                return fac(t.value);
            }
            ts.putback(next);
            return t.value;
        }
        case '(': {
            double left = expression();
            Token next = ts.get();
            if (next.kind != ')') {
                throw std::runtime_error("')' Exprected");
            }
            Token is_fac = ts.get();
            if (is_fac.kind == '!') {
                return fac(left);
            }
            ts.putback(is_fac);
            return left;
        }
        default:
            throw std::runtime_error("primary expected");
    }
}

int main() try {
    while (true) {
        std::cout << "> ";
        Token check = ts.get();
        if (check.kind == 'q') {
            std::cout << "Exiting...\n";
            exit(0);
        }
        if (check.kind == 'h') {
            help();
            continue;
        }
        ts.putback(check);
        double ans = expression();
        Token next = ts.get();
        if (next.kind == ';') {
            std::cout << "= " << ans << '\n';
        }
    }
} catch (std::runtime_error& e) {
    std::cerr << "Error: " << e.what() << '\n';
} catch (...) {
    std::cerr << "unexpected error accoured\n";
}
