#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string current_magnet, previous_magnet;
    int groups = 0;
    
    if (n > 0) {
        groups = 1; // Start with at least 1 group
        
        // Read the first magnet
        cin >> previous_magnet;
        
        // Process the remaining magnets
        for (int i = 1; i < n; i++) {
            cin >> current_magnet;
            
            // If current magnet is different from previous, they repel and form a new group
            if (current_magnet != previous_magnet) {
                groups++;
            }
            
            previous_magnet = current_magnet;
        }
    }
    
    cout << groups << endl;
    return 0;
}