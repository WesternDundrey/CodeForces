#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    
    // Read team names
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Count occurrences of each team name
    map<string, int> counts;
    for (const string& team : a) {
        counts[team]++;
    }
    
    // Find the team with maximum occurrences
    string winningTeam;
    int maxCount = 0;
    
    for (const auto& pair : counts) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            winningTeam = pair.first;
        }
    }
    
    // Output the winning team
    cout << winningTeam << endl;
    
    return 0;
}