#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long a[n];
		for(long long i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		long long ans = 0;
		for(long long i=0;i<n;i++){
			ans+=a[i]*i;
			ans%=MOD;
		}
		cout<<ans<<endl;
	}
}