#include <bits/stdc++.h>
using namespace std;
long long n, MOD = 1e15 + 7;
struct matrix {
    long long a[4][4];
};
long long mulMod(long long a, long long b) {
    a %= MOD, b %= MOD;
    long long res = 0;
    while (b > 0) {
        if (b % 2) res = (res + a) % MOD;
        a = (a + a) % MOD;
        b /= 2;
    }
    return res;
}
matrix mulMatrix(matrix A, matrix B) {
    matrix res;
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) res.a[i][j] = 0;
    }
    for (int i = 0; i <= 3; i++){
        for (int j = 0; j <= 3; j++){
            for (int k = 0; k <= 3; k++) res.a[i][j] = (res.a[i][j] + mulMod(A.a[i][k], B.a[k][j])) % MOD;
        }
    }
    return res;
}
matrix powMod(matrix A, long long p) {
    if (p == 0) {
        matrix I;
        for (int i = 0; i <= 3; i++) {
            for (int j = 0; j <= 3; j++) I.a[i][j] = (i == j) ? 1 : 0;
        }
        return I;
    }
    if (p == 1) return A;
    matrix tmp = powMod(A, p / 2);
    matrix ans = mulMatrix(tmp, tmp);
    if (p % 2 == 1) ans = mulMatrix(ans, A);
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        if (n == 1) { cout << 1 % MOD << endl; continue; }
        if (n == 2) { cout << 3 % MOD << endl; continue; }
        if (n == 3) { cout << 6 % MOD << endl; continue; }
        matrix base;
        base.a[0][0] = 1; base.a[0][1] = 1; base.a[0][2] = 1; base.a[0][3] = 1;
        base.a[1][0] = 0; base.a[1][1] = 1; base.a[1][2] = 1; base.a[1][3] = 1;
        base.a[2][0] = 0; base.a[2][1] = 1; base.a[2][2] = 0; base.a[2][3] = 0;
        base.a[3][0] = 0; base.a[3][1] = 0; base.a[3][2] = 1; base.a[3][3] = 0;
        matrix M = powMod(base, n - 3);
        long long ans = (M.a[0][0] * 6 + M.a[0][1] * 3 + M.a[0][2] * 2 + M.a[0][3] * 1) % MOD;  
        cout << ans << endl;
    }
}

