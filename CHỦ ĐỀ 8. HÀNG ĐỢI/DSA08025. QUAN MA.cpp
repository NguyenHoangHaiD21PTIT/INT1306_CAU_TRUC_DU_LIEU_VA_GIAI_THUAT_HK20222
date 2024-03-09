#include<bits/stdc++.h>
using namespace std;

int s, t, u, v;
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int visited[10][10], d[10][10];//d la so buoc it nhat di chuyen den o do

int BFS(){
	//Buoc 1: Khoi tao
	memset(visited, 0, sizeof(visited));
	memset(d, 0, sizeof(d));
	queue<pair<int,int>>q;
	q.push({s, t});
	visited[s][t] = 1;
	//Buoc 2: Lap
	while(!q.empty()){
		pair<int,int>p = q.front();
		q.pop();
		int i = p.first, j = p.second;
		if(i==u&&j==v) return d[u][v];
		for(int k = 0;k<8;k++){
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			if(i1>=0&&i1<=7&&j1>=0&&j1<=7&&!visited[i1][j1]){
				q.push({i1, j1});
				visited[i1][j1] = 1;
				d[i1][j1] = d[i][j] + 1;
			}
		}
	}
	return -1;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		cin.ignore();
		string s1, s2;
		cin>>s1>>s2;
		t = s1[0] - 'a';
		s = s1[1] - '0' - 1;
		v = s2[0] - 'a';
		u = s2[1] - '0' - 1;
		cout<<BFS()<<endl;
	}
}
/*
8
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6 */