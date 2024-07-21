#include<bits/stdc++.h>
using namespace std;

long long f[50], cnt[50];

void gen(){
	f[0]=1;
	f[1]=1;
	cnt[0]=1;
	cnt[1]=0;
	for(int i=2;i<=50;i++){
		f[i] = f[i-1]+f[i-2];
		cnt[i]=cnt[i-1] + cnt[i-2];
	}
}

long long count(long long n, long long k){
	if(n==0) return 1;
	if(n==1) return 0;
	if(k<=f[n-1]){
		return count(n-1,k);
	} else {
		return cnt[n-1] + count(n-2,k-f[n-1]);
	}
}

int main(){
	gen();
	int t;
	cin>>t;
	while(t--){
		long long n, k;
		cin>>n>>k;
		cout<<count(n,k)<<endl;
	}
}
