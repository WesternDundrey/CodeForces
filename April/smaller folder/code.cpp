#include <iostream>
#include <string>

using namespace std;

string solve(const string& p, const string& s) {
    int p_idx = 0;
    int s_idx = 0;
    
    while (p_idx < p.length()) {
        // Check if we've consumed all of s or the current characters don't match
        if (s_idx >= s.length() || s[s_idx] != p[p_idx]) {
            return "NO";
        }
        
        // Consume the first sound
        s_idx++;
        
        // Check if there's a second sound of the same type
        if (s_idx < s.length() && s[s_idx] == p[p_idx]) {
            s_idx++;
        }
        
        // Move to the next hit
        p_idx++;
    }
    
    
    return (s_idx == s.length()) ? "YES" : "NO";
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        string p, s;
        cin >> p >> s;
        cout << solve(p, s) << endl;
    }
    
    return 0;
}