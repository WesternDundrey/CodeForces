#include <iostream>
#include <vector>


using namespace std;
int main(){
    int y;
    cin >> y;
    vector <int> a;
    a = {y/1000%10, y/100%10, y/10%10, y%10};
    while (true){
        y++;
        a = {y/1000%10, y/100%10, y/10%10, y%10};
        if (a[0] != a[1] && a[0] != a[2] && a[0] != a[3] && a[1] != a[2] && a[1] != a[3] && a[2] != a[3]){
            break;
        }
    }
    cout << y;
    return 0;
}
