#include<bits/stdc++.h>
using namespace std;
long long n, MOD;
struct matrix {
    long long a[2][2];
};

long long mulMod(long long a, long long b) {
    if (b == 0) return 0;
    long long tmp = mulMod(a, b / 2);
    long long ans = (tmp + tmp) % MOD;
    if (b % 2) ans = (ans + a) % MOD;
    return ans;
}

matrix mulMatrix(matrix A, matrix B) {
    matrix ans;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) ans.a[i][j] = 0;
    }
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 1; k++) ans.a[i][j] = (ans.a[i][j] + mulMod(A.a[i][k], B.a[k][j])) % MOD;
        }
    }
    return ans;
}

matrix powMod(matrix A, long long p) {
    if (p == 0) {
        matrix I;
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 1; j++) I.a[i][j] = (i == j) ? 1 : 0;
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
        if (n <= 2) { 
            cout << n % MOD << endl; 
            continue; 
        }
        matrix base;
        base.a[0][0] = 1; base.a[0][1] = 1; 
        base.a[1][0] = 1; base.a[1][1] = 0; 
        matrix M = powMod(base, n - 1);
        long long Tn = (M.a[0][0] + M.a[0][1]) % MOD;
        cout << Tn << endl;
    }
}

