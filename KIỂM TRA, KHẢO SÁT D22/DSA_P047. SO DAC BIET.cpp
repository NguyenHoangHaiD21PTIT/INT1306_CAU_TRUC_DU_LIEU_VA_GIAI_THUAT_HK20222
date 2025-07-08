#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const ll oo = 1e18 + 8;
const int mxn = 1e6 + 9;

bool nt[200];

void sang() {
    for (int i = 2; i <= 150; ++i) nt[i] = true;
    for (int i = 2; i <= 40; ++i) {
        if (nt[i]) {
            for (int j = i * i; j <= 150; j += i) nt[j] = false;
        }
    }
}

ll dp[2][200][200][3];

int main() {
    sang();
    ll n;
    cin >> n;
    vector<int> a;
    while (n) {
        a.push_back(n % 10);
        n /= 10;
    }
    dp[0][0][0][0] = 1;
    ll cur = 0, m = static_cast<ll>(a.size());
    for (ll i = 0; i < m; ++i) {
        ll nxt = 1 - cur;
        memset(dp[nxt], 0, sizeof dp[nxt]);
        for (ll sumx = 0; sumx <= i * 9; ++sumx) {
            for (ll sumy = 0; sumy <= i * 9; ++sumy) {
                for (ll nho = 0; nho <= 2; ++nho) {
                    if (dp[cur][sumx][sumy][nho]) {
                        for (ll x = 0; x <= 9; ++x) {
                            for (ll y = 0; y <= 9; ++y) {
                                ll d = x + y * 2 + nho;
                                if (d % 10 != a[i]) continue;
                                ll nho2 = d / 10;
                                dp[nxt][sumx + x][sumy + y][nho2] += dp[cur][sumx][sumy][nho];
                            }
                        }
                    }
                }
            }
        }
        cur = nxt;
    }

    ll res = 0;
    for (ll sumx = 2; sumx <= m * 9; ++sumx) {
        if (nt[sumx]) {
            for (ll sumy = 2; sumy <= m * 9; ++sumy) {
                if (nt[sumy]) res += dp[cur][sumx][sumy][0];
            }
        }
    }

    cout << res;
}
