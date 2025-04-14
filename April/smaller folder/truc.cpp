#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        if (m % k != 0) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << (int)((1LL * i * m + j) % k + 1) << (j == m - 1 ? "" : " ");
                }
                cout << "\n";
            }
        } else if (n % k != 0) {
             for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << (int)((1LL * j * n + i) % k + 1) << (j == m - 1 ? "" : " ");
                }
                cout << "\n";
            }
        } else {
             for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                   cout << (int)(((i % k) + (j % k)) % k + 1) << (j == m - 1 ? "" : " ");
                }
                 cout << "\n";
            }
        }
    }
    return 0;
}