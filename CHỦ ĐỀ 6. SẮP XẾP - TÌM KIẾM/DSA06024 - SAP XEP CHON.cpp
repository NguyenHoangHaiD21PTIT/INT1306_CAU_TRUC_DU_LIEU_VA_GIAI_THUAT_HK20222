#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		//Voi moi i, ta tim min trong [i+1;n-1] = x. Neu a[i]>x--> SWAP
		int p = min_element(a+i+1,a+n) - a; //Vi tri phan tu nho nhat trong [i+1;n-1]
		if(a[i]>a[p]) swap(a[i],a[p]);
		cout<<"Buoc "<<i+1<<": ";
		//In trang thai mang ra
		for(int k=0;k<n;k++){
			cout<<a[k]<<" ";
		}
		cout<<endl;
	}
}