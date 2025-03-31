#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> nameCount;
    string name;

    for (int i = 0; i < n; i++) {
        cin >> name;
        if (nameCount[name] == 0) {
            cout << "OK" << endl;
            nameCount[name] = 1;
        } else {
            cout << name << nameCount[name] << endl;
            nameCount[name]++;
        }
    }

    return 0;
}
