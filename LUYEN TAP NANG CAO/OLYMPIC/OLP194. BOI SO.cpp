#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e18;
int main() {
    ll n;
    cin >> n;
    vector<ll> d(n, inf); 
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    for (ll i = 1; i < 10; ++i) {
        if (i < n) {
            d[i] = i;
            pq.push({i, i});
        }
    }
    while (!pq.empty()) {
        ll w = pq.top().first, u = pq.top().second;
        pq.pop();
        if (w != d[u]) continue;
        for (ll i = 0; i < 10; ++i) {
            ll x = (u * 10 + i) % n;
            if (d[x] > d[u] + i) {
                d[x] = d[u] + i;
                pq.push({d[x], x});
            }
        }
    }
    cout << d[0];
}

