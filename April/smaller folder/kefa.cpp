#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    int count = 1;
    vector<int> c(n);
    int max = 0;
    for ( int i = 0; i < n ; i++){
        cin >> a[i];
    }
    for ( int i = 0; i < n ; i++){
        if ( a[i+1] >= a[i] ){
            count++;
        }
        else {
            c.push_back(count);
            count = 1;
    }
    }
    max = *max_element(c.begin(), c.end()); 
    cout << max << endl;
}