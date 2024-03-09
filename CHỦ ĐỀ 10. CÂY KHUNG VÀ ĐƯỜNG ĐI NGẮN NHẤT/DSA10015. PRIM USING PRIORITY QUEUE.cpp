#include<bits/stdc++.h>
using namespace std;

//PRIM
int used[10005]; //used[i] = 1: i thuoc tap canh cua cay khung
vector<pair<int, int>>v[1005]; //v[i] luu tap dinh ke cua dinh i kem theo trong so

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(used, 0, sizeof(used));
		int dinh, canh;
		cin>>dinh>>canh;
		for(int i=1;i<=dinh;i++) v[i].clear();
		while(canh--){
			int a, b, c;
			cin>>a>>b>>c;
			v[a].push_back({b, c});
			v[b].push_back({a, c});
		}
		//Buoc 1: Khoi tao
		long long d = 0;
		priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>>pq;
		pq.push({0,1});//Trong so phai len truoc
		
		//Buoc 2: Lap
		while(pq.size()>0){
			pair<int,int> p = pq.top();
			pq.pop();
			int x = p.second, y = p.first; //x: dinh, y: trong so
			if(used[x]) continue;
			d+=y;
			used[x] = 1;
			
			//Duyet cac dinh ke
			for(auto i: v[x]){
				int a = i.first, b = i.second;
				if(used[a]==0) pq.push({b,a});
			}
		}
		//Buoc 3: Tra ket qua
		cout<<d<<endl;
	}
}