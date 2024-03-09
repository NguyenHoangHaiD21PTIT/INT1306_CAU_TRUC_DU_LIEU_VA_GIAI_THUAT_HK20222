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
		vector<int>v[300];//v[i] luu trang thai mang sau buoc thu i
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]>a[j]){
					swap(a[i],a[j]);
				}
			}
			for(int k=0;k<n;k++){
				v[i].push_back(a[k]);
			}
		}
		for(int i=n-2;i>=0;i--){
			cout<<"Buoc "<<i+1<<": ";
			for(int j: v[i]){
				cout<<j<<" ";
			}
			cout<<endl;
		}
	}
}