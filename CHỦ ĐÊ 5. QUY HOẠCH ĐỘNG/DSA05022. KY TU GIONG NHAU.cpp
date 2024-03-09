#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, x, y, z;
		cin>>n>>x>>y>>z;
		//f[i] la so thao tac de tao ra i ky tu nhu nhau
		int f[n+1]={0};
		f[1] = x; 
		for(int i=2;i<=n;i++){
			if(i%2==0) f[i] = min(f[i-1] + x, f[i/2] + z);
			else f[i] = min(f[i-1] + x, min(y + f[(i+1)/2] + z,x + f[(i-1)/2] + z ));
		}
		cout<<f[n]<<endl;
	}
}