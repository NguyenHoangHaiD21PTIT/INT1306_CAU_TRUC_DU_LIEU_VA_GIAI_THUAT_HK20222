#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
using ll = long long;
ll pmod(ll a, ll b){
    ll res = 1;
    while (b){
        if (b % 2 == 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}
int main(){
    int t; cin >> t;
    while (t--){
        ll a, b; cin >> a >> b;
        cout << pmod(a, b) << endl;
    }
}
