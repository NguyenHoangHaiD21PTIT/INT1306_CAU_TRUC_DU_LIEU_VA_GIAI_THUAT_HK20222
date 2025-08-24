#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 100005;
int n, a[MAXN];
ll bit[MAXN];

void upd(int x, ll p) {
    while (x <= n + 2) { 
        bit[x] += p;
        x += x & -x;
    }
}

ll sum(int x) {
    ll res = 0;
    while (x > 0) {
        res += bit[x];
        x -= x & -x;
    }
    return res;
}

//BIT lưu tần suất
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> d(n+2, 0);
    ll cnt = 0;
    //1 - based
    for (int j = 0; j < n; ++j) {
        int v = a[j];
        ll le = sum(v + 1);      // số phần tử ≤ a[j] đã thấy. Tính tổng tần suất từ 0 đến a[j]
        ll gt = cnt - le;       // số phần tử > a[j] đã thấy
        // X1, X2, ... Xn, A[j]: Có n số lớn hơn A[j] --> n cặp này sẽ bật lên tại ngưỡng A[j] + 1
        if (v <= n-2) d[v + 1] += gt;
        upd(v + 1, 1);            // ghi nhận đã thấy thêm a[j]
        ++cnt;
    }
    ll cur = 0;
    for (int x = 0; x <= n-1; ++x) {
        cur += d[x];
        cout << cur << "\n";
    }
}
