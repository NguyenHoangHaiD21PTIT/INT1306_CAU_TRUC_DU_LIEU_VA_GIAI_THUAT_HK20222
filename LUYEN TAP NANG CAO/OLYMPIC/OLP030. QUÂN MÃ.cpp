#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;

struct matrix {
    long long a[100][100];
};

// Hàm nhân ma trận kích thước r x r
matrix mulMatrix(matrix A, matrix B, int r) {
    matrix res;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < r; j++) res.a[i][j] = 0;
	}
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < r; k++)  res.a[i][j] = (res.a[i][j] + (A.a[i][k] * B.a[k][j]) % MOD) % MOD;
        }
    }
    return res;
}

matrix powMod(matrix A, long long p, int r) {
    if (p == 0) {
        matrix I;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < r; j++) I.a[i][j] = (i == j) ? 1 : 0;
        }
        return I;
    }
    if (p == 1) return A;
    matrix tmp = powMod(A, p / 2, r);
    matrix ans = mulMatrix(tmp, tmp, r);
    if (p % 2 == 1) ans = mulMatrix(ans, A, r);
    return ans;
}

inline int getBit(int mask, int pos) {
    return (mask >> pos) & 1; // Lấy bit tại vị trí pos của mask
	// mask >> pos dịch bit mask sang phải pos lần, VD: 10110, dịch 2 lần sẽ thành 00101
	// & 1 lấy bit cuối cùng của kết quả, nếu là 1 thì trả về 1, nếu là 0 thì trả về 0
}

bool val1(int x, int y, int m) {
	//Kiểm tra trạng thái 2 cột kề nhau x và y có hợp lệ không
	/* x y
	   - -
	   - -
	   - -
	   - -
	*/
    for (int i = 0; i < m; i++) {
        if (getBit(x, i)) { //Đã đặt quân mã ở hàng i cột x
            if (i + 2 < m && getBit(y, i + 2)) return false;
			//(i, x) --> (i + 2, x + 1) thì bị ăn
            if (i - 2 >= 0 && getBit(y, i - 2)) return false;
        }
    }
    return true;
}

bool val2(int x, int z, int m) { //Kiểm tra trạng thái của 2 cột cách nhau 2
    for (int i = 0; i < m; i++) {
        if (getBit(x, i)) {
            if (i + 1 < m && getBit(z, i + 1)) return false;
            if (i - 1 >= 0 && getBit(z, i - 1)) return false;
        }
    }
    return true;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int m; ll n;
        cin >> m >> n;
        int lim = 1 << m; //2 ^ m: Số trạng thái của 1 cột với m hàng
        int num[16][16];
        for (int i = 0; i < 16; i++){
            for (int j = 0; j < 16; j++) num[i][j] = -1;
		}
        int r = 0;
		// Xét các cặp trạng thái kề nhau giữa các cột, đánh STT cho chúng
        for (int x = 0; x < lim; x++) {
            for (int y = 0; y < lim; y++) {
                if (val1(x, y, m)) num[x][y] = r++;
            }
        }
        matrix mat;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < r; j++) mat.a[i][j] = 0;
		}
		//(x, y, z) là trạng thái của 3 cột liên tiếp
        for (int x = 0; x < lim; x++) {
            for (int y = 0; y < lim; y++) {
                for (int z = 0; z < lim; z++) {
                    int u = num[x][y];
                    int v = num[y][z];
                    if (u != -1 && v != -1 && val2(x, z, m)) mat.a[u][v] = 1;
                }
            }
        }
        ll res = 0;
        if (n == 1) res = (1LL << m) % MOD;
		// Có 1 cột thì mỗi ô có thể đặt hoặc không
        else {
            matrix powerMat = powMod(mat, n - 2, r);
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < r; j++) res = (res + powerMat.a[i][j]) % MOD;
			}
        }
        cout << res << "\n";
    }
}
