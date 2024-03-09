#include<bits/stdc++.h>
using namespace std;

long long f[100];

void fibo(){
	f[1] = 1;
	f[2] = 1;
	for(long long i=3;i<=92;i++) f[i] = f[i-2] + f[i-1];
}

char find(long long n, long long k){
	if(n==1) return '0';
	if(n==2) return '1';
	if(k<=f[n-2]){
		return find(n-2,k);
	} else {
		return find(n-1,k-f[n-2]);
	}
}

int main(){
	int t;
	cin>>t;
	fibo();
	while(t--){
		long long n, k;
		cin>>n>>k;
		cout<<find(n,k)<<endl;
	}
}