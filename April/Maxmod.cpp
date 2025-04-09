#include <iostream> // Required for input/output operations
#include <vector>   // Included but not strictly necessary for this solution approach as we print directly
#include <numeric>  

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t; 
    std::cin >> t;
    
    
    while (t--) { 
        int n; 
        std::cin >> n; // Read n
        
        // Check if n is even using the modulo operator.
        if (n % 2 == 0) {
            std::cout << -1 << "\n";
        } else {
            
            std::cout << n; 
            
            for (int i = 1; i < n; ++i) {
                // Print a space before each subsequent element to ensure the output numbers are space-separated.
                std::cout << " " << i; 
            }
            
            // Print a newline character at the end of the output for the current test case, as required by the problem format.
            std::cout << "\n";
        }
    }
    
    // Return 0 to indicate successful program execution.
    return 0; 
}
