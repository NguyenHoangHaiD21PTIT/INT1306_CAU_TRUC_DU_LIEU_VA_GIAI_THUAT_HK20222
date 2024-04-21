#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		set<char>se;
		for(int i=0;i<s.size();i++) se.insert(s[i]);
		int k = se.size();
		map<char,int>mp;
		int l = 0, ans = 1e9;
		for(int r = 0;r<s.size();r++){
			mp[s[r]]++;
			while(mp.size()==k){
				ans = min(ans, r-l+1);
				mp[s[l]]--;
				if(mp[s[l]]==0) mp.erase(s[l]);
				l++;
			}
		}
		cout<<ans<<endl;
	}
}
/*
2
aabcbcdbca
aaab */
