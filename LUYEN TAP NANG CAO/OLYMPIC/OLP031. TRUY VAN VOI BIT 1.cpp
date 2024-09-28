#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 100009;
int n, a[MAXN];
ll BIT[MAXN]; // BIT[i]: Tổng các số a[j], j thuộc cây con gốc i

// Hàm cập nhật BIT
void update(int x, ll p) {
    while (x <= n) {
        BIT[x] += p;
        x += x & (-x); // x mới = cha x cũ
    }
}

// Hàm lấy tổng từ a[1] + a[2] + ... + a[x]
ll getSum(int x) {
    ll res = 0;
    while (x > 0) {
        res += BIT[x];
        x -= x & (-x); // x mới = số lớn nhất, không vượt quá x và không là con của x
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]); //Khởi tạo BIT với giá trị gốc
    }
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, k; 
            cin >> u >> k;
            update(u, k); //Cập nhật BIT với giá trị K
            a[u] += k; // Cập nhật giá trị thực trong mảng a
        } else if (type == 2) {
            int u, v; 
            cin >> u >> v;
            cout << getSum(v) - getSum(u - 1) << endl; 
        }
    }
}
