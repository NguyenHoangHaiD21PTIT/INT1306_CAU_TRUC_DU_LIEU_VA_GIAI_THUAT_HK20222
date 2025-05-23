#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n; cin>>n;
    ll a[105];ll dp[105][105] = {};
    for(ll i = 1;i<=n;i++) cin>>a[i];
    // dp[i][j]: giá trị lớn nhất thu được khi xét dãy từ a[i] đến a[j]
    for (ll len = 3; len <= n; len++) {
        for (ll i = 1; i + len - 1 <= n; i++) {
            //[i .. x] dài len --> x - i + 1 = len --> x = len+i - 1, x<=n
            ll j = i + len - 1;
            //k là phần tử ở giữa bị loại, i + 1 <= k <= j - 1
            for (ll k = i + 1; k < j; ++k) dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
            dp[i][j]+=a[i]*a[j];
        }
    }
    cout << dp[1][n];
}
