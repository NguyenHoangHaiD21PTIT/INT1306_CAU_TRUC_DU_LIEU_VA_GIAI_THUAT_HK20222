#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 100000 + 5;

int n, a[MAXN];
ll BIT[MAXN]; // Fenwick: đếm tần suất giá trị trong [1..n]

// Cập nhật: tăng tần suất tại chỉ số x thêm p
void update(int x, ll p) {
    while (x <= n) {
        BIT[x] += p;
        x += x & (-x);
    }
}

// Lấy tổng tần suất trong đoạn [1..x]
ll getSum(int x) {
    ll res = 0;
    while (x > 0) {
        res += BIT[x];
        x -= x & (-x);
    }
    return res;
}

void resetBIT() {
    memset(BIT, 0, sizeof(ll) * (n + 2));
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<long long> L(n + 1, 0), R(n + 1, 0);
        resetBIT();
        // Lưu tần suất theo giá trị các phần tử đã đi qua. Tìm số phần tử bên trái A[j] mà lớn hơn A[i]
        for (int j = 1; j <= n; j++) {
            int x = a[j];
            // Tổng tần suất của các giá trị [1 ... n] - Tổng tần suất các giá trị từ [1 ... x]
            // Như vậy, mảng BIT lưu tổng tần suất
            L[j] = getSum(n) - getSum(x);
            update(x, 1); 
        }
        resetBIT();
        // Số phần tử bên phải A[j] mà nhỏ hơn A[j]
        for (int j = n; j >= 1; j--) {
            int x = a[j];
            R[j] = getSum(x - 1);
            update(x, 1);
        }
        long long ans = 0;
        for (int j = 1; j <= n; j++) ans += L[j] * R[j];
        cout << ans << '\n';
    }
}
