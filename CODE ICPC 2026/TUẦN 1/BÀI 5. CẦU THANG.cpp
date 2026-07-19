#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    int n, m; 
    cin >> n >> m;
    vector <int> d(n + 1, 0);//d: Bẩn
    while (m--){
        int x; cin >> x;
        d[x] = 1;
    }
    vector <int> dp (n + 1, 0);
    dp[0] = 1;
    if (!d[1]) dp[1] = 1;
    for (int i = 2; i <= n; i++){
        if (!d[i]) dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    cout << dp[n];
}