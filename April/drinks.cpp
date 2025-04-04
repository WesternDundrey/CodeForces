#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

int main(){
    int n;
    cin >> n;

    float sum;
    sum = 0;
    int a;

    for (int i=0; i<n; i++){
        cin >> a;
        sum = sum + a;
    }
    cout << sum/n<<endl;
}