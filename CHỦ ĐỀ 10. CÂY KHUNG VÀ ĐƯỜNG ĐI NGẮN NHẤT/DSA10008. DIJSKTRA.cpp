#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>ke[1005];
int d[1005]; //d[i] la khoang cach tu i toi dinh nguon

int main(){
	int t;
	cin>>t;
	while(t--){
		int dinh, canh, v;
		cin>>dinh>>canh>>v;
		for(int i=1;i<=dinh;i++) ke[i].clear();
		while(canh--){
			int x, y, w;
			cin>>x>>y>>w;
			ke[x].push_back({y, w});
			ke[y].push_back({x, w});
		}
		//Buoc 1: Khoi tao
		for(int i=1;i<=dinh;i++) d[i] = INT_MAX;
		d[v] = 0;
		
		//({d[v], v})
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
		pq.push({0,v});
		
		//Buoc 2: Lap
		while(!pq.empty()){
			//Moi buoc, lay ra dinh chua xet ma thoa man d[] min
			pair<int,int>p = pq.top();
			int u1 = p.second;
			pq.pop();
			for(auto i: ke[u1]){
				int u2 = i.first;
				int w = i.second;
				if(d[u2] > d[u1] + w){
					d[u2] = d[u1] + w;
					pq.push({d[u2], u2});
				}
			}
		}
		for(int i=1;i<=dinh;i++) cout<<d[i]<<" ";
		cout<<endl;
		
	}
}