#include<bits/stdc++.h>
using namespace std;

//THUAT TOAN KADANE
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i =0;i<n;i++){
			cin>>a[i];
		}
		int ans = -1e9;//tongmax
		int tong = 0;
		for(int i=0;i<n;i++){
			tong+=a[i];
			ans=max(ans,tong);
			if(tong<=0) tong=0;
		}
		cout<<ans<<endl;
	}
}