#include<bits/stdc++.h>
using namespace std;

int par[1005], sz[1005];

int find(int x){
	if(x==par[x]) return x;
	return par[x] = find(par[x]);
}

void Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return;
	if(sz[a]<sz[b]) swap(a,b);
	par[b] = a;
	sz[a]+=sz[b];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		for(int i = 1;i<=n;i++){
			par[i] = i;
			sz[i] = 1;
		}
		for(int i = 0;i<m;i++){
			int x, y;
			cin>>x>>y;
			Union(x, y);
		}
		int q;
		cin>>q;
		while(q--){
			int x, y;
			cin>>x>>y;
			if(find(x)==find(y)) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}