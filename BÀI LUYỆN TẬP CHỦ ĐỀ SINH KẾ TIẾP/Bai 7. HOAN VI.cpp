#include<bits/stdc++.h>
using namespace std;
int n, a[100], ok;
void kt(){
	for(int i=0;i<n;i++){
		a[i]=i+1;
	}
}
int main(){
		cin>>n;
		kt();
		int cnt = 1;
		//In cau hinh dau tien
		cout<<"1: ";
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		//Kiem tra con sinh duoc tiep hay khong roi in tiep
		while(next_permutation(a,a+n)!=false){
			cnt++;
			cout<<cnt<<": ";
			for(int i=0;i<n;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
}
