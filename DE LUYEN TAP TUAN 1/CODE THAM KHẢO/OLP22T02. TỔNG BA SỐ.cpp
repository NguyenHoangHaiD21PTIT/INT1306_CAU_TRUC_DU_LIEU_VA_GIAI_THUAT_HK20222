#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005, MAX_VAL = 1000000; 
long long f[MAXN][MAXN];
int a[MAXN], frq[MAX_VAL * 3 + 5];
int main() {
    int n, q;
    cin >> n >> q;
    for (int t = 1; t <= n; t++) {
        cin >> a[t];
        a[t] += MAX_VAL;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int rem = MAX_VAL * 3 - a[i] - a[j];
            if (0 <= rem && rem < MAX_VAL * 3) f[i][j] = frq[rem];
            frq[a[j]]++;
        }
        for (int j = i + 1; j <= n; j++) frq[a[j]]--;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = i; j <= n; j++) f[i][j] += f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1];
    }
    for (int t = 1; t <= q; t++) {
        int l, r;
        cin >> l >> r;
        if (l > r) swap(l, r);
        cout << f[l][r] << "\n";
    }
}
