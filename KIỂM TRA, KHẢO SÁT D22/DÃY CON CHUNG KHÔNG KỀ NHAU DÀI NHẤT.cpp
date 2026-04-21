#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005] = {};

int sol(int a[], int n, int b[], int m){
    memset (dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
            if (a[i] == b[j]){
                int prev = (i >= 2 && j >= 2) ? dp[i - 2][j - 2] : 0;
                dp[i][j] = max (dp[i][j], prev + 1);
            }
        }
    }
    return dp[n][m];
}

int main(){
    int t; cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        int a[1009], b[1009];
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> b[i];
        cout << sol (a, n, b, m) << endl;
    }
}
