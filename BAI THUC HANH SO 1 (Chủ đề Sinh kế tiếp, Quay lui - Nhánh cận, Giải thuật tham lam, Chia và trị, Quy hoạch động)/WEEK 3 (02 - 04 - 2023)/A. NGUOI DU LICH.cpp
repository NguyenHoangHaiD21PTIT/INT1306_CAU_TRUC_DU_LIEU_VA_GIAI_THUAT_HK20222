#include<bits/stdc++.h>
using namespace std;

int n, c[100][100], cmin = INT_MAX, x[100], visited[100]={}, ans = INT_MAX;
vector<int>path;

void Try(int i, int sum){
	for(int j=2;j<=n;j++){
		if(visited[j]==0){
			x[i] = j;
			visited[j] = 1;
			sum+=c[x[i-1]][x[i]];
			if(i==n){
				if(ans>sum+c[x[n]][x[1]]){
					path.clear();
					ans = sum + c[x[n]][x[1]];
					for(int k = 2;k<=n;k++) path.push_back(x[k]);
				}
		 	} else if (sum + (n-i+1)*cmin<ans) {
				Try(i+1, sum);
			}
			visited[j] = 0;
			sum-=c[x[i-1]][x[i]];
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]) cmin = min(cmin, c[i][j]);
		}
	}
	x[1] = 1;
	visited[1] = 1;
	Try(2,0);
	cout<<"(1,";
	for(int i=0;i<path.size();i++) cout<<path[i]<<",";
	cout<<"1)"<<endl<<ans;
}