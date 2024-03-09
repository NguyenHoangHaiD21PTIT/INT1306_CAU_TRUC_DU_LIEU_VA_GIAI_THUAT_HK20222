#include<bits/stdc++.h>
using namespace std;

int par[15], a[15][15], d[15];

struct edge{
	int st, en, w;
};

int main(){
	int n, v;
	cin>>n>>v;
	vector<edge>ve;
	for(int i=1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]) ve.push_back({i, j, a[i][j]});
		}
	}

	//Buoc 0: Khoi tao
	for(int i=1;i<=n;i++) d[i] = INT_MAX;
	d[v] = 0;
	
	//Buoc lap: Lap den buoc thu v - 1;
	for(int i = 1;i<=n-1;i++){
		//Moi buoc lap thi xet tung dinh, moi dinh thi xet cac dinh mà co duong di vao dinh do
		//Cap nhat do dai d cho dinh dich
		for(auto it: ve){ //Duyet danh sach canh
			int x = it.st, y = it.en, z = it.w;
			if(d[x]!=INT_MAX&& d[y] > d[x] + z){
				d[y] = d[x] + z;
				par[y] = x;
			}
		}
	}

	for(int i = 1;i<=n;i++){
		if(d[i] == INT_MAX){
			cout<<"K/c "<<v<<" -> "<<i<<" = INF; "<<endl;
			continue;
		}  
		if(v==i) cout<<"K/c "<<v<<" -> "<<i<<" = 0; "<<v<<" <- "<<i<<endl;
		else{
			cout<<"K/c "<<v<<" -> "<<i<<" = "<<d[i]<<"; ";
			vector<int>path;
			int tmp = v, tmp2 = i;//Can tim duong tu s den i
			while(tmp2!=tmp){
				path.push_back(tmp2);
				tmp2 = par[tmp2];
			}
			path.push_back(tmp);
			for(int i = 0;i< path.size() - 1;i++) cout<<path[i]<<" <- ";
			cout<<path[path.size()-1]<<endl;	
		}
	}
}
}
/*
5				
1				
0	1	0	0	3
0	0	3	3	8
0	0	0	1	-5
0	0	2	0	0
0	0	0	4	0 */
 