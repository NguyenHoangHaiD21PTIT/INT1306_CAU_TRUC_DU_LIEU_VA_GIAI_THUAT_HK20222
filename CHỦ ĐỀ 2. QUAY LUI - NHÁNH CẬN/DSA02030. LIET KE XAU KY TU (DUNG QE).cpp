#include<bits/stdc++.h>
using namespace std;

int k; vector<string>v; string s ="";

int check(string x){
	for(int i = 0;i<x.size()-1;i++){
		if(x[i]>x[i+1]) return 0;
	}
	return 1;
}

void gen(){
	//Buoc 1: Khoi tao
	queue<string>q;
	for(int i = 0;i<s.size();i++){
		string tmp = "";
		tmp+=s[i];
		q.push(tmp);
		if(k==1) v.push_back(tmp);
	}
	
	//Buoc 2: Loang
	while(1){
		string x = q.front();
		q.pop();
		if(x.size()==k) break;
		for(int i = 0;i<s.size();i++){
			string x1 = x + s[i];
			if(check(x1)){
				q.push(x1);
				if(x1.size()==k) v.push_back(x1);
			}
		}
	}
	
}
int main(){
	//Buoc 1: Tao xau de lay du lieu khoi tao
	char c; cin>>c;
	cin>>k;
	s = s + c;
	while(c>'A'){
		c--;
		s = c + s;
	}
	gen();
	for(auto i: v) cout<<i<<endl;
}