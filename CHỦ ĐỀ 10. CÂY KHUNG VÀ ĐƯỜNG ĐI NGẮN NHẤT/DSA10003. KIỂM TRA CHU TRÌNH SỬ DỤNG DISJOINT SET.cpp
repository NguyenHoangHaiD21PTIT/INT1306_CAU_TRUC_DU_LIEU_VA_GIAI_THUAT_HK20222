#include<bits/stdc++.h>
using namespace std;

int par[1005], sze[1005];

int find(int x){
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}

bool Union(int x, int y){
	x = find(x); y = find(y);
	if(x == y) return false;
	if(sze[x] < sze[y]) swap(x, y);
	par[y] = x;
	sze[x] += sze[y];
	return true;	
}

int main(){
	int t; cin >> t;
	while(t--){
		int v, e;
		cin >> v >> e;
		for(int i = 1;i <= v; i++){
			par[i] = i;
			sze[i] = 1;
		}
		vector<pair<int, int>>V;
		while(e--){
			int x, y;
			cin >> x >> y;
			V.push_back({x, y});
		}
		int check = 0; 
		for(auto i: V){
			if(!Union(i.first, i.second)){
				check = 1;
				break;
			}
		}
		if(check) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
