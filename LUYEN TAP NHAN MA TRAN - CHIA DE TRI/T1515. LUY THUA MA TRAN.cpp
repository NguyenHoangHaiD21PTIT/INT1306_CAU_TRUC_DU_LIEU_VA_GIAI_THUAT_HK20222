#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int n; 

struct matrix {
    long long a[25][25];
};

matrix IM() {
    matrix I;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) I.a[i][j] = (i == j) ? 1 : 0;
    }
    return I;
}

// Hàm nhân 2 ma trận
matrix mulMatrix(matrix A, matrix B) {
    matrix ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans.a[i][j] = 0;
            for (int k = 1; k <= n; k++) ans.a[i][j] = (ans.a[i][j] + A.a[i][k] * B.a[k][j]) % MOD;
        }
    }
    return ans;
}

matrix addMatrix(matrix A, matrix B) {
    matrix ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) ans.a[i][j] = (A.a[i][j] + B.a[i][j]) % MOD;
    }
    return ans;
}

matrix powMod(matrix A, long long p) {
    if (p == 1) return A;
    if (p == 0) return IM();
    matrix half = powMod(A, p / 2);
    matrix ans = mulMatrix(half, half);
    if (p % 2 != 0) ans = mulMatrix(ans, A);
    return ans;
}

// Hàm tính B(k) = A + A^2 + ... + A^k
matrix calcB(matrix A, int k) {
    if (k == 1) return A;
    matrix halfB = calcB(A, k / 2); // B(k/2)
    matrix Ak2 = powMod(A, k / 2);  // A^(k/2)
    matrix result = mulMatrix(addMatrix(IM(), Ak2), halfB);
    if (k % 2 != 0) result = addMatrix(result, powMod(A, k));
    return result;
}

int main() {
    int k;
    cin >> n >> k;
    matrix A;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> A.a[i][j];
    }
    matrix result = calcB(A, k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << result.a[i][j] << " ";
        cout << endl;
    }
}
