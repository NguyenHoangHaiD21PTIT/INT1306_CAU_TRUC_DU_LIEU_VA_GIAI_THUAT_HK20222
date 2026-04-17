#include<bits/stdc++.h>
using namespace std;

int par[100005], sze[100005]={};

int find(int x){
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}

bool Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sze[x] < sze[y]) swap(x, y);
    par[y] = x;
    sze[x] += sze[y];
    return true;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			par[i] = i;
			sze[i] = 1;
		}
		while(m--){
			int x, y;
			cin >> x >> y;
			Union(x, y);
		}
		int res = -1;
		for(int i = 1; i <= n; i++) res = max(res, sze[i]);
		cout << res << endl;
	}
}
