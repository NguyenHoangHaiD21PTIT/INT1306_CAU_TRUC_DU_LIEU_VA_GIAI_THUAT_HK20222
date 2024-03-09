#include<bits/stdc++.h>
using namespace std;

vector<long long>v;

void gen(){
	//Buoc 1: Khoi tao
	queue<long long>q;
	q.push(1);
	v.push_back(1);
	//Buoc 2: Lap
	while(1){
		long long x = q.front();
		q.pop();
		if(x==1e18) break;
		long long x1 = x*10;
		long long x2 = x*10 + 1;
		q.push(x1); q.push(x2);
		v.push_back(x1); v.push_back(x2);
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
		for(long long i: v){
			if(i>n) break;
			cnt++;
		}
		cout<<cnt<<endl;
	}
}