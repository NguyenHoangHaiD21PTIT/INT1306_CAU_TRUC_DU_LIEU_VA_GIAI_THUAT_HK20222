#include <bits/stdc++.h>
using namespace std;

const int LIM = 1e7 + 7;
vector<int> P;
using ll = long long;

void sieve() {
    vector<bool> f(LIM + 1, true);
    f[0] = f[1] = false;
    for (ll i = 2; i * i <= LIM; i++) {
        if (f[i]){
            for (ll j = i * i; j <= LIM; j += i) f[j] = false;
        }
    }
    for (ll i = 2; i <= LIM; i++) {
        if (f[i]) P.push_back(i);
    }
}

map<ll, ll>fact (ll x){
    map<ll, ll> cnt;
    for(ll p: P){
        if(p * p > x) break;
        while(x % p == 0){
            cnt[p]++;
            x /= p;
        }
    }
    if (x > 1) cnt[x]++;
    return cnt;
}

bool check(map<ll, ll> A, map<ll, ll>B){
    for(auto kv: B){ //kv = x^y
        ll x = kv.first, y = kv.second;
        if(A[x] < y) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int N, M; 
    cin >> N >> M;
    map<ll, ll> A; 
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        auto tmp = fact(x);       
        for (auto kv : tmp) A[kv.first] += kv.second; 
    }
    vector<int> ans;
    for (int i = 1; i <= M; i++) {
        map<ll, ll> B;
        for (int j = 0; j < N; j++) {
            ll x; cin >> x;
            auto tmp = fact(x);
            for (auto kv : tmp) B[kv.first] += kv.second;
        }
        if (check(A, B)) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
}