#include<bits/stdc++.h>
using namespace std;
long long n;
const int MOD = 1e9 + 7;
struct matrix {
    long long a[2][2];
};

matrix mulMat(matrix A, matrix B) {
    matrix ans;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) ans.a[i][j] = 0;
    }
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 1; k++) ans.a[i][j] = (ans.a[i][j] + A.a[i][k] * B.a[k][j]) % MOD;
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
    matrix ans = mulMat(tmp, tmp);
    if (p % 2 == 1) ans = mulMat(ans, A);
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 1) { 
            cout << n % MOD << endl; 
            continue; 
        }
        matrix base;
        base.a[0][0] = 1; base.a[0][1] = 1; 
        base.a[1][0] = 1; base.a[1][1] = 0; 
        matrix M = powMod(base, n - 1);
        long long Tn = (M.a[0][0]) % MOD;
        cout << Tn << endl;
    }
}
