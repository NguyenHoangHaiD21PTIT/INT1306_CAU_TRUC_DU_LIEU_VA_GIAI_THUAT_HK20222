#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;
long long n;

struct matran{
	long long c[11][11];
};

matran operator *(matran a, matran b){
	matran res;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			res.c[i][j]=0;
			for(int k=0;k<n;k++){
				res.c[i][j] = (res.c[i][j] + a.c[i][k]*b.c[k][j])%MOD;
			}
		}
	}
	return res;
}

matran powmod(matran a, long long n){
	if(n==1) return a;
	if(n%2==1) return powmod(a,n-1) *a;
	matran tmp = powmod(a,n/2);
	return tmp*tmp;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		long long k;
		cin>>k;
		matran x;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) cin>>x.c[i][j];
		}
		x = powmod(x,k);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)  cout<<x.c[i][j]<<" ";
			cout<<endl;
		}
	}
}