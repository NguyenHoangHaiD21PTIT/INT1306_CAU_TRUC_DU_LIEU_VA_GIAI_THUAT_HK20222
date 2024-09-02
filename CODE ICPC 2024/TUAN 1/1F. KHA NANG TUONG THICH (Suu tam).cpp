#include "bits/stdc++.h"
using namespace std;
using ll = long long;
 
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif
 
#define int long long
 
const int K = 5;
const int MOD = 1e9 + 7;
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
 
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif
 
 
    int n;
    cin >> n;
    vector <array <int, 5>> a(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j)
            cin >> a[i][j];
    }
 
    map <ll, int> cnt[K + 1];
 
    for (int i = 0; i < n; ++i) {
        array <int, 5> subset;
        for (int msk = 0; msk < (1 << K); ++msk) {
            int k = 0;
            for (int j = 0; j < 5; ++j) {
                if (msk & (1 << j)) {
                    subset[j] = a[i][j];
                    ++k;
                }
                else    
                    subset[j] = 0;
            }
            sort(subset.begin(), subset.end());
            ll val = 0;
            ll p = 1;
            for (int j = 0; j < 5; ++j) {
                if (subset[j]) {
                    val = (val * p + subset[j]);
                    p *= MOD;
                }
            }
            cnt[k][val]++;
        }
    }
 
 
    ll tot = 1LL * n * (n - 1) / 2;
 
    ll invalid = 0;
    for (int i = 1; i <= K; ++i) {
        for (const auto& [x, y] : cnt[i]) {
            if (i & 1)
                invalid += 1LL * y * (y - 1) / 2;
            else 
                invalid -= 1LL * y * (y - 1) / 2;
        }
    }
 
    cout << (tot - invalid) << "\n";
 
    return 0;
}