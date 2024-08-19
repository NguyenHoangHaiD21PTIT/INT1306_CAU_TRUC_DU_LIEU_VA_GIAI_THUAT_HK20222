#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e15 + 7;
long long n;

struct matrix {
    long long a[5][5]; 
};


matrix mulMatrix(matrix A, matrix B) {
    matrix ans;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) ans.a[i][j] = 0;
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) ans.a[i][j] = (ans.a[i][j] + A.a[i][k] * B.a[k][j]) % MOD;
        }
    }
    return ans;
}

matrix powMod(matrix A, long long p) {
    if (p == 0) {
        matrix I;
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) I.a[i][j] = (i == j) ? 1 : 0;
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
    while (t--) {
        cin >> n;
        if (n <= 5) {
            vector<int> b = {1, 3, 6, 12, 23};
            cout << b[n - 1] << endl;
        } else {
            matrix T;
            T.a[1][1] = 1; T.a[1][2] = 0; T.a[1][3] = 0; T.a[1][4] = 0;
            T.a[2][1] = 0; T.a[2][2] = 1; T.a[2][3] = 1; T.a[2][4] = 0;
            T.a[3][1] = 1; T.a[3][2] = 1; T.a[3][3] = 0; T.a[3][4] = 1;
            T.a[4][1] = 0; T.a[4][2] = 1; T.a[4][3] = 0; T.a[4][4] = 0;
            matrix X = powMod(T, n + 2);
            long long Tn = X.a[3][1] - 1;
            cout << Tn << endl;
        }
    }
    return 0;
}
