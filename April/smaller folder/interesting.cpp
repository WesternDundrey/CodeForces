#include <iostream>
#include <vector>
#include <algorithm>  // for sort and upper_bound
using namespace std;

int main() {
    int a;
    cin >> a;
    vector<int> v(a);
    
    for (int i = 0; i < a; i++) {
        cin >> v[i];
    }
    
    // Sort vector v to enable binary search
    sort(v.begin(), v.end());
    
    int b;
    cin >> b;
    vector<int> f(b);
    
    for (int i = 0; i < b; i++) {
        cin >> f[i];
    }
    
    // For each element in f, use binary search to find count
    for (int i = 0; i < b; i++) {
        // upper_bound returns iterator to first element greater than f[i]
        int count = upper_bound(v.begin(), v.end(), f[i]) - v.begin();
        cout << count << endl;
    }
    
    return 0;
}