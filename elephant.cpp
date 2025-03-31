#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if (n % 5 == 0) { // Fixed syntax error (removed `:` and added `{}`)
        std::cout << n / 5;
    } else {
        std::cout << (n / 5) + 1; // Added parentheses for clarity
    }

    return 0;
}
