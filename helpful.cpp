#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;

    std::vector<int> numbers;
    std::stringstream ss(s);
    std::string temp;

    // Extract numbers
    while (std::getline(ss, temp, '+')) {
        numbers.push_back(std::stoi(temp));
    }

    // Sort numbers
    std::sort(numbers.begin(), numbers.end());

    // Reconstruct the sorted sum
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i];
        if (i < numbers.size() - 1) {
            std::cout << "+";
        }
    }

    return 0;
}
