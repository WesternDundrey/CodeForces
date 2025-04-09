#include <iostream> 
#include <string> 
#include <algorithm> 

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; 
    std::cin >> t; 
    // Process each test case individually
    while (t--) {
        std::string n_str; 
        std::cin >> n_str;
        int l = n_str.length(); 
        int max_subsequence_length = 0; 
        int current_zero_count = 0;  

        // Iterate through each character (digit) of the input string n_str
        for (int i = 0; i < l; ++i) {
            if (n_str[i] == '0') {
                // If the current digit is '0', increment the count of available zeros
                current_zero_count++;
            } else {
                int current_subsequence_len = current_zero_count + 1;

                max_subsequence_length = std::max(max_subsequence_length, current_subsequence_len);
            }
        }

        int min_removed_digits = l - max_subsequence_length;

        // Print the result for the current test case followed by a newline.
        std::cout << min_removed_digits << "\n";
    }

    return 0; 
}