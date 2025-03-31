#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    double max_gap = 0;

    for (int i = 1; i < n; i++) {
        double gap = a[i] - a[i - 1];
        max_gap = max(max_gap, gap);
    }

    double edge_left = a[0] - 0;
    double edge_right = l - a[n - 1];

    double result = max({max_gap / 2.0, edge_left, edge_right});

    cout << fixed << setprecision(10) << result << endl;

    return 0;
}
