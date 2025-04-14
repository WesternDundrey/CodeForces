#include <iostream>
#include <vector>
#include <deque>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; 
    while (t--) {
        int q;
        cin >> q;

        deque<int> dq;
        ll R = 0; 
        ll S = 0; 
        int n = 0; 
        bool is_reversed = false;

        for (int op_idx = 0; op_idx < q; ++op_idx) {
            int type;
            cin >> type;

            if (type == 1) { 
                
                int k;
                if (!is_reversed) {
                    k = dq.back();
                    dq.pop_back();
                    dq.push_front(k);
                } else {
                    k = dq.front();
                    dq.pop_front();
                    dq.push_back(k);
                }
                
                R = R + S - (ll)n * k; 
                
            } else if (type == 2) { 
                
                is_reversed = !is_reversed;
                
                R = (ll)(n + 1) * S - R;
                
            } else { 
                int k;
                cin >> k;
                if (!is_reversed) {
                    dq.push_back(k);
                } else {
                    dq.push_front(k);
                }
                
                n++; 
                S += k; 
                
                R = R + (ll)k * n;
            }
            cout << R << "\n";
        }
    }

    return 0;
}