#include<bits/stdc++.h>
using namespace std;

int a[105][105]={};
int visited[105][105]={0};
vector<pair<int,int>>tplt[105];//mang cac vector pair, xem o (i,j) thuoc tplt nao

int cnt;//so tplt
int hang, cot, k;

int dx[4]={-1,0,0,1};//do dich chi so hang
int dy[4]={0,-1,1,0};//do dich chi so cot

void DFS(int i, int j){//loang tu hang i cot j
	visited[i][j]=1;
	tplt[cnt].push_back({i,j});
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
/*	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			cout<<a[i][j]<<" ";
		}	
		cout<<endl;
	} */
	memset(visited,0,sizeof(visited));
	//1. Dem so TPLT (cung la de cho bien cnt chay)
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			if(a[i][j]==1&&visited[i][j]==0){
				DFS(i,j);
				cnt++;
			}	
		}
	}
	for(int i=0;i<cnt;i++){
		cout<<"Thanh phan lien thong thu "<<i+1<<" : "<<endl;
		for(auto x: tplt[i]){
			cout<<(x.first+1)<<" "<<(x.second+1)<<endl;
		}
	}  
	int max = -1e9;
	vector<int>sze;
	for(int i=0;i<cnt;i++){
		sze.push_back(tplt[i].size());
	}
	cout<<*max_element(sze.begin(),sze.end());
}