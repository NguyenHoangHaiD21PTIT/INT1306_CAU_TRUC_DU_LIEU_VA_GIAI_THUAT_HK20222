#include<bits/stdc++.h>
using namespace std;

int dp[105][105]={};

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp, 0, sizeof(dp));
		string s;
		cin>>s;
		int n = s.size();
		for(int i = n-2;i>=0;i--){
			for(int j=i+1;j<=n-1;j++){
				if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1];
				else dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
			}
		}
		cout<<dp[0][n-1]<<endl;
	}
}
