#include<bits/stdc++.h>
using namespace std;

int s, t, u, v;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int visited[10][10], d[10][10];

int BFS(){
	memset(visited, 0, sizeof(visited));
	memset(d, 0, sizeof(d));
	queue<pair<int, int>>q;
	q.push({t, s});
	visited[t][s] = 1;
	while(!q.empty()){
		pair<int, int>p = q.front();
		q.pop();
		int i = p.first, j = p.second;
		if(i == v && j == u) return d[v][u];
		for(int k = 0; k < 8; k++){
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			if(i1 >= 0 && i1 <= 7 && j1 >= 0 && j1 <= 7 && !visited[i1][j1]){
				q.push({i1, j1});
				visited[i1][j1] = 1;
				d[i1][j1] = d[i][j] + 1;
			}
		}
	}
	return -1;
}

int main(){
	cin >> s >> t >> u >> v;
	s--; t--; u--; v--;
	cout << BFS();
}
