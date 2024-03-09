#include<bits/stdc++.h>
using namespace std;
int nt(int n){
	if(n<=1){
		return 0;
	} else {
		for(int i=2;i<=sqrt(n);i++){
			if(n%i==0){
				return 0;
			}
		}
		return 1;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long x, y;
		cin>>x>>y;
		double x1 = sqrt(x);
		double x2 = (int)x1;
		double y1 = sqrt(y);
		double y2 = (int) y1;
		int ans = 0;
		if(x1==x2){
			for(int i = x2;i<=y2;i++){
				if(nt(i)==1){
					ans++;
				}
			}
		} else {
			for(int i = x2+1;i<=y2;i++){
				if(nt(i)==1){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}