#include<bits/stdc++.h>
using namespace std;
int n, a[100], ok;
void kt(){
	for(int i=0;i<n;i++){
		a[i]=i+1;
	}
}
int check(int a[], int n){
	for(int i=0;i<n-1;i++){
		if(abs(a[i]-a[i+1])==1){
			return 0;
		}
	}
	return 1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		kt();
		//In cau hinh dau tien
		//Kiem tra con sinh duoc tiep hay khong roi in tiep
		while(next_permutation(a,a+n)!=false){
			if(check(a,n)==1){
				for(int i=0;i<n;i++){
					cout<<a[i];
				}
				cout<<endl;
			}
		}
	}
}