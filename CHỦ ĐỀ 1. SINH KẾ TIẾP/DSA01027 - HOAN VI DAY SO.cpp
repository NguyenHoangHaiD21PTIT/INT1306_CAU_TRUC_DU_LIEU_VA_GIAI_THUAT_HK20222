#include<bits/stdc++.h>
using namespace std;

int n, a[100];

void kt(){
	sort(a,a+n);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	kt();
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	while(next_permutation(a,a+n)!=false){
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}