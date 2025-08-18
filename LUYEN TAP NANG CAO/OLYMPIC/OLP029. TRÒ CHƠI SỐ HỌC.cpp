#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 25;
int n;
ll MOD;

struct mat {
    ll a[MAX][MAX];
};

mat IM() {
    mat I;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) I.a[i][j] = (i == j);
    return I;
}

mat mul(mat A, mat B) {
    mat ans;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            ans.a[i][j] = 0;
            for (int k = 1; k <= n; k++) ans.a[i][j] = (ans.a[i][j] + A.a[i][k] * B.a[k][j] % MOD) % MOD;
        }
    return ans;
}

mat add(mat A, mat B) {
    mat ans;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) ans.a[i][j] = (A.a[i][j]+B.a[i][j])%MOD;
    return ans;
}

mat powMod(mat A, ll p) {
    if(p == 0) return IM();
    if(p == 1) return A;
    mat h = powMod(A, p / 2), ans = mul(h, h);
    if(p % 2) ans = mul(ans, A);
    return ans;
}

mat calcB(mat A, ll k) {
    if(k == 1) return A;
    mat hB = calcB(A, k / 2), A2 = powMod(A, k / 2);
    mat res = mul(add(IM(), A2), hB);
    if(k % 2) res = add(res, powMod(A, k));
    return res;
}

bool isPrime(ll x) {
    if(x < 2) return 0;
    for(ll i = 2;i * i <=x; i++) if(x % i == 0) return 0;
    return 1;
}

int main() {
    int T; cin >> T;
    while(T--) {
        ll K; cin >> n >> K >> MOD;
        vector<ll> a(n + 1);
        for(int i = 1;i <= n; i++) cin >> a[i];
        mat A;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                A.a[i][j] = (i!=j && isPrime(6*a[i] + a[j]));

        mat res = calcB(A,K);
        cout << res.a[1][n] % MOD << "\n";
    }
}
