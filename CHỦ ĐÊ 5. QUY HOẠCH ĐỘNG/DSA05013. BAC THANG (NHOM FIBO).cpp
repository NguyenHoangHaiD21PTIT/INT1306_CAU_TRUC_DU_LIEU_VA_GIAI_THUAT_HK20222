#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		long long f[n+1]={0};
		f[0] = 1;
		for(int i=1;i<=n;i++){
			int x = min(i,k);
			for(int j=1;j<=x;j++){
				f[i]+=f[i-j];
				f[i]%=MOD;
			}
		}
		cout<<f[n]<<endl;
	}
}