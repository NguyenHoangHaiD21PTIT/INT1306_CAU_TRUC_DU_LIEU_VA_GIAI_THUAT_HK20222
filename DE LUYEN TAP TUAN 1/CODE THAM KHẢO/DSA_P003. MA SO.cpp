#include<bits/stdc++.h>
using namespace std;

int n; vector<string>v2;

void gen(){
	queue<string>q;
	for(int i = 1;i<=n;i++){
	 	string tmp="";
		tmp+=to_string(i);
		q.push(tmp);
	}
	while(1){
		string x = q.front();
		q.pop();
		if(x.size()==n) break;
		for(int i = 1;i<=n;i++){
			string x1 = x + to_string(i);
			q.push(x1);
			if(x1.size()==n)  v2.push_back(x1);
		}
	}
}

int main(){
	cin>>n;
	gen();
	char c='A';
	string s1="A";
	for(int i=1;i<n;i++){
		c++;
		s1=s1+c;
	}
	vector<string>v1;
	v1.push_back(s1);
	while(next_permutation(s1.begin(),s1.end())!=false) v1.push_back(s1);
	for(auto i: v1){
		for(auto j: v2) cout<<i<<j<<endl;
	} 
}
