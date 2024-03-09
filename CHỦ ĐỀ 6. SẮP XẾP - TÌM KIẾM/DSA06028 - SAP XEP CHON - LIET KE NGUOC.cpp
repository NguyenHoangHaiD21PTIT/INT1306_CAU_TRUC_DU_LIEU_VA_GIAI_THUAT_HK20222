#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	vector<int>v[300];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		//Voi moi i, ta tim min trong [i+1;n-1]. Neu a[i]>min --> swap(a[i],min)
		int pos = min_element(a+i+1,a+n) - a; //Vi tri phan tu min trong [i+1;n-1]
		if(a[i]>a[pos])  swap(a[i],a[pos]);
		for(int k = 0;k<n;k++){
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