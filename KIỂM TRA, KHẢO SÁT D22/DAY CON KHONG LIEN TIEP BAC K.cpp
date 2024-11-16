#include<bits/stdc++.h>
using namespace std;
const int mxn = 1e4 + 7;
int main() {
    int n, k;
    cin >> n >> k;
    int a[n + 1], sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (k > n) {
        cout << sum;
        return 0;
    }
    int dp[mxn];
    dp[1] = a[1];
    for (int i = 2; i <= n; i++) {
        int mi = dp[i - 1];
        for (int j = i - 2; j >= i - k && j >= 0; j--) mi = min(mi, dp[j]);
        dp[i] = a[i] + mi;
    }
    int res = INT_MAX;
    for (int i = n - k + 1; i <= n; i++) res = min(res, dp[i]);
    cout << sum - res;
}
