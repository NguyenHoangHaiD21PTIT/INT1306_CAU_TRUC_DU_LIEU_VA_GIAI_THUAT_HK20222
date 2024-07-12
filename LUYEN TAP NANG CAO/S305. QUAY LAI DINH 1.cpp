#include<bits/stdc++.h>
using namespace std;

int visited[25];
vector<int>ke[25];
int par[25];
set<int>s;

void BFS(int x){
    queue<int>q;
    q.push(x);
    visited[x] = 1;
    while(q.size()){
        int p = q.front();
		q.pop();
		for(int i: ke[p]){
			if(visited[i]==0){
				q.push(i);
				par[i] = p;
				visited[i]=1;
			}
		}
    }
}

void pathBFS(int x, int y){
    memset(visited, 0, sizeof(visited));
    memset(par, 0, sizeof(par));
    BFS(x);
    while(y!=x){
        s.insert(y);
        y = par[y];
    }
    s.insert(x);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        s.clear();
        int v, e;
        cin>>v>>e;
        for(int i = 1;i<=v;i++) ke[i].clear();
        while(e--){
            int x, y;
            cin>>x>>y;
            ke[x].push_back(y);
        }
        int a = 1, b = 2;
        pathBFS(a, b);
        pathBFS(b, a);
        cout<<s.size()<<endl;
    }
}