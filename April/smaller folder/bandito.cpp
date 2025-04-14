#include <iostream> 
#include <algorithm>

#define ll long long 

using namespace std; 

int main() { 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; 
    cin >> t; 

    while (t--) { 
        int n, m, l, r; 
        cin >> n >> m >> l >> r; 

       
        int r_prime = min(m, r); 

        
        int l_prime = r_prime - m; 

        
        cout << l_prime << " " << r_prime << "\n";
    }
    return 0; 
}