#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : llabs(a); }
int mod(ll x, int p) { int r = int(x % p); return r < 0 ? r + p : r; }

vector<int> sieve(int n) {
    vector<bool> is(n + 1, 1);
    vector<int> primes;
    is[0] = is[1] = 0;
    for (int i = 2; i * i <= n; ++i){
        if (is[i]){
            for (int j = i * i; j <= n; j += i) is[j] = 0;
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (is[i]) primes.push_back(i);
    }
    return primes;
}

int main() {
    int N; cin >> N;
    vector<ll> t(N + 1), a(N + 1);
    for (int i = 0; i <= N; ++i) cin >> t[i];
    for (int i = 0; i <= N; ++i) a[i] = t[N - i];
    ll g = 0;
    for (ll x : a) g = GCD(g, llabs(x));
    set<ll> ans;
    ll x = g;
    if (x > 1) {
        while (x % 2 == 0) { 
            ans.insert(2); 
            x /= 2; 
        }
        for (ll p = 3; p * p <= x; p += 2){
            if (x % p == 0) { 
                ans.insert(p); 
                while (x % p == 0) x /= p; 
            }
        }
        if (x > 1) ans.insert(x);
    }
    auto primes = sieve(N);
    for (int p : primes) {
        if (mod(a[0], p) != 0) continue;
        vector<int> b(p, 0);
        for (int i = 1; i <= N; ++i) {
            int d = (i - 1) % (p - 1) + 1;
            b[d] += mod(a[i], p);
            if (b[d] >= p) b[d] -= p;
        }
        bool ok = true;
        for (int d = 1; d <= p - 1; ++d){
            if (b[d] % p != 0) { 
                ok = false; 
                break; 
            }
        }
        if (ok) ans.insert(p);
    }
    bool first = 1;
    for (ll p : ans) cout << p << endl;
}
//Sưu tầm
