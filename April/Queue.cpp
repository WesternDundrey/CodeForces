#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    vector<char> a(n);
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // Process the swapping for 't' time steps
    while (t--) {
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == 'B' && a[i + 1] == 'G') {
                swap(a[i], a[i + 1]);
                i++;  // Skip the next index to prevent double swaps
            }
        }
    }

    // Print final result
    for (char c : a) {
        cout << c;
    }

    return 0;
}
