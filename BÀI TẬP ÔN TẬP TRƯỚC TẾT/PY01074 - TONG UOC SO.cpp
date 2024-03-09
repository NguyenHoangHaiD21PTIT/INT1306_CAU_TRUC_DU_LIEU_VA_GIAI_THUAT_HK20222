#include<bits/stdc++.h>
using namespace std;
int main(){
	long long t;
	cin>>t;
	long long T=0;
	while(t--){
		long long n;
		cin>>n;
		long long tong = 0;
		for(long long i= 2;i<=sqrt(n);i++){
			if(n%i==0){
				long long dem = 0;
				while(n%i==0){
					dem++;
					n/=i;
				}
				tong+=i*dem;
			}
		}
		if(n!=1){
			tong+=n;
		}
		T+=tong;
	}
	cout<<T;
}
