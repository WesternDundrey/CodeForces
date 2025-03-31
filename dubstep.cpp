#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    string ans = "";
    for(int i = 0; i < s.size();i++){
        if(s[i]=='W'&& s[i+1]=='U' && s[i+2]=='B'){
            i+=2;
            if(ans.size() && ans[ans.size()-1]!=' ') ans+=' ';
        }else{
            ans+=s[i];
        }
    }
    cout << ans;
}