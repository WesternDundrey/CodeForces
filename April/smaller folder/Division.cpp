#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> div;
    for (int i=0; i < n; i++){
        int b;
        int c;
        cin >> b >> c;
        if (b%c == 0){
            cout << '0' << endl;
        }
        else if (b%c != 0){
            cout << (c-(b%c)) << endl;
        }
        
    }
}