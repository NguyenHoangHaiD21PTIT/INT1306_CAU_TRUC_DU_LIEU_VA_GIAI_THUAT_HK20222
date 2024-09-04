#include<bits/stdc++.h>
using namespace std;
long long n, MOD;
struct matrix {
    long long a[3][3];
};

matrix mulMatrix(matrix A, matrix B) {
    matrix ans;
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) ans.a[i][j] = 0;
    }
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            for (int k = 1; k <= 2; k++) ans.a[i][j] = (ans.a[i][j] + A.a[i][k]*B.a[k][j]) % MOD;
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
    A.a[1][1] = 0; A.a[1][2] = 1;
    A.a[2][1] = 1; A.a[2][2] = 1;
    while (t--) {
        long long a, b;
        cin>>a>>b>>MOD;
        matrix X = powMod(A, __gcd(a, b));
        cout<<X.a[1][2]<<endl;
    }
}
