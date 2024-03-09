#include<bits/stdc++.h>
using namespace std;

int a[10005] = {};

void solve(string s){
	vector<string>v;
	stringstream ss(s);
	string token;
	while(ss>>token){
		if(token!="+") v.push_back(token);
	} 
	for(auto i: v){
		int x1 = 0, x2 = 0, pos;
		for(int j = 0;j<i.size();j++){
			if(i[j]=='*') pos = j;
		}
		for(int j = 0;j<=pos-1;j++) x1 = x1*10 + (i[j] - '0');//He so
		for(int j = pos + 3;j<i.size();j++) x2 = x2*10 + (i[j] - '0');//So mu
		a[x2] += x1;
	}
}

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		memset(a, 0, sizeof(a));
		solve(s1);
		solve(s2);
		vector<pair<int,int>>v;//a[i] luu he so cua hang tu bac i
		for(int i=10000;i>=0;i--){
			if(a[i]) v.push_back({i,a[i]});
		}
		int n = v.size();
		for(int i = 0;i<n-1;i++) cout<<v[i].second<<"*x^"<<v[i].first<<" + ";
		cout<<v[n-1].second<<"*x^"<<v[n-1].first<<endl; //Phan tu cuoi cung k co dau "+"
	}
}
/*
1
3*x^8 + 7*x^2 + 4*x^1
11*x^6 + 9*x^2 + 2*x^1 */