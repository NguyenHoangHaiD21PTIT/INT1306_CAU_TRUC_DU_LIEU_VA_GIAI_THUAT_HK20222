#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005]={};

int solve(string s1, string s2){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=s1.size();i++){
		for(int j=1;j<=s2.size();j++){
			if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max (dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[s1.size()][s2.size()];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s1, s2;
		cin>>s1>>s2;
		cout<<solve(s1,s2)<<endl;
	}
}
/*
2
AGGTAB
GXTXAYB
AA
BB */