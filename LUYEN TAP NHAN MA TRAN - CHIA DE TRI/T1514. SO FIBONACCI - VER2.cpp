#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e12 + 19;
int sz = 2;

struct matrix {
    long long a[3][3];
};

// Hàm nhân hai số với mod
long long mulNumber(long long a, long long b) {
    if (b == 0) return 0;
    long long ans = mulNumber(a, b / 2);
    ans = (ans + ans) % MOD;
    if (b % 2 == 1) ans = (ans + a) % MOD;
    return ans;
}

// Hàm nhân hai ma trận
matrix mulMatrix(matrix A, matrix B) {
    matrix ans;
    for (int i = 1; i <= sz; i++) {
        for (int j = 1; j <= sz; j++) ans.a[i][j] = 0;
    }
    for (int i = 1; i <= sz; i++) {
        for (int j = 1; j <= sz; j++) {
            long long sum = 0;
            for (int k = 1; k <= sz; k++) sum = (sum + mulNumber(A.a[i][k], B.a[k][j])) % MOD;
            ans.a[i][j] = sum;
        }
    }
    return ans;
}

// Hàm lũy thừa ma trận
matrix powMatrix(matrix A, long long n) {
    if (n == 0) {
        matrix I;
        for (int i = 1; i <= sz; i++) {
            for (int j = 1; j <= sz; j++) I.a[i][j] = (i == j); // Ma trận đơn vị
        }
        return I;
    }
    if (n == 1) return A;
    matrix ans = powMatrix(A, n / 2);
    ans = mulMatrix(ans, ans);
    if (n % 2 == 1) ans = mulMatrix(ans, A);
    return ans;
}
int main() {
    matrix A;
    A.a[1][1] = 1; A.a[1][2] = 1;
    A.a[2][1] = 1; A.a[2][2] = 0;
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        matrix X = powMatrix(A, n - 1);
        long long Fn = (X.a[1][1] + X.a[1][2]) % MOD;
        cout << Fn << endl;
    }
}
