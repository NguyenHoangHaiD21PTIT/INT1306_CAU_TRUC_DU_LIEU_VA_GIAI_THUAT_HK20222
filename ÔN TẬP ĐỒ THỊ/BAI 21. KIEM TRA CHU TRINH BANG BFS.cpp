#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};
int truoc[1005]={};

int BFS(int u){
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
			} else if (i !=truoc[x]) {
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int dinh, canh;
	cin>>dinh>>canh;
	while(canh--){
		int dau, cuoi;
		cin>>dau>>cuoi;
		ke[dau].push_back(cuoi);
		ke[cuoi].push_back(dau);
	}
	for(int i=1;i<=dinh;i++){
		sort(ke[i].begin(),ke[i].end());
	}
	int check = 0;
	for(int i=1;i<=dinh;i++){
		if(visited[i]==0){
			if(BFS(i)==1){
				check=1;
				break;
			}
		}
	}
	cout<<check;
}