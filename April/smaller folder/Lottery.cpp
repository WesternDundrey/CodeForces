#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int bills=0;
    while(n > 0){
        if (n>=100){
            n-=100;
        }
        else if (n>=20&&n<100){
            n-=20;
        }
        else if (n>=10&&n<20){
            n-=10;
        }
        else if (n>=5 &&n<10){
            n-=5;
        }
        else{
            n-=1;
        }
        bills++;
    }
    cout << bills << endl;
}