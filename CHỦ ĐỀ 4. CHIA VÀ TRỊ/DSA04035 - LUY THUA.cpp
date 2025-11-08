#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
ll lt(ll a, ll b){
    ll res = 1;
    while (b){
        if (b % 2 == 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}
int main(){
    ll a, b;
    while (cin >> a >> b && (a != 0 || b != 0)) cout << lt(a, b) << endl;
}
