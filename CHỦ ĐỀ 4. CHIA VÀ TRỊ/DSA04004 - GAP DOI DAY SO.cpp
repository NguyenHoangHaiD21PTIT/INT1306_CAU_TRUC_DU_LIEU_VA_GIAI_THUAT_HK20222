#include<bits/stdc++.h>
using namespace std;

long long find(long long n, long long k){
	if(k==1) return 1;
	long long res = pow(2,n-1);
	if(k==res){
		return n;
	} else if (k< res){
		return find(n-1,k);
	} else {
		return find(n-1,k-res);
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n, k;
		cin>>n>>k;
		cout<<find(n,k)<<endl;
	}
}