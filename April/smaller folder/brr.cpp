#include <iostream>
#include <string>
#include <vector>
#include <ios> // Required for std::ios_base, std::cin.tie


bool solve() {
    std::string p; // The sequence of hits
    std::string s; // The sequence of sounds heard
    std::cin >> p >> s;
    int n = p.length(); 
    int m = s.length(); 

   
    if (n > m) {
        return false;
    }

    int p_ptr = n - 1; 
    int s_ptr = m - 1; 

    
    while (p_ptr >= 0) {
        
        if (s_ptr < 0) {
            return false;
        }

        
        if (p[p_ptr] != s[s_ptr]) {
            return false;
        }

       
        if (s_ptr - 1 >= 0 && s[s_ptr - 1] == p[p_ptr]) {
            
            s_ptr -= 2;
        } else {
            
            s_ptr -= 1;
        }

        // Move to the previous hit in the sequence p.
        p_ptr -= 1;
    }

   
    return s_ptr == -1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        if (solve()) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}