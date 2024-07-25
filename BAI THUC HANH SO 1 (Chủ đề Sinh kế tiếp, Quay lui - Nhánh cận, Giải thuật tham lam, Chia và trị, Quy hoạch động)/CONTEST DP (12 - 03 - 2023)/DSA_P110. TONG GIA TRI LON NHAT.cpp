#include<bits/stdc++.h>
using namespace std;

int dp[6000][6000]={}; //dp[i][j] la GTLN cua cai tui trong luong j khi mang i do vat

int main(){
	memset(dp,0,sizeof(dp));
	int n, s; //n: so do vat, s: khoi luong cai tui
	cin>>n>>s;
	int w[6000], v[6000];//w: khoi luong, v: gia tri
	for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s;j++){
			dp[i][j] = dp[i-1][j];
			if(j>=w[i]) dp[i][j] = max (dp[i][j], dp[i-1][j-w[i]] + v[i]);
		}
	}
	cout<<dp[n][s]<<endl;
}
