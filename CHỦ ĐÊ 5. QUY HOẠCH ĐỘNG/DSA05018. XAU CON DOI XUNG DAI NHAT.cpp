#include<bits/stdc++.h>
using namespace std;

bool dp[1005][1005];

int main(){
	int t;
	cin>>t;
	while(t--){
		int ans = -1e9;
		string s;
		cin>>s;
		memset(dp, false, sizeof(dp));
		int n = s.size();
		for(int i = n - 1;i>=0;i--){
			for(int j = i;j<=n-1;j++){
				if(i==j) dp[i][j] = true;
				else if (s[i] ==s[j]) {
					if(j-i==1) dp[i][j] = true;
					else dp[i][j] = dp[i+1][j-1];
				}
				if(dp[i][j]) ans = max(ans, j-i+1);
			}
		}
		cout<<ans<<endl;
	}
}

/*
2
abcbadd
aaaaa */