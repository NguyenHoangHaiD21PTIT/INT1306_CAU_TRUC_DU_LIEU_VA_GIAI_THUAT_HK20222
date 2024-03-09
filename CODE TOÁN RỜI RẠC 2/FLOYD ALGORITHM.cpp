#include<bits/stdc++.h>
using namespace std;

int ketiep[15][15], a[15][15], d[15][15];

void timduong(int u, int v){
	if(u==v) cout<<"K/c "<<u<<" --> "<<v<<" = 0; "<<u<<endl; //Duong di den chinh no
	else{
		if(ketiep[u][v]==-1) cout<<"K/c "<<u<<" --> "<<v<<" = INF; "<<endl; //Khong co duong di
		else{
			cout<<"K/c "<<u<<" --> "<<v<<" = "<<d[u][v]<<"; ";
			vector<int>path;
			path.push_back(u); //duong di bat dau tu u
			while(u!=v){
				u = ketiep[u][v];
				path.push_back(u);
			}
			int x = path.size();
			for(int i = 0;i<x-1;i++) cout<<path[i]<<" --> ";
			cout<<path[x-1]<<endl;
		}
	}
}

int main(){
	int n;
	cin>>n;

	//Buoc 1: Khoi tao
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) d[i][j] = 1e9;
		d[i][i] = 0;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]){
				ketiep[i][j] = j;
				d[i][j] = a[i][j];
			} else {
				ketiep[i][j] = -1;
			}
		}
	}
	
	//Buoc 2: Cap nhat
	for(int k=1;k<=n;k++){ //k la dinh trung gian
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][j] > d[i][k] + d[k][j] &&d[i][k] !=1e9 && d[k][j]!=1e9){
					d[i][j] = d[i][k] + d[k][j];
					ketiep[i][j] = ketiep[i][k];
				}
			}
		}
	}
	
	//Buoc 3: Tra lai ket qua
	for(int i = 1;i<=n;i++){
		for(int j=1;j<=n;j++) timduong(i,j);
		cout<<endl;
	}
}
/*
4
0 0 -2 0
4 0 3 0
0 0 0 2
0 -1 0 0 */