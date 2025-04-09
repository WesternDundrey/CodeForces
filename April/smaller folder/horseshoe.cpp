#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    vector<int> a(4);
    
    // Read 4 colors
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    
    // Use set to count unique colors
    set<int> unique(a.begin(), a.end());
    
    // Need to buy (4 - number of unique colors)
    cout << 4 - unique.size();
    
    return 0;
}