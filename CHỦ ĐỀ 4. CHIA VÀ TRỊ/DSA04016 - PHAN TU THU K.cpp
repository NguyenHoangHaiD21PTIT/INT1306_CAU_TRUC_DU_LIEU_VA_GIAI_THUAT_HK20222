#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n, m, k;
		cin>>n>>m>>k;
		int p=n+m;
		int a[p];
		for(int i = 0;i<p;i++){
			cin>>a[i];
		}
		sort(a,a+p);
		cout<<a[k-1]<<endl;
	}
}
