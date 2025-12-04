#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int n, q;
vector<int> a; vector<ll> f; // f[i]: chi phí nhỏ nhất để đến vị trí i

void solve() {
    int s, t, k;
    cin >> s >> t >> k;
    s--; t--; 
    if (s == t) { 
        cout << a[s] << "\n"; 
        return; 
    }
    if (s > t) swap(s, t);
    fill(f.begin() + s, f.begin() + t + 1, INF);
    f[s] = a[s];
    // Đi từ s đến t hay t đến s đều giống nhau
    for (int i = s + 1; i <= t; ++i) {
        ll mn = INF;
        // Để đến được i, ta phải đi từ một trong k vị trí trước i
        int L = max(s, i - k); 
        for (int j = i - 1; j >= L; --j) mn = min(mn, f[j]);
        f[i] = mn + a[i];
    }
    cout << f[t] << "\n";
}

int main() {
    string s; cin >> n >> q >> s;
    a.resize(n); f.resize(n);
    for(int i=0; i<n; ++i) a[i] = s[i] - '0';
    while(q--) solve();
}
