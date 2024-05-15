#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll,ll>>ke[100005];
ll d[100005]; //d[i] la khoang cach tu i toi dinh nguon
ll cnt[100005]; //dem so duong den i

int main(){
	ll dinh, canh;
	cin>>dinh>>canh;
	while(canh--){
		ll x, y, w;
		cin>>x>>y>>w;
		ke[x].push_back({y, w});
		ke[y].push_back({x, w});
	}
	//Buoc 1: Khoi tao
	for(ll i=1;i<=dinh;i++) d[i] = LONG_LONG_MAX;
	d[1] = 0, cnt[1] = 1;
	
	//({d[v], v})
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
	pq.push({0,1});

	//Buoc 2: Lap
	while(!pq.empty()){
		//Moi buoc, lay ra dinh chua xet ma thoa man d[] min
		pair<ll,ll>p = pq.top();
		ll u1 = p.second;
		pq.pop();
		for(auto i: ke[u1]){
			ll u2 = i.first;
			ll w = i.second;
			if(d[u2]==d[u1] + w) cnt[u2] += cnt[u1];
			if(d[u2] > d[u1] + w){
				cnt[u2] = cnt[u1];
				d[u2] = d[u1] + w;
				pq.push({d[u2], u2});
			}
		}
	}
	cout<<d[dinh]<<" "<<cnt[dinh];
}
