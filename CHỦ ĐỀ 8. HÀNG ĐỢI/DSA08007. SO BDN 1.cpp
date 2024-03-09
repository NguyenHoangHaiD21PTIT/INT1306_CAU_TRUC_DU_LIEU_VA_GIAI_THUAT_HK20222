#include<bits/stdc++.h>
using namespace std;

vector<long long>v;

void gen(){
	//Buoc 1: Khoi tao
	queue<string>q;
	q.push("1");
	v.push_back(1);
	//Buoc 2: Lap
	while(1){
		string x = q.front();
		q.pop();
		if(x.size()==19) break;
		string x1 = x + "0";
		string x2 = x + "1";
		q.push(x1); q.push(x2);
		long long n1 = stoll(x1);
		long long n2 = stoll(x2);
		v.push_back(n1); v.push_back(n2);
	}
}

int main(){
	gen();
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long cnt = 0;
		for(auto i: v){
			if(i>n) break;
			cnt++;
		}
		cout<<cnt<<endl;
	}
}