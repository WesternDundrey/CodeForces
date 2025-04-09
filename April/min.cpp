#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // Needed for std::gcd
#include <map> // Can use map for multiset counts

using namespace std;

// Function to compute GCD of a vector of numbers
// Returns 0 if vector is empty
long long vector_gcd(const vector<long long>& v) {
    if (v.empty()) {
        return 0; // Or handle as appropriate - problem guarantees n>=2 initially
    }
    
    long long current_gcd = v[0];
    for (size_t i = 1; i < v.size(); ++i) {
        current_gcd = std::gcd(current_gcd, v[i]);
        // Optimization: if gcd becomes 1, it will stay 1
        if (current_gcd == 1) {
            break;
        }
    }
    return current_gcd;
}


void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    map<long long, int> counts;
    long long min_val = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        counts[a[i]]++;
        if (min_val == -1 || a[i] < min_val) {
            min_val = a[i];
        }
    }

    // Build M: multiset of elements divisible by min_val
    vector<long long> M;
    for(const auto& pair : counts) {
        long long val = pair.first;
        int count = pair.second;
        if (val % min_val == 0) {
            for(int k=0; k < count; ++k) {
                 M.push_back(val);
            }
        }
    }

    // Check Condition 1: gcd(M) == min_val
    if (M.empty()) { // Should not happen if n>=1 and a[i]>=1
        cout << "No\n";
        return;
    }
    long long gcd_M = vector_gcd(M);

    if (gcd_M != min_val) {
        cout << "No\n";
        return;
    }

    // Check Condition 2: M must contain more than one element
    if (M.size() <= 1) {
         cout << "No\n"; // Cannot form non-empty S2 = M - {m}
         return;
    }

    // Check Condition 3: gcd(M - {m}) == min_val
    // Build M_minus_m vector
    vector<long long> M_minus_m;
    bool removed_one = false;
    for(long long val : M) {
        if (val == min_val && !removed_one) {
            removed_one = true; // Remove only one instance
        } else {
            M_minus_m.push_back(val);
        }
    }

    // M_minus_m must be non-empty (guaranteed by M.size() > 1 check)
    long long gcd_M_minus_m = vector_gcd(M_minus_m);

    if (gcd_M_minus_m == min_val) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}