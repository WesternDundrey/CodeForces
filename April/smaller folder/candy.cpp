#include <iostream>

#include <cmath>

using namespace std;
int main(){
    int n;
    cin >> n;
    int a;
    for (int i = 0; i < n ; i ++){
        cin >> a;
        a-=1;
        a/=2;
        cout << a<< endl;
    }
}