#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll f[50], cnt[50];
void gen(){
    f[0] = 1; f[1] = 1; cnt[0] = 0; cnt[1] = 1;
    for (int i = 2; i < 50; i++){
        f[i] = f[i - 1] + f[i - 2];
        cnt[i] = cnt[i - 1] + cnt[i - 2];
    }
}
ll count (ll n, ll k){
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (k <= f[n - 1]) return count(n - 1, k);
    else return cnt[n - 1] + count(n - 2, k - f[n - 1]);
}
int main(){
    gen();
    int t; cin >> t;
    while (t--){
        ll n, k; cin >> n >> k;
        cout << count(n, k) << "\n";
    }
}
