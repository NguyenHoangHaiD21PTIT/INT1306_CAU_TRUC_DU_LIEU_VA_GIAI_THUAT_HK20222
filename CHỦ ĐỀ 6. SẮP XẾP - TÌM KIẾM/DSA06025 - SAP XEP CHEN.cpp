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
		cout<<"Buoc "<<i<<": ";
		//In trang thai mang ra
		for(int j=0;j<=i;j++){
			cout<<a[j]<<" ";
		}
		cout<<endl;
	}	
}