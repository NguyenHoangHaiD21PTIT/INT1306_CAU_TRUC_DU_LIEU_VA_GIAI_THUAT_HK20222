#include<bits/stdc++.h>
using namespace std;

vector<int>ke[10005];
int visited[10005], cnt[10005], q[10005];

void DFS(int x){
	visited[x] = 1;
	cnt[x]++;
	for(int i: ke[x]){
		if(visited[i]==0) DFS(i);
	}
}

int main(){
	int k, dinh, canh;
	cin>>k>>dinh>>canh;
	//Nhung o co nguoi dung
	for(int i=0;i<k;i++) cin>>q[i];
	while(canh--){
		int dau, cuoi;
		cin>>dau>>cuoi;
		ke[dau].push_back(cuoi);
	}
	for(int i=0;i<k;i++){
		memset(visited,0,sizeof(visited));
		DFS(q[i]);
	}
	int dem = 0;
	for(int i=1;i<=dinh;i++){
		if(cnt[i]==k) dem++;
	}
	cout<<dem;
}