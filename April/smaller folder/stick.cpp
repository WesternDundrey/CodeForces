#include <iostream>

using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    if (n == m){
        if (n%2 == 0){
            cout << "Malvika" << endl;
        }
        else {
            cout << "Akshat" << endl;
        }
    }
    else {
    auto minimum = min(n, m);
    if (minimum%2 == 0){
        cout << "Malvika" << endl;
    }
    else {
        cout << "Akshat" << endl;
    
    }
}
}