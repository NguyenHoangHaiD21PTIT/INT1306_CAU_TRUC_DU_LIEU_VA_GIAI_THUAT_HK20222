#include<bits/stdc++.h>
using namespace std;

long long f[100010];

void gen(){
	f[1] = 0; f[2] = 1; f[3] = 1;
	for(int i=4;i<=100001;i++){
		if(i%2==0){
			if(i%3==0){
				f[i] = min(f[i-1], min(f[i/2],f[i/3])) + 1;
			} else {
				f[i] = min(f[i-1], f[i/2]) + 1;
			}
		} else if (i%3==0){
			f[i] = min(f[i-1], f[i/3]) + 1;
		} else {
			f[i] = f[i-1] + 1;
		}
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