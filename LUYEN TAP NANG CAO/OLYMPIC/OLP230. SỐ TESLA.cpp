#include <bits/stdc++.h>
using namespace std;
long long n, MOD;
struct matrix {
    long long a[3][3];
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
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) res.a[i][j] = 0;
    }
    for (int i = 0; i <= 2; i++){
        for (int j = 0; j <= 2; j++){
            for (int k = 0; k <= 2; k++) res.a[i][j] = (res.a[i][j] + mulMod(A.a[i][k], B.a[k][j])) % MOD;
        }
    }
    return res;
}
matrix powMod(matrix A, long long p) {
    if (p == 0) {
        matrix I;
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) I.a[i][j] = (i == j) ? 1 : 0;
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
        cin >> n >> MOD;
        if (n <= 3) { 
            cout << n % MOD << endl; 
            continue; 
        }
        matrix base;
        base.a[0][0] = 1; base.a[0][1] = 2; base.a[0][2] = 3;
        base.a[1][0] = 1; base.a[1][1] = 0; base.a[1][2] = 0;
        base.a[2][0] = 0; base.a[2][1] = 1; base.a[2][2] = 0;
        matrix M = powMod(base, n - 3);
        long long Tn = (M.a[0][0] * 3 + M.a[0][1] * 2 + M.a[0][2]) % MOD;
        cout << Tn << endl;
    }
}

