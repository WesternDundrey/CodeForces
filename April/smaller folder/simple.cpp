#include <iostream> 
#include <cmath>  

/**
 * @brief Checks if a given number is prime.
 *
 * A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.
 * This function implements a standard primality test optimized for efficiency.
 *
 * @param n The number to check for primality. Should be a positive integer.
 * @return true if n is prime, false otherwise.
 */
bool is_prime(long long n) {
    // Numbers less than or equal to 1 are not prime by definition.
    if (n <= 1) {
        return false;
    }
    // 2 is the smallest and only even prime number.
    if (n == 2) {
        return true;
    }
    // Any other even number is divisible by 2 and thus not prime.
    if (n % 2 == 0) {
        return false;
    }
    long long limit = static_cast<long long>(sqrt(n));
    for (long long i = 3; i <= limit; i += 2) { // Iterate through odd numbers only
        if (n % i == 0) {
            // If n is divisible by any odd number i in this range, it's not prime.
            return false;
        }
    }

    // If the loop completes without finding any divisors, n must be prime.
    return true;
}

int main() {
    // Optimize input/output operations for potentially faster execution.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; 
    std::cin >> t; 

    // Process each test case
    while (t--) {
        long long x; // The base number (can be up to 10^9, so use long long)
        int k;       // The number of repetitions (1 <= k <= 7)
        std::cin >> x >> k; // Read x and k for the current test case


        bool result_is_prime = false; // Initialize the result flag

        // Case 1: k = 1
        // If k is 1, the resulting number y is just x itself.
        if (k == 1) {
            result_is_prime = is_prime(x);
        }
        // Case 2: k > 1 (k is between 2 and 7 based on constraints)
        else {
            if (x == 1) {
                if (k == 2) {
                    result_is_prime = true;
                }
                // For k=3,4,5,6,7, result_is_prime remains false.
            }
            else { // x > 1 and k > 1
                result_is_prime = false;
            }
        }

        // Output the result ("YES" or "NO") for the current test case.
        if (result_is_prime) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0; // Indicate successful program execution
}