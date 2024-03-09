#include<bits/stdc++.h>
using namespace std;

long long f[60];

void gen(){
	f[0] = 1;
	f[1] = 1;
	f[2] = 2;
	for(long long i = 3;i<=52;i++) f[i] = f[i-1] + f[i-2] + f[i-3];
}

int main(){
	gen();
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		cout<<f[n]<<endl;
	}
}