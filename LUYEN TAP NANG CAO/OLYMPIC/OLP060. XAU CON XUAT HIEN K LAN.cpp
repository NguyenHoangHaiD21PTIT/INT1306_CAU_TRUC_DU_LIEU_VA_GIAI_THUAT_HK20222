#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5, p = 1e9 + 13;

ll n, k, ans;
string s;
ll Pow[N], Hash[N];

void pre() {
    Pow[0] = 1;
    for (ll i = 1; i < N; i++) Pow[i] = (Pow[i - 1] * 26) % p;
}

ll get(ll i, ll j) { 
    return (Hash[j] - (Hash[i - 1] * Pow[j - i + 1]) + p) % p;
}

void solution() {
    ans = 0;
    ll left = 1, right = n;
    while (left <= right) {
        ll mid = (left + right) / 2;
        // lưu tất cả hash các dãy con có độ dài mid, kết thúc tại i
        vector<ll> d;
        for (ll i = mid; i <= n; i++) d.push_back(get(i - mid + 1, i));
        sort(d.begin(), d.end());
        ll cnt = 1;
        bool found = false;
        for (ll i = 1; i < d.size(); i++) {
            if (d[i] == d[i - 1]) cnt++; 
            else cnt = 1;
            if (cnt >= k) { 
                found = true;
                break;
            }
        }
        if (found) {
            ans = mid; 
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    cout << ans << endl; 
}

int main() {
    pre();
    ll t; 
    cin >> t; 
    while (t--) {
        cin >> n >> k >> s; 
        s = " " + s; 
        Hash[0] = 0;
        for (ll i = 1; i <= n; i++) Hash[i] = (Hash[i - 1] * 26 + (s[i] - 'a')) % p;
        if (k == 1) cout << n << endl; 
        else solution(); 
    }
}
