#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};
int truoc[1005];

void DFS(int x){
	visited[x]=1;
	for(int i: ke[x]){
		if(visited[i]==0){
			truoc[i]=x;//ghi nhan tu x moi loang ra duoc i
			DFS(i);
		}
	}
}
int main(){
	int dinh, canh, x, y;//x: dau, y: cuoi
	cin>>dinh>>canh>>x>>y;
	while(canh--){
		int dau, cuoi;
		cin>>dau>>cuoi;
		ke[dau].push_back(cuoi);
	}
	for(int i=1;i<=dinh;i++){
		sort(ke[i].begin(), ke[i].end());
	}
	//Thuc hien kiem tra duong di
	memset(visited,0,sizeof(visited));
	DFS(x);
	if(visited[y]==0){
		cout<<-1;
	} else { //Truy vet duong di
		vector<int>path;
		while(y!=x){//cuoi chua lui ve dau
			path.push_back(y);
			y=truoc[y];//lui vi tri cuoi
		}
		path.push_back(x);
		for(int i=path.size()-1;i>=0;i--){
			cout<<path[i]<<" ";
		}
	}
}