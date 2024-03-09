#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, m; //n dinh, m canh
		cin>>n>>m;
		int d[n+5][n+5];
		//Goi d[i][j] la khoang cach be nhat giua i va j
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++) d[i][j] = 1e9;
			d[i][i] = 0; 
		}
		while(m--){
			int x, y;
			cin>>x>>y;
			d[x][y] = 1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
		int cnt = 0; double dis = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][j]!=1e9&&i!=j){
					cnt++;
					dis+=d[i][j];
				}
			}
		}
		if(cnt==0) cout<<0<<endl;
		else cout<<fixed<<setprecision(2)<<(double)dis/(double)cnt<<endl;
	}
}
