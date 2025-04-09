#include <iostream> // Required for input/output operations (cin, cout)

int main() {
    // Optional: Improves the speed of input/output operations.
    // This can be helpful in competitive programming where time limits are strict.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Variable to store the number of test cases
    std::cin >> t; // Read the number of test cases from the input

    // Loop through each test case
    while (t--) {
        int k; // Variable to store the number k for the current test case
        std::cin >> k; // Read the value of k from the input
        if (k % 2 != 0) {
            // If k is odd, it's an ideal generator.
            std::cout << "YES\n";
        } else {
            // If k is even, it's not an ideal generator.
            std::cout << "NO\n";
        }

    }

    return 0; // Indicate successful execution
}