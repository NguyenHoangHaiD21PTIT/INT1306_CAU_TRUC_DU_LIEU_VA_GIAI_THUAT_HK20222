#include<bits/stdc++.h>
using namespace std;
int main(){
	int t ; 
	cin>> t ;
	while(t--){
		int hang, cot, k;
		cin>>hang>>cot>>k;
		int a[hang][cot];
		for(int i=0;i<hang;i++){
			for(int j=0;j<cot;j++){
				cin>>a[i][j];
			}
		}
		for(int i =0;i<hang;i++){
			for(int j = i;j<hang;j++){
				if(a[i][k-1]>a[j][k-1]){
					swap(a[i][k-1],a[j][k-1]);
				}
			}
		}
		for(int i=0;i<hang;i++){
			for(int j=0;j<cot;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}