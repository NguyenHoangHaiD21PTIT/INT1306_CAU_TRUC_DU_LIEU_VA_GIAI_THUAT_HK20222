#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1]={0};
		for(int i=1;i<=n;i++) cin>>a[i];
		//f[x] la tong max day con khong ke nhau ket thuc tai chi so x
		/*Mot day con khong ke nhau ket thuc tai chi so x co the duoc hình thanh bang 2 cach:
		Cach 1: Lay day khong ke ket thuc tai x - 1
		Cach 2: Lay day khong ke ket thuc tai vi tri x - 2 va them a[i] */
		int f[n+1]={0};
		f[1] = a[1];
		for(int i=2;i<=n;i++) f[i] = max (f[i-1], f[i-2] + a[i]);
		cout<<f[n]<<endl;
	}
}