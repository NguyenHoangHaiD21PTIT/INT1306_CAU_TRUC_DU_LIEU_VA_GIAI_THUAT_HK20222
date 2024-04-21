#include<bits/stdc++.h>
using namespace std;

bool dp[5005][5005]={};

int main(){
	string s;
	cin>>s;
	memset(dp, false, sizeof(dp));
	int n = s.size();
	for(int i=n-1;i>=0;i--){
		for(int j=i;j<=n-1;j++){
			if(i==j){
				dp[i][j] = true;
			} else if (s[i]==s[j]) {
				if(j-i==1) dp[i][j] = true;
				else dp[i][j] = dp[i+1][j-1];
			}
		}
	}
	int q;
	cin>>q;
	while(q--){
		int l, r;
		cin>>l>>r;
		int l1 = l-1, r1 = r-1;
		if(dp[l1][r1]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
