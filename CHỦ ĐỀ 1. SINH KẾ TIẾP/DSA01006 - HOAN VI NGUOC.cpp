#include<bits/stdc++.h>
using namespace std;
int n, a[100], ok;
void kt(){
	for(int i=0;i<n;i++){
		a[i]=n-i;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		kt();
		//In cau hinh dau tien
		for(int i=0;i<n;i++){
			cout<<a[i];
		}
		cout<<" ";
		//Kiem tra con sinh duoc tiep hay khong roi in tiep
		while(prev_permutation(a,a+n)!=false){
			for(int i=0;i<n;i++){
				cout<<a[i];
			}
			cout<<" ";
		}
		cout<<endl;
	}
}