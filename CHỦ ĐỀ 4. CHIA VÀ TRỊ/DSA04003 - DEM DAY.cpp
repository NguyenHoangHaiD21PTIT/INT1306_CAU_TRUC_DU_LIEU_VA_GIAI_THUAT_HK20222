#include<bits/stdc++.h>
using namespace std;

const int MOD = 123456789;

long long binpow(long long a, long long b){
	long long ans = 1;
	while(b>0){
		if(b%2==1){
			ans*=a;
			ans%=MOD;
		}
		a=(a*a)%MOD;
		b/=2;
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		cout<<binpow(2,n-1)<<endl;
	}
}