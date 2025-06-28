#include <limits>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <algorithm>

void duplicate(std::vector<std::string> names, std::string name) {
    for (std::string n : names) {
        if (n == name) {
            throw std::runtime_error("Name '" + name + "' can't be entered twice");
        }
    }
}

int find_score(std::vector<std::string> names, std::vector<int> scores, std::string name) {
    for (int i = 0; i < names.size(); i++) {
        if (names[i] == name) return scores[i];
    }
    throw std::out_of_range("Name '" + name + "' not found");
}

bool bad_input() {
    if (std::cin.fail()) {
        std::cerr << "Error: bad input\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }
    return false;
}

std::string get_name() {
    std::string name;
    std::getline(std::cin, name);
    if (std::any_of(name.begin(), name.end(), [](unsigned char c) {return std::isspace(c);}))
}

int main() {
    std::string name;
    int score = 0;
    std::vector<std::string> names;
    std::vector<int> scores;

    std::cout << "please enter names and scores ('exit' to stop):\n";
    while (std::cout << "> ") {
        try {
            if (name == "exit") {
                break;
            }
            std::cin >> score;
            if (std::cin.eof()) {
                std::cout << "\nExiting...\n";
                return 0;
            }
            if (bad_input()) {
                continue;
            }
            duplicate(names, name);
            names.push_back(name);
            scores.push_back(score);
        } catch (std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << '\n';
        }
    }
    if (names.empty()) {
        std::cerr << "no input collected\n";
        return 0;
    }
    std::string search_name;
    std::cout << "please type a name and i will return its corresponding score:\n";
    while (std::cin >> search_name) {
        try {
            int found_score = find_score(names, scores, search_name);
            std::cout << "the name " << search_name << " has the score of " << found_score << '\n';
        } catch (std::out_of_range& e) {
            std::cerr << "Error: " << e.what() << '\n';
        }
    }
}
