#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int x, y;
		cin>>x>>y;
		long long dp[50][50]={};
		memset(dp, 0, sizeof(dp));
		for(int i=0;i<=y;i++) dp[0][i] = 1;
		for(int i=0;i<=x;i++) dp[i][0] = 1;
		for(int i=1;i<=x;i++){
			for(int j=1;j<=y;j++){
				if(i!=0&&j!=0) dp[i][j] += dp[i-1][j] + dp[i][j-1];
			}
		}
		cout<<dp[x][y]<<endl;
	}
}