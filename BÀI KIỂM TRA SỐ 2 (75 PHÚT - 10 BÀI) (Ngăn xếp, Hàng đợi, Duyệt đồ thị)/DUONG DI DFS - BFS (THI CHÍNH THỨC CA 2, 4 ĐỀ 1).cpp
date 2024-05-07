#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};
int truoc[1005]={};

void DFS(int x){
	visited[x] = 1;
	for(int i: ke[x]){
		if(visited[i]==0){
			DFS(i);
			truoc[i]=x;
		}
	}
}

void BFS(int x){
	queue<int>q;
	q.push(x);
	visited[x]=1;
	while(q.size()!=0){
		int p = q.front();
		q.pop();
		for(int i: ke[p]){
			if(visited[i]==0){
				q.push(i);
				truoc[i] = p;
				visited[i]=1;
			}
		}
	}
}

int main(){
    int dinh, canh;
    cin>>dinh>>canh;
    vector<int>path;
    while(canh--){
        int dau, cuoi;
        cin>>dau>>cuoi;
        ke[dau].push_back(cuoi);
        ke[cuoi].push_back(dau);
    }
    for(int i = 2;i<=dinh;i++){
        memset(visited, 0, sizeof(visited));
        memset(truoc, 0, sizeof(truoc));
        path.clear();
        int x = 1, y = i;
        DFS(x);
        if(!visited[y]){
            cout<<"-1"<<endl;
        } else {
            while(y!=x){
                path.push_back(y);
                y = truoc[y];
            }
            path.push_back(x);
            reverse(path.begin(), path.end());
            for(int x: path) cout<<x<<" ";
            cout<<endl;
        }
        memset(visited, 0, sizeof(visited));
        memset(truoc, 0, sizeof(truoc));
        path.clear();
        x = i, y = 1;
        BFS(x);
        if(!visited[y]){
            cout<<"-1"<<endl;
        } else {
            while(y!=x){
                path.push_back(y);
                y = truoc[y];
            }
            path.push_back(x);
            reverse(path.begin(), path.end());
            for(int x: path) cout<<x<<" ";
            cout<<endl;
        }
    }
}
