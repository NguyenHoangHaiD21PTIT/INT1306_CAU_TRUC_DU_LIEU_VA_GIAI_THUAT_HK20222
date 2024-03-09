#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int color[1005]={};

/* Thuat toan DFS: 1 dinh cua do thi se co 1 trong 3 mau sau
- 0: Trang: Dinh chua duoc tham
- 1: Xam: Dinh dang tham nhung chua xong
- 2: Den: Dinh da tham xong */
int DFS(int u){
	color[u]=1;//vao tham dinh u
	for(int i: ke[u]){
		if(color[i]==0){
			if(DFS(i)==1){
				return 1;
			}
		} else if (color[i]==1){
			return 1;//ton tai canh nguoc
		}
	}
	color[u] = 2;
	return 0;
}
int main(){
	int dinh, canh;
	cin>>dinh>>canh;
	while(canh--){
		int dau, cuoi;
		cin>>dau>>cuoi;
		ke[dau].push_back(cuoi);
	}
	for(int i=1;i<=dinh;i++){
		sort(ke[i].begin(),ke[i].end());
	}
	int check = 0;
	for(int i=1;i<=dinh;i++){
		if(color[i]==0){
			if(DFS(i)==1){
				check=1;
				break;
			}
		}
	}
	cout<<check;
}