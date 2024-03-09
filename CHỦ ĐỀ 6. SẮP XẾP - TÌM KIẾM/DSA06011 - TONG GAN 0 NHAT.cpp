#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i = 0;i<n;i++){
			cin>>a[i];
		}
		int tongmin = 1e9;
		int ans = 1e9;
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				if(abs(a[i]+a[j])<tongmin){
					tongmin = abs(a[i]+a[j]);
					ans = a[i] + a[j];
				}
			}
		}
		cout<<ans<<endl;
	}
}