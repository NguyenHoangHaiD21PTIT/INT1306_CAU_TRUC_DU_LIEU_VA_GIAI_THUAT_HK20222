#include<bits/stdc++.h>
using namespace std;

int a[1005][1005]; //ma tran ke de cho
int n, visited[1005]; //so dinh, mang visited danh dau la dinh do da tham
int par[1005];//par[i] la dinh loang ra i

void BFS(int u){
    queue<int>q;
    q.push(u);
    visited[u] = 1;
    while(q.size()!=0){
        int p = q.front();
        q.pop();
        for(int i = 1;i<=n;i++){ 
        	if(visited[i]==0&&a[p][i]){ //Xet cac dinh ke voi dinh p ma chua xet
                q.push(i);
                visited[i] = 1;
                par[i] = p;
            }
        }
    }
}

void T_BFS(int a[][1005], int v){
	BFS(v);//Xay dung cay khung tu dinh v
	//Dem so dinh duoc tham
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		if(visited[i]) cnt++;
	}
	if(cnt==n){
		cout<<"BFS tree"<<endl;
		for(int i = 1;i<=n;i++){
			if(par[i]) cout<<par[i]<<" "<<i<<endl;
		}
	} else {
		cout<<"Do thi khong lien thong";
	}
}

int main(){
	cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    int v;
    cin>>v;
    T_BFS(a, v);
}