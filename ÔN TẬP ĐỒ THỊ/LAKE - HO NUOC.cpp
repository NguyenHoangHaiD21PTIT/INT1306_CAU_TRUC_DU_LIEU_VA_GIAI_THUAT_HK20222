#include<bits/stdc++.h>
using namespace std;

int a[105][105]={};
int visited[105][105]={0};

int cnt = 0;//ans: so phan tu trong TPLT 
int hang, cot, k;

int dx[4]={-1,0,0,1};//do dich chi so hang
int dy[4]={0,-1,1,0};//do dich chi so cot

void DFS(int i, int j){//loang tu hang i cot j
	visited[i][j]=1;
	cnt++;
	for(int k=0;k<4;k++){//duyet cac o ke o (i,j)
		int i1=i+dx[k];
		int j1=j+dy[k];
		//Kiem tra xem o  gia tri 1 ke ay da duoc tham chua va co trong mang hay khong
		if(i1>=0&&i1<=hang-1&&j1>=0&&j1<=cot-1&& a[i1][j1]==1&&visited[i1][j1]==0){
			DFS(i1,j1);
		}
	}
}
int main(){
	cin>>hang>>cot>>k;//k: so o ngap
	while(k--){
		int x, y;
		cin>>x>>y;
		a[x-1][y-1]=1;
	}
	vector<int>ans;
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			if(a[i][j]==1&&visited[i][j]==0){
				DFS(i,j);
				ans.push_back(cnt);
				cnt = 0;
			}	
		}
	}
	cout<<*max_element(ans.begin(),ans.end());
}
