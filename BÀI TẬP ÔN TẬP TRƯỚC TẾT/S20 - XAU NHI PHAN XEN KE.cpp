#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, a[1050]={};
	cin>>n;
	for(int i=1;i<n;i++){
		a[i]=1-a[i-1];
	}
	for(int j=0;j<=1;j++){
		a[0]=j;
		for(int i=1;i<n;i++){
			a[i]=1-a[i-1];
		}
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}
