#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<char> uniqueLetters;
    std::string input;
    
    std::cin >> input;  // Read input as a string

    // Insert each character into the set (duplicates automatically removed)
    for (char c : input) {
        uniqueLetters.insert(c);
    }

    // Check the size of the set
    if (uniqueLetters.size() % 2 == 0) {
        std::cout << "CHAT WITH HER!" << std::endl;
    } else {
        std::cout << "IGNORE HIM!" << std::endl;
    }

    return 0;
}
