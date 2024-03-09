#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		if(binary_search(a,a+n,x)==true){
			cout<<1<<endl;
		} else {
			cout<<-1<<endl;
		}
	}
}