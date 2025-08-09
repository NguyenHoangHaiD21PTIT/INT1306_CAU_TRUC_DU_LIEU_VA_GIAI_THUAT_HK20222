#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while (t--){
		int dp[105][105] = {};
		memset(dp, 0, sizeof(dp));
		int n, ans = 0; string s;
		cin >> n >> s;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(s[i - 1] == s[j - 1] && i != j) dp[i][j] = dp[i - 1][j - 1] + 1 ;
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				ans = max(ans, dp[i][j]);
			}
		}
		cout << ans << endl;
	}
}

