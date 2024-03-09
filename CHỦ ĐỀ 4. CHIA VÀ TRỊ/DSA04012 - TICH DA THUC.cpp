#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int m, n;
		cin>>m>>n;
		int a[m], b[n]; //A la da thuc bac m-1 nen co m phan tu, b la bac n-1
		int x = m-1+n-1+1; //so ptu da thuc tich khi thu gon
		int c[x]={};
		for(int i=0;i<m;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				c[i+j]+=a[i]*b[j];
			}
		}
		for(int i=0;i<x;i++) cout<<c[i]<<" ";
		cout<<endl;
	}
}