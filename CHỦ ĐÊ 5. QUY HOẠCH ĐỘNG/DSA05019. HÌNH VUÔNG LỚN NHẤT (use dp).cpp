#include<bits/stdc++.h>
using namespace std;

bool a[505][505];
int dp[505][505];

int main(){
    int t;
    cin >> t;
    while(t--){
    	int n, m;
        cin >> n >> m;
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                cin >> a[i][j];
                dp[i][j] = a[i][j];
                if(dp[i][j]) ans = 1;
            }
        }
        for(int i = 0; i <= n; ++i) dp[0][i] = 0;
        for(int i = 0; i <= m; ++i) dp[i][0] = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(a[i][j]){
                    if(!a[i - 1][j] or !a[i][j - 1] or !a[i - 1][j - 1]) continue;
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
