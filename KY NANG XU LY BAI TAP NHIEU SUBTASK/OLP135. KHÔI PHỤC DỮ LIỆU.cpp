#include <bits/stdc++.h>
using namespace std;

long long n, k, MOD;

struct matrix {
    long long a[105][105]; // k ≤ 100
};

matrix mulMatrix(matrix A, matrix B, int sz) {
    matrix res;
    for(int i = 0;i < sz; i++){
        for(int j = 0;j < sz; j++) res.a[i][j] = 0;
    }
    for(int i = 0; i < sz; i++){
        for(int j = 0;j < sz; j++){
            for(int k = 0; k < sz; k++) res.a[i][j] = (res.a[i][j] + A.a[i][k] * B.a[k][j]) % MOD;
        }
    }
    return res;
}

matrix powMod(matrix A, long long p, int sz) {
    if(p==0) {
        matrix I;
        for(int i = 0; i < sz; i++){
            for(int j = 0; j < sz; j++) I.a[i][j] = (i == j) ? 1 : 0;
        }
        return I;
    }
    if(p == 1) return A;
    matrix tmp = powMod(A, p/2, sz);
    matrix ans = mulMatrix(tmp, tmp, sz);
    if(p % 2 == 1) ans = mulMatrix(ans, A, sz);
    return ans;
}

int main() {
    cin >> n >> k;
    MOD = 1e9 + 7;
    matrix base;
    // Ma trận cơ sở: chọn 0,1,2 phần tử
    for(int i = 0; i < k; i++){
        base.a[i][i] = 1;               // chọn 0 phần tử
        base.a[i][(i + 1) % k] += 3;     // chọn 1 phần tử
        base.a[i][(i + 2) % k] += 3;     // chọn 2 phần tử
        base.a[i][i] %= MOD;            // tránh tràn MOD
        base.a[i][(i + 1) % k] %= MOD;
        base.a[i][(i + 2) % k] %= MOD;
    }
    matrix M = powMod(base, n, k);
    long long res = (M.a[0][0] - 1 + MOD) % MOD; //Trừ trường hợp không chọn phần tử nào
    cout << res << "\n";
}
