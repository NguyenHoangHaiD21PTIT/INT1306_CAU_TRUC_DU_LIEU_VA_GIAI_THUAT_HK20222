#include<bits/stdc++.h>
using namespace std;

struct point{
	double x, y;
};

struct edge{
	int a, b;
	double w;
};

bool cmp(edge a, edge b){
	return a.w<b.w;
}

int par[1005], sz[1005];

int find(int x){
	if(x==par[x]) return x;
	return par[x] = find(par[x]);
}

bool Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return false;
	if(sz[a]<sz[b]) swap(a, b);
	sz[a]+=sz[b];
	par[b] = a;
	return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<point>v1;
		v1.push_back({0.00, 0.00});
		//Nhap toa do
		for(int i = 1;i<=n;i++){
			point p;
			cin>>p.x>>p.y;
			v1.push_back(p);
		}
		for(int i = 1;i<=n;i++){
			par[i] = i;
			sz[i] = 1;
		}
		//Nhap danh sach canh va trong so
		vector<edge>v2;
		for(int i = 1;i<=v1.size()-2;i++){
			for(int j = i+1;j<=v1.size()-1;j++){
				double d = (double)sqrt((v1[i].x - v1[j].x)*(v1[i].x - v1[j].x) + (v1[i].y - v1[j].y)*(v1[i].y - v1[j].y));
				v2.push_back({i, j, d});
			}
		}
		//Kruskal
		sort(v2.begin(), v2.end(), cmp);
		double res = 0;int cnt = 0;
		for(auto i: v2){
			if(cnt==n-1) break;
			if(Union(i.a, i.b)){
				res+=i.w;
				cnt++;
			}
		}
		cout<<fixed<<setprecision(6)<<res<<endl;
	}
}