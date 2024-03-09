#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		double a[n], b[n]; int f[n];
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i];
			f[i] = 1;
		} 
		for(int i=0;i<n;i++){
			for(int j = 0;j<i;j++){
				if(a[j]<a[i]&&b[j]>b[i]) f[i] = max(f[i], f[j]+1);
			}
		}
		cout<<*max_element(f,f+n)<<endl;
	}
}