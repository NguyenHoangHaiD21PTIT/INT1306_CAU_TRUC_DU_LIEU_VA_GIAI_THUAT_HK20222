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
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
		cout<<"Buoc "<<i+1<<": ";
		//In ra trang thai mang
		for(int k=0;k<n;k++){
			cout<<a[k]<<" ";
		}
		cout<<endl;
	}
}
/*
        i j
5 8 3 9 1 4
3 8 5 9 1 4 
1 8 5 9 3 4 //b1
1 5 8 9 3 4
1 3 8 9 5 4 //b2
1 3 5 9 8 4
1 3 4 9 8 5 //b3
1 3 4 8 9 5
1 3 4 5 9 8 //b4
1 3 4 5 8 9 // b5
*/













