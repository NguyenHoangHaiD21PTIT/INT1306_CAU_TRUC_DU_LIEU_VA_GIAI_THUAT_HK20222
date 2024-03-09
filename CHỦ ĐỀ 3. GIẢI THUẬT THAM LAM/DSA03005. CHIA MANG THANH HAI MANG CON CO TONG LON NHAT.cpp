#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int a[n];
		int sum = 0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		sort(a,a+n, greater<int>());;
		int x = max(k,n-k);
		int sum1 = 0;
		for(int i=0;i<x;i++) sum1+=a[i];
		int sum2 = sum - sum1;
		cout<<sum1 - sum2<<endl;
	}	
}