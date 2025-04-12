#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;  // Read n first
    
    int p;
    cin >> p;  // Number of levels player 1 can pass
    
    vector<int> levels_p(p);
    for (int i = 0; i < p; i++) {
        cin >> levels_p[i];
    }
    
    int q;
    cin >> q;  // Number of levels player 2 can pass
    
    vector<int> levels_q(q);
    for (int i = 0; i < q; i++) {
        cin >> levels_q[i];
    }
    
    // Merge both vectors into a new one
    vector<int> all_levels;
    all_levels.reserve(p + q);
    all_levels.insert(all_levels.end(), levels_p.begin(), levels_p.end());
    all_levels.insert(all_levels.end(), levels_q.begin(), levels_q.end());
    
    // Sort and remove duplicates
    sort(all_levels.begin(), all_levels.end());
    all_levels.erase(unique(all_levels.begin(), all_levels.end()), all_levels.end());
    
    // Check if all levels from 1 to n are present
    bool can_pass_all = true;
    for (int level = 1; level <= n; level++) {
        if (find(all_levels.begin(), all_levels.end(), level) == all_levels.end()) {
            can_pass_all = false;
            break;
        }
    }
    
    if (can_pass_all) {
        cout << "I become the guy." << endl;
    } else {
        cout << "Oh, my keyboard!" << endl;
    }
    
    return 0;
}