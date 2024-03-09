#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
long long powdu(long long a, long long b){
	long long res=1;
	while(b){
		if(b%2==1){
			res=(res*a)%MOD;
		}
		a=(a*a)%MOD;
		b/=2;
	}
	return res;
}
int main(){
	while(1){
		long long a, b;
		cin>>a>>b;
		if(a==0&&b==0) break;
		cout<<powdu(a,b)<<endl;
	}
}