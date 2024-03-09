#include<bits/stdc++.h>
using namespace std;
int hang, cot, a[105][105];

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

void DFS(int i, int j){
	a[i][j]=0;
	for(int k=0;k<8;k++){
		int i1=i+dx[k];
		int j1=j+dy[k];
		if(i1>=0&&i1<=hang-1&&j1>=0&&j1<=cot-1&&a[i1][j1]==1) DFS(i1,j1);
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>hang>>cot;
		for(int i=0;i<hang;i++){
			for(int j=0;j<cot;j++) cin>>a[i][j];
		}
		int dem=0;
		for(int i=0;i<hang;i++){
			for(int j=0;j<cot;j++){
				if(a[i][j]==1){
					dem++;
					DFS(i,j);
				}
			}
		}
		cout<<dem<<endl;
	}
}