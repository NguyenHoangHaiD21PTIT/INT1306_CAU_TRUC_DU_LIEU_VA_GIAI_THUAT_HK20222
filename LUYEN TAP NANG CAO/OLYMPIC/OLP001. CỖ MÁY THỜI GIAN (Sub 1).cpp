#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
int n, Q; string str;
vector<int> a; 
using ll = long long;

void solve() {
    int s, t, k; 
    cin >> s >> t >> k; s--; t--; 

    if (s == t) {
        cout << a[s] << "\n";
        return;
    }

    vector<ll> d(n, INF); d[s] = a[s]; 
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; //{d[v], v}
    pq.push({d[s], s});

    while (!pq.empty()) {
        ll val = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (u == t) {
            cout << val << "\n";
            return;
        }
        if (val > d[u]) continue;
        // |u - x| <= k --> -k <= x - u <= k -> u - k <= x <= u + k
        int L = max(0, u - k), R = min(n - 1, u + k);
        for (int v = L; v <= R; ++v) {
            if (u == v) continue;
            if (d[u] + a[v] < d[v]) {
                d[v] = d[u] + a[v];
                pq.push({d[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> Q >> str;
    a.resize(n);
    for (int i = 0; i < n; ++i) a[i] = str[i] - '0';
    while (Q--) solve();
}
