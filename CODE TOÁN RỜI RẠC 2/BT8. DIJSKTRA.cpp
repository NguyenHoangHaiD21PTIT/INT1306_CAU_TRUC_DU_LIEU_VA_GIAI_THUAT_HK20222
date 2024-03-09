#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

int a[15][15], n, v, par[15];//a: ma tran trong so, v: dinh de cho, par[i] la dinh lam giam d[i] xuong

void DIJSKTRA(int s){
	int visited[15], d[15]; //d[u] la khoang cach tu dinh u toi dinh nguon
	
	//Khoi tao cho thuat toan Dijsktra
	for(int i=1;i<=n;i++) visited[i] = 0, d[i] = INT_MAX;
	d[s] = 0;
	
	//Hang doi uu tien luu dinh ke va trong so
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,s});
	
	//Buoc lap
	while(!pq.empty()){
		//Moi mot buoc, ta lay ra dinh co d[] min ma chua xet
		pair<int,int>p = pq.top();
		pq.pop();
		int cur = p.second;
		if(visited[cur]==1) continue;
		visited[cur] = 1;
		//Xet cac dinh ke voi dinh duoc chon, neu cap nhat duoc d thi cap nhat va cho vao pq
		for(int i = 1;i<=n;i++){
			if(a[cur][i]){
				if(d[i] > d[cur] + a[cur][i]){
					d[i] = d[cur] + a[cur][i];
					pq.push({d[i], i});
					par[i] = cur;
				}
			}
		}
	}
	
	//Tra ket qua
	for(int i = 1;i<=n;i++){
		if(d[i] == INT_MAX){
			cout<<"K/c "<<s<<" -> "<<i<<" = INF; "<<endl;
			continue;
		}  
		if(s==i) cout<<"K/c "<<s<<" -> "<<i<<" = 0; "<<s<<" <- "<<i<<endl;
		else{
			cout<<"K/c "<<s<<" -> "<<i<<" = "<<d[i]<<"; ";
			vector<int>path;
			int tmp = s, tmp2 = i;//Can tim duong tu s den i
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

int main(){
	cin>>n>>v;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++) cin>>a[i][j];
	}
	DIJSKTRA(v);
}
/*
13
2
0   2   8   0   0   0   0   0   0   0   0   0   0
0   0   2   0   0   0   9   0   0   0   0   0   0
0   0   0   6   0   8   1   0   0   0   0   0   0
7   0   0   0   0   0   0   0   0   0   0   0   0
0   0   1   7   0   0   0   0   0   0   0   0   0
0   0   0   0   1   0   0   9   8   0   0   0   0
0   0   0   0   0   2   0   2   0   0   0   0   0
0   0   0   0   0   0   0   0   9   0   0   2   0
0   0   0   0   0   0   0   0   0   6   0   9   8
0   0   0   0   7   6   0   0   0   0   0   0   0
0   0   0   0   0   0   0   0   6   7   0   0   0
0   0   0   0   0   0   0   0   0   0   0   0   2
0   0   0   0   0   0   0   0   0   0   7   0   0
0   0   0   0   0   0   0   0   0   0   0   0   2
0   0   0   0   0   0   0   0   0   0   7   0   0 */
/*
10 9
0 7 2 0 0 0 0 0 0 0
7 0 0 3 6 0 0 0 0 0
2 0 0 10 0 5 0 0 0 0
0 3 10 0 2 4 5 0 0 0
0 6 0 2 0 0 3 6 0 0
0 0 5 4 0 0 7 0 3 0
0 0 0 5 3 7 0 4 2 0
0 0 0 0 6 0 4 0 0 5
0 0 0 0 0 3 2 0 0 8
0 0 0 0 0 0 0 5 8 0 */