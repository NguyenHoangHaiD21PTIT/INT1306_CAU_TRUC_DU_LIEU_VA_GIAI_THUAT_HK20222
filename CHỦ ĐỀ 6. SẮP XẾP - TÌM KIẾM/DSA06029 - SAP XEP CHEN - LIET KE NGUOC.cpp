#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int>v[300];//v[i] luu trang thai mang sau buoc thu i
	for(int i=0;i<n;i++){
		int x = a[i];
		int pos = i - 1;//Tuc la se chen so x vao truoc cac so trong vi tri [0;i-1]
		while(pos>=0&&a[pos]>x){
			a[pos+1]=a[pos];
			pos--;
		}
		a[pos+1] = x;
		for(int k=0;k<=i;k++){
			v[i].push_back(a[k]);
		}
	}
	for(int i=n-1;i>=0;i--){
		cout<<"Buoc "<<i<<": ";
		for(int j: v[i]){
			cout<<j<<" ";
		}
		cout<<endl;
	}	
}