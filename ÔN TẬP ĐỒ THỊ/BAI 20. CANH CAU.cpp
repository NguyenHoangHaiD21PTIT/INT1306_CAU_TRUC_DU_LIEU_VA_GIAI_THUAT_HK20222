#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};
vector<pair<int,int>>v;//ds canh

//3. DFS 1 dinh x bat ky
void DFS(int x){
	visited[x]=1;
	for(int i: ke[x]){
		if(visited[i]==0){
			DFS(i);
		}
	}
}

//4. DFS 1 dinh tru 2 dinh canh bi loai
void DFS2(int u, int x, int y){//DFS tru canh(x,y)
	visited[u]=1;
	//Duyet DS ke dinh u
	for(int i: ke[u]){
		//u va ke u khong duoc phep trung canh bi loai
		if((u==x&&i==y)||(u==y&&i==x)){
			continue;
		}
		if(visited[i]==0){
			DFS2(i,x,y);
		}
	}
}
int main(){
	//1> Chuyen danh sach canh --> ds ke va luu tru ds canh
	int dinh, canh;
	cin>>dinh>>canh;
	while(canh--){
		int dau, cuoi;
		cin>>dau>>cuoi;
		ke[dau].push_back(cuoi);
		ke[cuoi].push_back(dau);
		v.push_back({dau,cuoi});
	}
	for(int i=1;i<=dinh;i++){
		sort(ke[i].begin(), ke[i].end());
	}
	//2. Dem so TPLT
	int dem=0;//so TPLT
	memset(visited,0,sizeof(visited));
	for(int i=1;i<=dinh;i++){
		if(visited[i]==0){
			dem++;
			DFS(i);
		}
	}
//	cout<<dem<<" ";
	//5. Duyet DS canh, de dem so TPLT sau khi loai tung canh (x,y) trong DS canh
	int ans=0;//so canh cau
	for(auto i: v ){
		int x = i.first;
		int y = i.second;
		memset(visited,0,sizeof(visited));
		//Lan luot dem so TPLT sau khi loai (x,y)
		int cnt=0;// So TPLT moi
		for(int j=1;j<=dinh;j++){
			if(visited[j]==0){
				cnt++;
				DFS2(j,x,y);
			}
		}
		if(cnt>dem){ 
			ans++;
		}
	}
	cout<<ans;
}
	