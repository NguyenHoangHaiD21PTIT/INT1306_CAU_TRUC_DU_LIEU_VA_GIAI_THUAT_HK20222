#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005]; int dinh, canh;
int visited[1005];
int a[1005][1005];
int x[1005];

bool Hal(int k){ //Kiem tra xem ton tai duong di Hamilton hay khong
	for(int i: ke[x[k-1]]){
		if(k==dinh+1){
			return true;
		} else if (visited[i]==0){
			x[k] = i;
			visited[i] = 1;
			if(Hal(k+1)) return true;
			visited[i] = 0;
		}
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int check = 0;
		cin>>dinh>>canh;
		for(int i=1;i<=dinh;i++) ke[i].clear();
		while(canh--){
			int dau, cuoi;
			cin>>dau>>cuoi;
			ke[dau].push_back(cuoi);
			ke[cuoi].push_back(dau);
		}
		for(int i=1;i<=dinh;i++){
			memset(visited,0,sizeof(visited));
			memset(x,0,sizeof(x));
			x[1] = i;
			visited[i] = 1;
			if(Hal(2)){
				check = 1;
				break;
			}
		}
		cout<<check<<endl;
	}
}