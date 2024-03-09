#include<bits/stdc++.h>
long long gt(long long n){
	long long ans = 1;
	for(long long i = 1;i<=n;i++){
		ans*=i;
	}
	return ans;
}
using namespace std;
int main(){
	long long n;
	cin>>n;
	long long ans = 0;
	for(long long i = 1;i<=n;i++){
		ans+=gt(i);
	}
	cout<<ans;
}