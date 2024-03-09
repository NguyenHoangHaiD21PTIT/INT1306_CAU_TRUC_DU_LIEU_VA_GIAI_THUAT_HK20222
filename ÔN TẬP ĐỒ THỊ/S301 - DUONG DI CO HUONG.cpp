#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];//luu danh sach ke
int visited[1005]={};
int truoc[1005]={};

void BFS(int u){
    queue<int>q;
    q.push(u);
    visited[u]=1;
    while(q.size()!=0){
        int x = q.front();
        q.pop();
        for(int i: ke[x]){
            if(visited[i]==0){
                q.push(i);
                visited[i]=1;
                truoc[i]=x;
            }
        }
    }
}
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(truoc,0,sizeof(truoc));
		memset(visited,0,sizeof(visited));
		//1. Nhap va chuyen ds canh --> ds ke
		int dinh, canh, x, y;//x: dau, y: cuoi
		cin>>dinh>>canh>>x>>y;
		for(int i=1;i<=dinh;i++){
			ke[i].clear();
		}
		while(canh--){
			int dau, cuoi;
			cin>>dau>>cuoi;
			ke[dau].push_back(cuoi);
		}
		for(int i=1;i<=dinh;i++){
			sort(ke[i].begin(), ke[i].end());
		}
		memset(visited,0,sizeof(visited));
		//2. Kiem tra duong di
		BFS(x);//loang tu dinh x
		if(visited[y]==0){//khong loang duoc den y --> k co duong di
			cout<<-1;
		} else {//truy van duong di
			vector<int>path;
			while(y!=x){//cuoi chua lui ve dau
				path.push_back(y);
				y=truoc[y];//lui phan tu cuoi
			}
			path.push_back(x);
			for(int i=path.size()-1;i>=1;i--){
				cout<<path[i]<<" -> ";
			}
			cout<<path[0];
		}
	cout<<endl;
	}
}
/*
6 9 1 6
1 2  
2 5
3 1
3 2
3 5
4 3
5 4
5 6
6 4  
--> DS: 1256
5 10 2 3
5 1
4 5
3 5
4 3
2 1
3 2
5 3
2 5
1 3
5 2 --> DS: 213 */
