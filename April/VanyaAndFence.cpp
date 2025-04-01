#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main(){
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for(int i = 0; i <n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        if(a[i]>h){
            a[i]=2;
        }
        else{
            a[i]=1;
        }
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    cout << sum << endl;
    return 0;
        
}