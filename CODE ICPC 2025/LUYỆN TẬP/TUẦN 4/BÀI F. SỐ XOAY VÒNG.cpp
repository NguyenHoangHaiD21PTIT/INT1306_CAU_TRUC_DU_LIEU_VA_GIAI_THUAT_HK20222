#include<bits/stdc++.h>
using namespace std;
int main(){
    //abc + bca + cab = 100a + 10b + c + 100b + 10c + a + 100c + 10a + b = 111(a + b + c)
    string s; cin >> s;
    int tong = 0;
    for(char x: s) tong += x - '0';
    cout << tong * 111;
}