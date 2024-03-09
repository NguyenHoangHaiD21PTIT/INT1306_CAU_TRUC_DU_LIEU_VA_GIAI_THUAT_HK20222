#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];//luu danh sach ke
int visited[1005]={};
int truoc[1005]={};

void DFS(int u){
	visited[u]=1;
	for(int i: ke[u]){//xet cac dinh ke voi u
		if(visited[i]==0){
			truoc[i]=u;
			DFS(i);
		}
	}
}
int main(){
	//1. Nhap va chuyen ds canh --> ds ke
	int dinh, canh, x, y;//x: dau, y: cuoi
	cin>>dinh>>canh>>x>>y;
	while(canh--){
		int dau, cuoi;
		cin>>dau>>cuoi;
		ke[dau].push_back(cuoi);
		ke[cuoi].push_back(dau);
	}
	for(int i=1;i<=dinh;i++){
		sort(ke[i].begin(), ke[i].end());
	}
	memset(visited,0,sizeof(visited));
	//2. Kiem tra duong di
	DFS(x);//loang tu dinh x
	if(visited[y]==0){//khong loang duoc den y --> k co duong di
		cout<<-1;
	} else {//truy van duong di
		vector<int>path;
		while(y!=x){//cuoi chua lui ve dau
			path.push_back(y);
			y=truoc[y];//lui phan tu cuoi
		}
		path.push_back(x);
		for(int i=path.size()-1;i>=0;i--){
			cout<<path[i]<<" ";
		}
	}
}