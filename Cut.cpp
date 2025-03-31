#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z; // using x, y, z instead of a, b, c for clarity

    vector<int> cuts = {x, y, z}; // store available ribbon sizes

    int maxCount = 0;

    // Try all combinations of i*x + j*y + k*z = n
    for (int i = 0; i <= n / x; i++) {
        for (int j = 0; j <= n / y; j++) {
            int rem = n - (i * x + j * y);
            if (rem >= 0 && rem % z == 0) {
                int k = rem / z;
                maxCount = max(maxCount, i + j + k);
            }
        }
    }

    cout << maxCount << endl;
}
