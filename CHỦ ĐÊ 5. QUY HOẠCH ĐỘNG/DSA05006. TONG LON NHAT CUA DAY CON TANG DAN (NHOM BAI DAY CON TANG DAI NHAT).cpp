#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i = 0;i<n;i++) cin>>a[i];
		int f[n]; //f[x] la tong lon nhat cua day con ket thuc tai chi so x
		for(int i = 0;i<n;i++) f[i] = a[i];
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(a[j]<a[i]) f[i] = max(f[i], f[j] + a[i]);
			}
		}
		cout<<*max_element(f,f+n)<<endl;
	}
}