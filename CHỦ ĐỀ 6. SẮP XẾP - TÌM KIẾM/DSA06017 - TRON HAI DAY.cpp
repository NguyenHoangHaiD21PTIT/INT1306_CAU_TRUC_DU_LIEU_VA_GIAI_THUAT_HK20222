#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int x, y;
		cin>>x>>y;
		int p = x + y;
		int a[p];
		for(int i=0;i<p;i++){
			cin>>a[i];
		}
		sort(a,a+p);
		for(int i=0;i<p;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}