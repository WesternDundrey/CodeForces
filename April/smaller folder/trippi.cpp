#include <iostream>
#include <string>
#include <vector>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        cout << s1[0] << s2[0] << s3[0] << endl;
    }
    return 0;
}
