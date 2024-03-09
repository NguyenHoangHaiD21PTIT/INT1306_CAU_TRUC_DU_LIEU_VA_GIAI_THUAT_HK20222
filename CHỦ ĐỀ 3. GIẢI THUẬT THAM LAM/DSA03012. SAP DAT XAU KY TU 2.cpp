#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int d;
		cin>>d;
		string s;
		cin>>s;
		int n = s.size();
		map<char,int>mp;
		for(char x: s) mp[x]++;
		int k = 0;
		for(auto i: mp){
			if(i.second>k) k = i.second;
		}
		if(s.size()>=k*d-(d-1)) cout<<1<<endl;
		else cout<<-1<<endl;
	}
}