#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

struct matrix {
    long long a[100][100];  
};

long long mulMod(long long a, long long b) {
    if (b == 0) return 0;
    long long tmp = mulMod(a, b / 2);
    long long ans = (tmp + tmp) % MOD;
    if (b % 2) ans = (ans + a) % MOD;
    return ans;
}

matrix mulMatrix(matrix A, matrix B, int n) {
    matrix ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) ans.a[i][j] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) 
                ans.a[i][j] = (ans.a[i][j] + mulMod(A.a[i][k], B.a[k][j])) % MOD;
        }
    }
    return ans;
}

matrix powMod(matrix A, long long p, int n) {
    if (p == 0) {
        matrix I;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) I.a[i][j] = (i == j) ? 1 : 0;
        }
        return I;
    }
    if (p == 1) return A;
    matrix tmp = powMod(A, p / 2, n);
    matrix ans = mulMatrix(tmp, tmp, n);
    if (p % 2 == 1) ans = mulMatrix(ans, A, n);
    return ans;
}

int main() {
    int n, u, v, k;
    cin >> n >> u >> v >> k;
    u--; v--;  
    int graph[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> graph[i][j];
    }
    matrix A;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) A.a[i][j] = graph[i][j];
    }
    A = powMod(A, k, n);
    cout << A.a[u][v] << endl;
}
//https://oj.vnoi.info/problem/atcoder_dp_r
