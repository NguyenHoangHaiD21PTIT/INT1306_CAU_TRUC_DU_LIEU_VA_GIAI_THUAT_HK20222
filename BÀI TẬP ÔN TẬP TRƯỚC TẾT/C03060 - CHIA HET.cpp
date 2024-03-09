#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin>>n>>k;
	int ans = 0;
	for(int i=1;i<=n;i++){
		int tmp = i;
		if(tmp%2==0){
			int dem = 0;
			while(tmp%2==0){
				dem++;
				tmp/=2;
			}
			ans+=dem;
		}
	}
	if(ans>=k){
		cout<<"Yes";
	} else {
		cout<<"No";
	}
}