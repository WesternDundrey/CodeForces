#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    string target = "hello";
    int j = 0;  // Pointer for target word

    for (char c : s) {
        if (c == target[j]) {
            j++;  // Move to next character in "hello"
        }
        if (j == target.size()) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
