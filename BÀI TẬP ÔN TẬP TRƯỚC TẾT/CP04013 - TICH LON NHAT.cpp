#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long max1=max(a[0]*a[1]*a[n-1],a[n-1]*a[n-2]*a[n-3]);
	long long max2=max(a[0]*a[n-1],a[n-1]*a[n-2]);
	cout<<max(max1,max2);
}