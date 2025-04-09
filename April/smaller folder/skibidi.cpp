#include <iostream> 
#include <vector>   
#include <numeric>  
#include <algorithm> 

/**
 * @brief Checks if it's possible to partition the array 'a' into at least 'k' non-overlapping subarrays,
 * such that each subarray contains all integers from 0 to m-1. This is equivalent to checking
 * if a minimum MEX of at least 'm' can be achieved across all 'k' subarrays.
 *
 * @param m The target minimum MEX value to check feasibility for.
 * @param n The length of the array 'a'.
 * @param k The required number of subarrays in the partition.
 * @param a The input array of integers.
 * @return true if such a partition into at least 'k' subarrays is possible, false otherwise.
 */
bool is_feasible(int m, int n, int k, const std::vector<int>& a) {
    // Base case: If the target minimum MEX is 0, it's always achievable
    // because any non-empty subarray has MEX >= 0. The problem guarantees k >= 1.
    if (m == 0) {
        return true;
    }

    // --- Step 1: Global Check ---
    // Verify if the entire array 'a' contains at least one instance of each number
    // from 0 to m-1. If any number in this range is completely missing from 'a',
    // then no subarray can possibly contain all of them, making 'm' infeasible.
    std::vector<bool> present_overall(m, false); // Tracks presence of 0..m-1
    int count_present_overall = 0; // Counts distinct numbers from 0..m-1 found
    for (int x : a) {
        // Only consider numbers relevant to the MEX check (less than m)
        if (x < m) {
            // If this number hasn't been marked as present yet
            if (!present_overall[x]) {
                present_overall[x] = true; // Mark it as present
                count_present_overall++;   // Increment the distinct count
            }
        }
    }
    // If the total count of distinct numbers found is less than m, 'm' is impossible.
    if (count_present_overall < m) {
        return false;
    }

    // --- Step 2: Greedy Partitioning Check ---
    // Try to greedily form segments starting from the beginning of the array.
    // Each segment must contain all numbers from 0 to m-1. We find the *shortest*
    // possible segment starting at the current position that satisfies this.
    int segments_found = 0; // Counter for the number of valid segments found
    int current_idx = 0;   // The starting index for searching the current segment
    // Reuse this vector for counts within each segment search window to potentially
    // avoid reallocations, though std::fill itself takes O(m) time.
    std::vector<int> current_counts(m);

    // Continue searching for segments as long as we haven't reached the end of the array.
    while (current_idx < n) {
        // Reset the frequency counts and the distinct counter for the new segment search.
        std::fill(current_counts.begin(), current_counts.end(), 0); // O(m) operation
        int distinct_found = 0; // Counter for distinct numbers (0..m-1) found in the current window
        int segment_end = -1;   // Stores the end index of the successfully found segment

        // Extend the segment window to the right (index 'r') starting from 'current_idx'.
        for (int r = current_idx; r < n; ++r) {
            int val = a[r];
            // If the current element is one of the numbers we need (0 to m-1)
            if (val < m) {
                // If this is the first time we encounter 'val' in this specific segment search window
                if (current_counts[val] == 0) {
                    distinct_found++; // Increment the count of distinct required numbers found
                }
                current_counts[val]++; // Increment the frequency count for 'val'
            }

            // Check if we have found all m required numbers within the window a[current_idx...r]
            if (distinct_found == m) {
                segment_end = r; // Mark 'r' as the end index of this minimal segment
                break;           // Stop extending the window for this segment
            }
        }

        // Check if the inner loop successfully found a valid segment
        if (segment_end != -1) {
            segments_found++; // Increment the total count of valid segments found
            // Optimization: If we have already found k segments, we know 'm' is feasible.
            if (segments_found >= k) {
                return true;
            }
            // Prepare to search for the next segment starting right after the current one.
            current_idx = segment_end + 1;
        } else {
            // If the inner loop completed without finding all m numbers,
            // it's impossible to form another valid segment from the remaining array.
            break; // Exit the while loop
        }
    }

    // If the loop finished, return true if we managed to find at least k segments, false otherwise.
    // Note: Due to the optimization above, this check might be redundant but ensures correctness if the loop terminates early naturally.
    return segments_found >= k;
}


int main() {
    // Optimize standard input/output operations for speed.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Length of the array
        int k; // Required number of subarrays
        std::cin >> n >> k;

        std::vector<int> a(n); // Input array
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        // Binary search for the maximum possible value 'm' (minimum MEX).
        // The possible range for 'm' is [0, n+1].
        // MEX can be 0 if 0 is missing. MEX can be n+1 if 0..n are present.
        int low = 0, high = n + 1;
        int ans = 0; // Stores the maximum feasible 'm' found so far

        while (low <= high) {
            // Calculate the midpoint, avoiding potential integer overflow
            int mid = low + (high - low) / 2;
            // Check if achieving a minimum MEX of 'mid' is possible
            if (is_feasible(mid, n, k, a)) {
                // If 'mid' is feasible, it's a possible answer. We store it and
                // try to find an even larger feasible value.
                ans = mid;
                low = mid + 1; // Search in the upper half [mid+1, high]
            } else {
                // If 'mid' is not feasible, the maximum possible answer must be smaller.
                high = mid - 1; // Search in the lower half [low, mid-1]
            }
        }
        // Output the largest value 'm' for which is_feasible returned true.
        std::cout << ans << "\n";
    }
    return 0; // Indicate successful execution
}