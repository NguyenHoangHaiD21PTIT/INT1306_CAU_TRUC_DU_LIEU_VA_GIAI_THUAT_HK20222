#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, q;
	cin>>n>>m>>q;
	int d[n+5][n+5];
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++) d[i][j] = 1e9;
		d[i][i] = 0; 
	}
	while(m--){
		int x, y, w;
		cin>>x>>y>>w;
		d[x][y] = w;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
		}
	}
    while (q--) {
        int u, v; 
		cin >> u >> v;
        if(d[u][v]==1e9) cout<<-1<<endl;
        else cout<<d[u][v]<<endl;
    }
}
