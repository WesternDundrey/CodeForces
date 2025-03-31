#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    // Check the parity of the first three numbers to determine the majority parity.
    int evenCount = 0;
    for (int i = 0; i < 3; i++) {
        if (numbers[i] % 2 == 0) {
            evenCount++;
        }
    }
    
    // If at least two of the first three numbers are even,
    // then even is the majority, otherwise odd is the majority.
    bool majorityEven = evenCount >= 2;
    
    // Find the index of the number that differs in parity.
    for (int i = 0; i < n; i++) {
        bool isEven = (numbers[i] % 2 == 0);
        if ((majorityEven && !isEven) || (!majorityEven && isEven)) {
            cout << i + 1 << endl; // 1-indexed result
            break;
        }
    }
    
    return 0;
}
