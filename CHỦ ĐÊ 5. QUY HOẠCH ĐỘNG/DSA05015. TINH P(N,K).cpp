#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		if(k>n){
			cout<<0<<endl;
		} else if (k==0){
			cout<<1<<endl;
		} else {
			long long ans = 1;
			for(int i = n - k + 1; i<=n;i++){
				ans*=i;
				ans%=MOD;
			}
			cout<<ans<<endl;
		}
	}
}