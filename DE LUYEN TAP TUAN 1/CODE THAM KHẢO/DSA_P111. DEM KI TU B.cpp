#include<bits/stdc++.h>
using namespace std;

long long f[50], cnt[50];

void gen(){ //cnt[i]: Số ký tự B trong xâu thứ i, f[i]: Độ dài xâu thứ i
	f[0]=1;
	f[1]=1;
	cnt[0]=0;
	cnt[1]=1;
	for(int i=2;i<=50;i++){
		f[i] = f[i-1]+f[i-2];
		cnt[i]=cnt[i-1] + cnt[i-2];
	}
}

long long count(long long n, long long k){
	if(n==0) return 0;
	if(n==1) return 1;
	if(k<=f[n-1]) return count(n-1,k);
	else return cnt[n-1] + count(n-2,k-f[n-1]);
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
