#include<bits/stdc++.h>
using namespace std;

int check(long long x){
	string s = to_string(x);
	set<char>sc;
	for(char i: s) sc.insert(i);
	if(sc.size()==s.size()) return 1;
	else return 0;
}

vector<long long>v;

void gen(){
	//Buoc 1: Khoi tao
	queue<long long>q;
	for(int i = 0;i<=5;i++) q.push(i), v.push_back(i);
	q.pop();//vut so 0
	
	//Buoc 2: Lap
	while(1){
		long long x = q.front();
		q.pop();
		if(x>1e5) break;
		for(int i = 0;i<=5;i++){
			long long x1 = x * 10 + i;
			if(check(x1)){
				q.push(x1);
				v.push_back(x1);
			}
		}
	}
}

int main(){
	gen();
	int t;
	cin>>t;
	while(t--){
		int l, r;
		cin>>l>>r;
		int cnt = 0;
		for(auto i: v){
			if(i>=l&&i<=r) cnt++;
		}
		cout<<cnt<<endl;
	}
}