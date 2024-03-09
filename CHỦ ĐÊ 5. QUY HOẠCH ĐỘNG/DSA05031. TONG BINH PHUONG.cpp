#include<bits/stdc++.h>
using namespace std;

int f[10005];

void gen(){
	f[1] = 1; f[2] = 2; f[3] = 3;
	for(int i=4;i<=10003;i++){
		f[i] = i;
		for(int j = 1;j<=sqrt(i);j++) f[i] = min(f[i], f[i-j*j] + 1);
	}
}

int main(){
	gen();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<f[n]<<endl;
	}
}