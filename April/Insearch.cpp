#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int hard;
    for (int i; i < n; i++){
        cin >> a[i];
}
    for (int i = 0; i < n; i++){
        if (a[i] == 1){
            hard = 1;
            break;
        }
        else{
            hard = 0;
        }
    }
    if (hard == 1){
        cout << "Hard";
    }
    else{
        cout << "Easy";
    }
    return 0;
}