#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, MAX = 100050;  
long long fac[MAX], ivFac[MAX];  

long long powMod(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

void pre() {
    fac[0] = 1;
    for (long long i = 1; i < MAX; ++i) fac[i] = fac[i - 1] * i % MOD;
    ivFac[MAX - 1] = powMod(fac[MAX - 1], MOD - 2);  
    for (long long i = MAX - 2; i >= 0; --i) ivFac[i] = ivFac[i + 1] * (i + 1) % MOD;
}

long long C(long long n, long long k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * ivFac[k] % MOD * ivFac[n - k] % MOD;
}

int main() {
    long long N, M;
    cin >> N >> M;
    pre();
    vector<pair<long long, long long>> f;
    for (int i = 2; i * i <= M; ++i) {
        long long cnt = 0;
        while (M % i == 0) {
            M /= i;
            cnt++;
        }
        if (cnt > 0) f.push_back({i, cnt});
    }
    if (M > 1) f.push_back({M, 1});
    long long res = 1;
    for (auto x: f) {
        long long p = x.first, k = x.second;
        long long comb = C(k + N - 1, k);
        res = res * comb % MOD;
    }
    cout << res;
}