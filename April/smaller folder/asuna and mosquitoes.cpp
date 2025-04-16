#include <iostream>
#include <vector>
#include <numeric> // Included for completeness, but std::accumulate not used
#include <algorithm> // Included for completeness, but std::max_element not used

// Function to solve a single test case
void solve() {
    int n; // Number of towers
    std::cin >> n;
    
    // Using long long for heights and sum to prevent potential overflow
    // Maximum sum can be n * max(a_i) = 2e5 * 1e9 = 2e14, which fits in long long.
    std::vector<long long> a(n); 
    long long current_max = 0; // Variable to store the maximum height encountered
    long long total_sum = 0; // Variable to store the sum of all heights
    int odd_count = 0; // Counter for towers with odd height
    
     
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i]; 
        total_sum += a[i];
        
        
        if (a[i] % 2 != 0) { 
            odd_count++; 
        }
        
        
        if (a[i] > current_max) {
            current_max = a[i];
        }
    }
    
    
    if (odd_count == 0 || odd_count == n) {
        std::cout << current_max << "\n";
    } else {
        
        std::cout << total_sum - odd_count + 1 << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    
    int t; 
    std::cin >> t;
    while (t--) {
        solve(); 
    }
    return 0;
}