#include<bits/stdc++.h>
using namespace std;

string s = "012";
vector<string>v;

int check(string s){
	map<char, int>mp;
	for(auto i: s) mp[i]++;
	if(mp['2']>s.size()/2) return true;
	else return false;
}

void gen(){
	//Buoc 1: Khoi tao
	queue<string>q;
	q.push("1"); q.push("2");
	v.push_back("2");
	//Buoc 2: Lap
	while(1){
		string x = q.front();
		q.pop();
		if(v.size()==1005) break;
		for(char i: s){
			string s1 = x + i;
			q.push(s1);
			if(check(s1)) v.push_back(s1);
		}
	}
}

int main(){
	int t;
	cin>>t;
	gen();
	while(t--){
		int n;
		cin>>n;
		for(int i = 0;i<n;i++) cout<<v[i]<<" ";
		cout<<endl;
	}
}
