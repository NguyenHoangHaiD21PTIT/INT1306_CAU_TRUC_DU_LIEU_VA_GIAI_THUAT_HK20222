#include<bits/stdc++.h>
using namespace std;

int n, x, a[100];

bool cmp(int b1, int b2){
	return abs(b1-x)<abs(b2-x);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>x;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		stable_sort(a,a+n,cmp);
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}