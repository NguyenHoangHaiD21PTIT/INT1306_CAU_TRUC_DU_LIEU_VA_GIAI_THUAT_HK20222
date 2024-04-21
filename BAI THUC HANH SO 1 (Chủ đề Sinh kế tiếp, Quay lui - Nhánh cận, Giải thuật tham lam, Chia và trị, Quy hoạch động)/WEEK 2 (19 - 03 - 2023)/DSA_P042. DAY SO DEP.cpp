#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, a[55];
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		int dem = 0;
		for(int i=0;i<n-1;i++){
			int k = 2*min(a[i],a[i+1]);
			while(max(a[i],a[i+1])>k){
				dem++;
				k*=2;
			}
		}
		cout<<dem<<endl;
	}
}
