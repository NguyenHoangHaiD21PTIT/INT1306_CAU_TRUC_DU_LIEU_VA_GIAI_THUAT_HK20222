#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n; 
vector<ll> a;
vector<int> b; // mảng nhị phân
int ok;        // còn sinh được không

ll LCM(ll x, ll y) {
    return x / __gcd(x, y) * y;
}

void init() {
    b.assign(n, 0);
    ok = 1;
}

void sinh() {
    int i = n - 1;
    while (i >= 0 && b[i] == 1) {
        b[i] = 0;
        i--;
    }
    if (i == -1) ok = 0;
    else b[i] = 1;
}

// Đếm số phần tử còn lại ≤ x (Đếm số phần tử <= x mà không chia hết cho bất kì số nào trong A)
ll cnt(ll x) {
    ll res = 0;//Số phần tử chia hết cho ít nhất 1 trong các số của dãy
    init();
    while (ok) {
        // Tính LCM cả tập con
        ll cur = 1;
        bool val = false; // có chọn ít nhất 1 phần tử
        for (int i = 0; i < n; i++) {
            if (b[i]) {
                val = true;
                cur = LCM(cur, a[i]);
                if (cur > x) { 
                    val = false;
                    break;
                }
            }
        }
        //Ta biết rằng số lượng số <=x chia hết cho K là [x / K]. Như vậy, số phần tử chia hết cho LCM cả dãy, <=x là [x / LCM]
        if (val) {
            // Đếm số phần tử trong tập con
            int d = 0;
            for(int i = 0; i < n; i++){
                if(b[i]) d++;
            }
            if (d % 2 == 1) res += x / cur;
            else res -= x / cur;
        }
        sinh();
    }
    return x - res;
}

// Tìm số thứ k
// Tìm cận m min sao cho trong [1; m] còn lại ít nhất K số
ll find(ll k) {
    ll l = 1, r = 1e18, ans = -1;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (cnt(m) >= k) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}

int main() {
    int T; cin >> T;
    while (T--) {
        ll k;
        cin >> n >> k;
        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << find(k) << "\n";
    }
}
