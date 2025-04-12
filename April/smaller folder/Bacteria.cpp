#include <iostream>
using namespace std;
#include <bitset>
#include <string>


int main(){
    int n;
    cin >> n;
    int num = 0;
    string binary = bitset<64>(n).to_string();
    for ( int i = 0; i < binary.length(); i++ ) {
        if ( binary[i] == '1' ) {
            num++;
        }
    }
    cout << num << endl;
}