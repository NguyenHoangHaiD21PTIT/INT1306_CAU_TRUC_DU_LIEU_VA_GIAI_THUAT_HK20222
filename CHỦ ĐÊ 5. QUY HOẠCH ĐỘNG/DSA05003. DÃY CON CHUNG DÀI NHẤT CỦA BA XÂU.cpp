#include<bits/stdc++.h>
using namespace std;
int dp[105][105][105]={};
int main(){
	int t; cin >> t;
	while(t--){
		memset(dp, 0, sizeof(dp));
		int n1, n2, n3; string s1, s2, s3;
		cin >> n1 >> n2 >> n3 >> s1 >> s2 >> s3;
		for(int i = 1; i <= n1; i++){
			for(int j = 1; j <= n2; j++){
				for(int k = 1; k <= n3; k++){
					if(s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
					else dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
				}
			}
		}
		cout << dp[n1][n2][n3] << endl;
	}
}
