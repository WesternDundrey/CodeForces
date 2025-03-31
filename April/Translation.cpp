#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    vector<char> chars(str.begin(), str.end());
    reverse(chars.begin(), chars.end());
    string ans;
    cin >> ans;
    vector<char> answer(ans.begin(), ans.end());

    if (answer == chars){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}