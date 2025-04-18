#include <iostream>

// Use the standard namespace for convenience in competitive programming contexts.
using namespace std;

// Define long long as ll for brevity, useful for handling large integer inputs.
typedef long long ll;

// Function to check if it's possible to place k desks such that
// the maximum bench length is at most L.
// Parameters:
// n: number of rows in the grid
// m: number of spots per row in the grid
// k: total number of desks to place
// L: the maximum allowed bench length (candidate value from binary search)
bool check(ll n, ll m, ll k, ll L) {
    // If the maximum allowed length L is 0, it's impossible to place any desks
    // since k >= 1 as per problem constraints. The binary search starts L from 1,
    // so this base case `L==0` check is technically redundant but harmless.
    if (L == 0) return false; 

    // Calculate the maximum number of desks that can be placed in a single row
    // such that no bench (contiguous block of desks) has length greater than L.
    // The formula derived from maximizing desks by placing benches of length L
    // separated by single empty spots is: floor(m / (L+1)) * L + (m % (L+1)).
    // This uses integer division and the modulo operator.
    ll desks_per_row = (m / (L + 1)) * L + (m % (L + 1));
    
    // Handle the edge case where there are no rows (n = 0).
    // If n=0, we can only satisfy the requirement if k=0.
    // Since the problem constraints state k >= 1, this check effectively
    // handles n=0 by returning false if k>=1.
    if (n == 0) {
         return k == 0; 
    }

    // For m >= 1 and L >= 1, desks_per_row will always be at least 1.
    // Proof:
    // If m < L+1, then floor(m/(L+1)) = 0. desks_per_row = 0*L + m % (L+1) = m. Since m >= 1, desks_per_row >= 1.
    // If m >= L+1, then floor(m/(L+1)) >= 1. desks_per_row = floor*L + r >= 1*L >= 1 (since L >= 1).
    // Thus, desks_per_row is guaranteed to be positive.

    // To check if k desks can be placed in total across n rows, we compare
    // the maximum capacity per row (`desks_per_row`) with the required average number
    // of desks per row needed to reach k desks. The required average is ceil(k/n).
    // Calculating ceil(k/n) using integer arithmetic: (k + n - 1) / n.
    // This avoids potential overflow from multiplying n * desks_per_row directly,
    // although direct multiplication would likely be safe given the problem constraints (n*m <= 10^18 fits in long long).
    // This approach is generally safer against potential overflow corner cases.
    ll required_avg_per_row = (k + n - 1) / n; 

    // If the maximum number of desks we can fit in a row is at least the required average per row,
    // then it is possible to distribute the k desks across the n rows without exceeding
    // the maximum bench length L in any row.
    return desks_per_row >= required_avg_per_row;
}


int main() {
    // Optimize standard I/O operations for speed, common in competitive programming.
    ios_base::sync_with_stdio(false); // Untie C++ standard streams from C stdio.
    cin.tie(NULL); // Prevent `cin` from flushing `cout` automatically.

    int t; // Variable to store the number of test cases.
    cin >> t; // Read the number of test cases.
    
    // Process each test case.
    while (t--) {
        ll n, m, k; // Variables for grid dimensions (n rows, m columns) and number of desks k.
        cin >> n >> m >> k; // Read input values for the current test case.

        // Perform binary search to find the minimum possible value for the maximum bench length (L).
        // The search space for L is [1, m].
        ll low = 1; // Minimum possible maximum bench length is 1.
        ll high = m; // Maximum possible maximum bench length is m (one long bench).
        ll ans = m; // Initialize the answer to the maximum possible value (worst case).

        while (low <= high) {
            // Calculate the midpoint 'mid' safely to avoid potential overflow with (low + high).
            ll mid = low + (high - low) / 2; 
            
            // Check if it's possible to place k desks with 'mid' as the maximum allowed bench length.
            if (check(n, m, k, mid)) {
                // If it's possible, 'mid' is a feasible maximum length.
                // We record it as a potential answer and try to find an even smaller feasible length.
                // So, we search in the lower half: [low, mid-1].
                ans = mid;
                high = mid - 1;
            } else {
                // If it's not possible with 'mid', the maximum length must be larger.
                // We need to search in the upper half: [mid+1, high].
                low = mid + 1;
            }
        }
        // After the binary search completes, 'ans' holds the minimum possible value for the maximum bench length.
        cout << ans << "\n"; // Output the result for the current test case.
    }
    
    return 0; // Indicate successful execution of the program.
}