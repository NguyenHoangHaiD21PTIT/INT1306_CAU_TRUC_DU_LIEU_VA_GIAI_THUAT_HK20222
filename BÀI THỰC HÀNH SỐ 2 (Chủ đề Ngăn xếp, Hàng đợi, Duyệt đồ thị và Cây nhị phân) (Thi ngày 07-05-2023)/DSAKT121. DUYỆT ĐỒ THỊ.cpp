#include<bits/stdc++.h>
using namespace std;

vector <int> ke[1005];
int visited[1005] = {};

void DFS(int x){
	visited[x] = 1;
	cout << x << " ";
	for(int i: ke[x]){
		if(!visited[i]) DFS(i);
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		memset(visited, 0, sizeof(visited));
		int dinh, canh, v;
		cin >> dinh >> canh >> v;
		for(int i = 1; i <= dinh; i++) ke[i].clear();
		while(canh--){
			int dau, cuoi;
			cin >> dau >> cuoi;
			ke[dau].push_back(cuoi);
			ke[cuoi].push_back(dau);
		}
		cout << "DFS(" << v << ") = ";
		DFS(v);
		cout << endl;
	}
}