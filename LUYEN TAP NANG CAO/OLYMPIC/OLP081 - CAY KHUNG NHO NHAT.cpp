#include<bits/stdc++.h>
using namespace std;

int par[200005], sze[200005];

struct edge{
	int x, y, w;
};

bool cmp(edge a, edge b){
	return a.w<b.w;
}

int find(int x){
	if(x==par[x]) return x;
	return par[x] = find(par[x]);
}

bool Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return false;
	if(sze[a]<sze[b]) swap(a,b);
	par[b] = a;
	sze[a]+=sze[b];
	return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int dinh, canh;
		cin>>dinh>>canh;
		//Make_set
		for(int i=1;i<=dinh;i++){
			par[i] = i;
			sze[i] = 1;
		}
		vector<edge>v;
		while(canh--){
			int a, b, c;
			cin>>a>>b>>c;
			v.push_back({a, b, c});
		}
		stable_sort(v.begin(), v.end(), cmp);
		long long d = 0;
		vector<pair<int, int>>mst;
		for(auto i: v){
			if(mst.size()==dinh-1) break;
			if(Union(i.x, i.y)){
				mst.push_back({i.x, i.y});
				d+=i.w;
			}
		}
		cout<<d<<endl;
	}
}