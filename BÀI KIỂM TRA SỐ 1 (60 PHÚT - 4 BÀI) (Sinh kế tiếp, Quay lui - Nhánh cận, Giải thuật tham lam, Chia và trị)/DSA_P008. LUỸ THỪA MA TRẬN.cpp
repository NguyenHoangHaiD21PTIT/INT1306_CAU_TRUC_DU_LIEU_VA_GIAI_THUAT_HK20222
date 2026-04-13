#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k, MOD = 1e9 + 7;

struct mat{
    ll a[12][12];
};

mat mul(mat A, mat B){
    mat ans;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            ans.a[i][j] = 0;
            for (int k = 0; k < n; k++) ans.a[i][j] = (ans.a[i][j] + A.a[i][k] * B.a[k][j]) % MOD;
        }
    }
    return ans;
}

mat pMod(mat A, ll p){
    if (p == 0){
        mat I;
        for (int i = 0; i < n; i++) I.a[i][i] = 1;
        return I;
    }
    if (p == 1) return A;
    mat tmp = pMod(A, p / 2);
    mat ans = mul(tmp, tmp);
    if (p % 2) ans = mul(ans, A);
    return ans;
}

int main(){
    int t; cin >> t;
    while (t--){
        cin >> n >> k;
        mat A;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) cin >> A.a[i][j];
        }
        A = pMod(A, k);
        ll ans = 0;
        for (int i = 0; i < n; i++) ans = (ans + A.a[i][n - 1 - i]) % MOD;
        cout << ans << endl;
    }
}
