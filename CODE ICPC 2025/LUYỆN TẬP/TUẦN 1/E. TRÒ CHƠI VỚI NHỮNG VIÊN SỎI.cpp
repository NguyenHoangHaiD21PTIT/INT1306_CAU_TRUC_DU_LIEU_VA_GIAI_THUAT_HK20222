#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n; cin >> n;
    ll res = 0, cur = n;
    ll f[100];
    f[1] = 1; f[2] = 2;
    for(int i = 3; i <= 85; i++) f[i] = f[i - 1] + f[i - 2];
    /*Định lý Zeckendorf
    */
    //Tìm số Fibonacci nhỏ nhất trong biểu diễn Zeckendorf của n
    for (int i = 80; i >= 1; --i) {
        if (cur >= f[i]){
            res = f[i];
            cur -= f[i];
        }
    }
    cout << res;
}