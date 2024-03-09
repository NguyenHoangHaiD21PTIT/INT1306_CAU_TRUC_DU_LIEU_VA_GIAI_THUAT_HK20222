#include<bits/stdc++.h>
using namespace std;

//Su dung sap xep chon. Bao nhieu lan can doi cho thi do la dap an bai toan
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int ans = 0;
		for(int i=0;i<n-1;i++){
			//Voi moi i, ta tim min trong [i+1;n-1] = x. Neu a[i]>x thi swap
			int pos = min_element(a+i+1,a+n) - a;
			if(a[i]>a[pos]){
				swap(a[i],a[pos]);
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}