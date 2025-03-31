#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;


    if (n%4||n%7||n%47||n%74||n%447||n%474||n%477||n%744||n%747||n%774){
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}