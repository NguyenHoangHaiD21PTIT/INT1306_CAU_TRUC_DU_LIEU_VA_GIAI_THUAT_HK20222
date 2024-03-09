#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int x1 = a[0] * a[1];
	int x2 = a[n-2] * a[n-1];
	int x3 = x2 * a[n-3];
	int x4 = a[0] * a[1] * a[n-1];
	int ans = max(x1,max(x2,max(x3,x4)));
	cout<<ans;
}