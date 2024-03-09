#include<bits/stdc++.h>
using namespace std;

int C[1005][1005];//C[x][y]: To hop chap y cua x
const int MOD = 1e9+7;

void tohop(){
	//1. Chi so duoi i
	for(int i=0;i<=1000;i++){
		//2. Chi so tren j
		for(int j=0;j<=i;j++){
			if(j==0||j==i){
				C[i][j]=1;
			} else {
				C[i][j] = C[i-1][j] + C[i-1][j-1];
				C[i][j]%=MOD;
			}
		}
	}
}

int main(){
	tohop();
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		cout<<C[n][k]<<endl;
	}
}
