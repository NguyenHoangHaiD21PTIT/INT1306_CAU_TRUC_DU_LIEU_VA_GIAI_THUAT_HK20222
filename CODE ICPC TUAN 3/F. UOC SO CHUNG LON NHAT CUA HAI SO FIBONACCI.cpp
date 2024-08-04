#include <bits/stdc++.h>
using namespace std;

struct matran {
    long long c[2][2];
    matran() {
        c[0][0] = 0; c[0][1] = 1;
        c[1][0] = 1; c[1][1] = 1;
    }
};

matran matrixMul(const matran &a, const matran &b, long long MOD) {
    matran res;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res.c[i][j] = 0;
            for (int k = 0; k < 2; k++) res.c[i][j] = (res.c[i][j] + a.c[i][k] * b.c[k][j] % MOD) % MOD;
        }
    }
    return res;
}

matran powmod(matran a, long long n, long long MOD) {
    if (n == 1) return a;
    if (n % 2 == 1) return matrixMul(powmod(a, n - 1, MOD), a, MOD);
    matran tmp = powmod(a, n / 2, MOD);
    return matrixMul(tmp, tmp, MOD);
}

long long fibonacci(long long n, long long MOD) {
    if (n == 0) return 0;
    matran x;
    x = powmod(x, n, MOD);
    return x.c[0][1];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b, M;
        cin >> a >> b >> M;
        long long g = __gcd(a, b);
        cout << fibonacci(g, M) << endl;
    }
    return 0;
}
