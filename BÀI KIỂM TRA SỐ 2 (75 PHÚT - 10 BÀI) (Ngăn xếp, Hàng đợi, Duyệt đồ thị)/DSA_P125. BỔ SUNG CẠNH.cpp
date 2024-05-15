#include<bits/stdc++.h>
using namespace std;
int n,m, num[100001], parent[100001];
void init(){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		num[i]=1;
	}
}
int Find(int u){
	if(u != parent[u])
		parent[u]=Find(parent[u]);
		return parent[u];
}
void Union(int u, int v){
	int a=Find(u), b = Find(v);
	if(a==b) return;
	if(num[a] < num[b]) swap(a,b);
	parent[b]=a;
	num[a]+=num[b];
}
int main(){
	int u,v,x,i,ans=0;
	cin >> n >> m;
	init();
	while(m--){
		cin >> u >> v;
		Union(u,v);
	}
	int first = Find(1);
	for(int i=1;i<=n;i++){
		x=Find(i);
		if(x != first) ans=max(ans,num[x]);
	}
	cout << ans+num[first] << endl;
}
