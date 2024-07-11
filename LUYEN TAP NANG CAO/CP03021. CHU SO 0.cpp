#include<bits/stdc++.h>
using namespace std;
long cntlong n){
	if(n==0) return 0;
	long k = 1, tz = 0;
	while(pow(5, k)<=n){
		tz+=n/pow(5, k);
		k++;
	}
	return tz;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long n;
		cin>>n;
		cout<<cnt(n)<<endl;
	}
}
