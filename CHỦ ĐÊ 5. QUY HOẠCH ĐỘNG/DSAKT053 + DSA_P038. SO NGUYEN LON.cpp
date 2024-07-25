#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int main(){
	int t;
	cin>>t;
	while(t--){
		string s1, s2;
		cin>>s1>>s2;
		memset(dp,0, sizeof(dp));
		int n = s1.size(), m = s2.size();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
				else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			}
		}
		cout<<dp[n][m]<<endl;
	}
}
/*
2
144615
4976135
44
88 */
