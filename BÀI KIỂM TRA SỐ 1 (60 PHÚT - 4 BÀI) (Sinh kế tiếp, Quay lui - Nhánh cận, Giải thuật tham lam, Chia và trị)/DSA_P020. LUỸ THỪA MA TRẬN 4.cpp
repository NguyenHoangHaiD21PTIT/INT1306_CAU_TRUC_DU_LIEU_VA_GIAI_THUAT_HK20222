#include<bits/stdc++.h>
using namespace std;
long long n, k, MOD = 1e9 + 7;
struct matrix {
    long long a[12][12];
};

matrix mulMatrix(matrix A, matrix B) {
    matrix ans;
    for (int i = 0; i <= n - 1; i++) {
        for (int j = 0; j <= n - 1; j++) ans.a[i][j] = 0;
    }
    for (int i = 0; i <= n - 1; i++) {
        for (int j = 0; j <= n - 1; j++) {
            for (int k = 0; k <= n - 1; k++) ans.a[i][j] = (ans.a[i][j] +A.a[i][k] * B.a[k][j]) % MOD;
        }
    }
    return ans;
}

matrix powMod(matrix A, long long p) {
    if (p == 0) {
        matrix I;
        for (int i = 0; i <= n - 1; i++) {
            for (int j = 0; j <= n - 1; j++) I.a[i][j] = (i == j) ? 1 : 0;
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
        cin >> n >> k;
        matrix A;
        for (int i = 0; i <= n - 1; i++) {
            for (int j = 0; j <= n - 1; j++) cin >> A.a[i][j];
        }
        matrix ans = powMod(A, k);
        long long res = 0;
        for (int j = 0; j <= n - 1; j++) res = (res + ans.a[0][j]) % MOD;
        cout << res << '\n';
    }
}

