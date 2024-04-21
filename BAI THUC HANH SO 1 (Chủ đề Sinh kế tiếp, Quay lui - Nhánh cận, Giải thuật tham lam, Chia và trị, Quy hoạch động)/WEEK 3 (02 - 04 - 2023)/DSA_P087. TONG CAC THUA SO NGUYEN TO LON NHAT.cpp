#include<bits/stdc++.h>
using namespace std;

int prime[100005];

void sang(){
	for(int i =0;i<=100005;i++) prime[i]=1;
	prime[0]=0; prime[1]=0;
	for(int i=0;i<=sqrt(100005);i++){
		if(prime[i]==1){
			for(int j=i*i;j<100005;j+=i) prime[j]=0;
		}
	}
}

int uocnt(int n){
	int x;
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0){
			if(prime[n/i]==1) return n/i;
			else if (prime[i]==1) x=i;
		}
	}
	return x;
}

int main(){
	int t;
	cin>>t;
	sang();
	while(t--){
		int l, r;
		cin>>l>>r;
		long long ans = 0;
		for(int i=l;i<=r;i++) ans+=uocnt(i);
		cout<<ans<<endl;
	}
}
