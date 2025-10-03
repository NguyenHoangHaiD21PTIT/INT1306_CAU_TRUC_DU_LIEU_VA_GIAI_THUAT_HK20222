#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 9999;

int main() {
    int n; cin >> n;
    vector<long long>  L(n + 1), R(n + 1);
    for (int i = 1; i <= n; i++) cin >> L[i] >> R[i];
    long long ans = 0;
    vector<int>  x(n + 1);
    //Tổ hợp nhỏ nhất
    for (int i = 1; i <= n; i++) x[i] = L[i];
    while (true) {
        int mx = 0;
        for (int i = 1; i <= n; i++) mx = max(mx, x[i]);
        ans = (ans + mx) % MOD;
        int pos = n;
        while (pos >= 1 && x[pos] == R[pos]) pos--;
        if (pos == 0) break;
        x[pos] += 1;
        for (int i = pos+1; i <= n; i++) x[i] = L[i];
    }
    cout << ans;
}
