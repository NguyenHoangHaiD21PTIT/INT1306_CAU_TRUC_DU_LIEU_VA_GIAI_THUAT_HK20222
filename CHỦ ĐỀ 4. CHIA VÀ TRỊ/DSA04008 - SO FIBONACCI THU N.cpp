#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

struct matran{
	long long c[2][2];
};

matran operator *(matran a, matran b){
	matran res;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			res.c[i][j]=0;
			for(int k=0;k<2;k++){
				res.c[i][j]=(res.c[i][j]+a.c[i][k]*b.c[k][j])%MOD;
			}
		}
	}
	return res;
}

matran powmod(matran a, long long n){
	if(n==1) return a;
	if(n%2==1){
		return powmod(a,n-1) *a;
	}
	matran tmp = powmod(a,n/2);
	return tmp*tmp;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		matran x;
		x.c[0][0]=1;
		x.c[0][1]=1;
		x.c[1][0]=3;
		x.c[1][1]=2;
		x = powmod(x,n);
		for(int i = 0;i<2;i++){ 
			for(int j = 0;j<2;j++){
				cout<<x.c[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}