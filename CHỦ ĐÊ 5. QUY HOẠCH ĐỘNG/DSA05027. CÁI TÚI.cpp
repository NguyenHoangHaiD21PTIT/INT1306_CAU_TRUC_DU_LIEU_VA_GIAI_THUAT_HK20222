#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005] = {}; //dp[i][j]: Giá trị lớn nhất của cái túi có sức chứa j khi xét đến vật thứ i
int main(){
	int t; cin >> t;
	while(t--){
		memset(dp, 0, sizeof(dp));
		int n, s; cin >> n >> s;
		int w[1005], v[1005];//w: khoi luong, v: gia tri
		for(int i = 1; i <= n; i++) cin >> w[i];
		for(int i = 1; i <= n; i++) cin >> v[i];
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= s; j++){
				dp[i][j] = dp[i - 1][j];
				if(j >= w[i]) dp[i][j] = max (dp[i][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
		cout << dp[n][s] << endl;
	}
}
