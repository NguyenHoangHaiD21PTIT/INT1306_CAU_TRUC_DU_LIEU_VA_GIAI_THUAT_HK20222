#include<bits/stdc++.h>
using namespace std;

int tknp(int a[], int n, int x){
	int l = 0;
	int r = n -1;
	while(l<=r){
		int mid = l+(r-l)/2;
		if(a[mid]==x){
			return mid;
		}
		if(a[mid]<x){//x o nua phai
			l = mid +1;
		}
		if(a[mid]>x){//x o nua trai
			r = mid -1 ;
		}
	}
	return -1;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, x;
		cin>>n>>x;
		int a[n];
		for(int i = 0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		if(tknp(a,n,x)==-1){
			cout<<"NO"<<endl;
		} else {
			cout<<tknp(a,n,x)+1<<endl;
		}
	}
}
