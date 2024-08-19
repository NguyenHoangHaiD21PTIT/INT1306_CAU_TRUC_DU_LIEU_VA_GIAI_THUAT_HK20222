#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e12 + 19;
long long n;

struct matrix {
    long long a[3][3];
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
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) ans.a[i][j] = 0;
    }
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            for (int k = 1; k <= 2; k++) ans.a[i][j] = (ans.a[i][j] + mulMod(A.a[i][k], B.a[k][j])) % MOD;
        }
    }
    return ans;
}

matrix powMod(matrix A, long long p) {
    if (p == 0) {
        matrix I;
        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= 2; j++) I.a[i][j] = (i == j) ? 1 : 0;
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
    int t;
    cin >> t;
    matrix A;
    A.a[1][1] = 1; A.a[1][2] = 1;
    A.a[2][1] = 1; A.a[2][2] = 0;
    while (t--) {
        cin >> n;
        matrix X = powMod(A, n - 1);
        long long Fn = (X.a[1][1] + X.a[1][2]) % MOD;
        cout << Fn << endl;
    }
}
