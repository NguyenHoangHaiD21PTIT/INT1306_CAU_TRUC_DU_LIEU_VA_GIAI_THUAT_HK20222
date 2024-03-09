#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
	    if(next_permutation(a,a+n)!=false){
	    	for(int i=0;i<n;i++){
				cout<<a[i]<<" ";
			}	
		} else {//cau hinh cuoi - > quay nguoc len cau hinh dau
			for(int i=0;i<n;i++){
				a[i]=i+1;
			}
			for(int i=0;i<n;i++){
				cout<<a[i]<<" ";
			}
		}
		cout<<endl;
	}
}