#include<bits/stdc++.h>
using namespace std;

char a[1005][1005]; int visited[1005][1005]={};
int hang, cot;

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void DFS(int i, int j){
	visited[i][j] = 1;
	for(int k=0;k<4;k++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1>=0&&i1<=hang-1&&j1>=0&&j1<=cot-1&&a[i1][j1]=='#'&&visited[i1][j1]==0){
			DFS(i1,j1);
		}
	}
}

int main(){
	cin>>hang>>cot;
	for(int i=0;i<hang;i++){
		for(int j = 0;j<cot;j++){
			cin>>a[i][j];
		}
	}
	int ans  = 0;
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			if(a[i][j]=='#'&&visited[i][j]==0){
				ans++;
				DFS(i,j);
			}
		}
	}
	cout<<ans;
}
/*
5 6
.#....
..#...
..#..#
...##.
.#.... */
