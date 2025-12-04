#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n; ll k;
vector<ll> a;

/*Nhận xét: 
1. Tăng số này, giảm số kia thì tổng cả dãy không đổi. Do đó, giả sử UCLN của dãy là k, tổng cả dãy là B
a1k + a2k + ... + ank = k(a1 + a2 + ... + an) = k * S. Vậy k phải là ước của S.
2. Xét ước g. Ta viết B = k * g = a1 + ... + an = k1g + r1 + k2g + r2 + ... + kng + rn, = g(k1 + k2 + ... + kn) + (r1 + r2 + ... + rn)
Vậy tổng phần dư cũng phải chia hết cho g
3. Giả sử ta chọn a[i] để giảm, thì - r[i]. Còn nếu tăng a[i], thì + (g - r[i]). 
Giả sử có 5 số a1, a2, ..., a5. g - r1 + g - r2 = r3 + r4 + r5 --> 2g = r1 + r2 + r3 + r4 + r5
--> (r1 + r2 + r3 + r4 + r5) / g = 2. 2 chính là số phần tử ta chọn để tăng
Vậy Tổng số dư / g = Số phần tử cần tăng
*/
void run() {
    ll S = 0;
    for (ll x : a) S += x;
    vector<ll> D; 
    for (ll i = 1; i * i <= S; ++i) {
        if (S % i == 0) {
            D.push_back(i);
            if (i * i != S) D.push_back(S / i);
        }
    }
    sort(D.rbegin(), D.rend());
    for (ll g: D) {
        // Tính tổng các số dư khi chia cho g
        vector<ll> r; 
        ll r_sum = 0;
        for (ll x: a) {
            r.push_back(x % g);
            r_sum += x % g;
        }
        ll keep = n - (r_sum / g), cost = 0;
        sort(r.begin(), r.end());
        //Ta sẽ ưu tiên giảm các phần tử có số dư nhỏ nhất
        for (int i = 0; i < keep; ++i) cost += r[i];
        if (cost <= k) {
            cout << g << "\n";
            return;
        }
    }
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (auto &x : a) cin >> x;
    run();
}
