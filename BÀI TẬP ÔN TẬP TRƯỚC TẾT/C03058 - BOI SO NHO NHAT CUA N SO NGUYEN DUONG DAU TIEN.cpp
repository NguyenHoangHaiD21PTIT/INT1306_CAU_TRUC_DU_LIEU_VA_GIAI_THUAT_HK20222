#include<bits/stdc++.h>
using namespace std;
long long lcm(long long a,long long b){
	return a*b/__gcd(a,b);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long ans = 1;
		for(long i=2;i<=n;i++){
			ans=lcm(ans,i);
		}
		cout<<ans<<endl;
	}
}