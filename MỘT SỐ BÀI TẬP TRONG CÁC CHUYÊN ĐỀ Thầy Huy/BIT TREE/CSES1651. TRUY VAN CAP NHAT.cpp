#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 100009;
int n, a[MAXN];
ll BIT[MAXN]; // BIT[i]: Tổng các số a[j], j thuộc cây con gốc i
ll diff[MAXN]; // diff[i]: Mảng chênh lệch để xử lý các cập nhật phạm vi

void update(int x, int p) {
    while (x <= n) {
        BIT[x] += p;
        x += x & (-x); // x mới = cha x cũ
    }
}

// Lấy tổng từ a[1] + a[2] + ... + a[x]
ll getSum(int x) {
    ll res = 0;
    while (x > 0) {
        res += BIT[x];
        x -= x & (-x); // x mới = số lớn nhất, không vượt quá x và không là con của x
    }
    return res;
}

int main() {
    int q;
    cin >> n >> q; 
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; 
        diff[i] = a[i] - a[i - 1]; 
        update(i, diff[i]); // Cập nhật BIT với giá trị chênh lệch
    }

    while (q--) {
        int type;
        cin >> type; 
        if (type == 1) {
            int l, r, u; // Tăng tất cả các phần tử trong [l, r] lên u đơn vị
            cin >> l >> r >> u;
            update(l, u);
            update(r + 1, -u);
        } else if (type == 2) {
            int k;
            cin >> k; // Nhập chỉ số cần lấy tổng
            cout << getSum(k) << endl;
        }
    }

    return 0;
}
//https://lqdoj.edu.vn/problem/cses1651
