#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int f[n+1] = {};
		f[0] = 1;
		//f[i] la so cach leo len bac thu i
		for(int i=1;i<=n;i++){ //f[i] = f[i-1] + f[i-2] + ... + f[i - ?] ?>=i
			int x = min(i,k);
			for(int j=1;j<=x;j++){
				f[i]+=f[i-j];
				f[i]%=MOD;
			}
		}
		cout<<f[n]<<endl;
	}
}