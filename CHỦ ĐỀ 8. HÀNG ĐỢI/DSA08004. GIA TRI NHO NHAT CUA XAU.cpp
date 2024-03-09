#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		string s;
		cin>>s;
		map<char, long long> mp;
		for(char i: s) mp[i]++;
		priority_queue<long long>pq;
		for(auto i: mp) pq.push(i.second);
		while(k--){
			long long x = pq.top();
			x--;
			pq.pop();
			if(x>=0) pq.push(x);
		}
		long long ans = 0;
		while(pq.size()>0){
			long long x = pq.top();
			ans+=x*x;
			pq.pop();
		}
		cout<<ans<<endl;
	}
}