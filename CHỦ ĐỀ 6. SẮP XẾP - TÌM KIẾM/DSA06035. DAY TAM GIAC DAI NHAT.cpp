#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int tang[n], giam[n], tgiac[n]; //tang[i] la do dai day con lien tiep tang ket thuc tai i
		//giam [i] la do dai day con lien tiep bat dau tu i (Day tang lien tiep ket thuc tai i tu ben phai sang)
		for(int i=0;i<n;i++){
			cin>>a[i];
			tang[i] = giam[i] = tgiac[n] = 1;
		} 
		for(int i=0;i<n-1;i++){
			if(a[i+1]>a[i]) tang[i+1] = tang[i] + 1;
		}
		for(int i = n-1;i>=1;i--){
			if(a[i-1]>a[i]) giam[i-1] = giam[i] + 1;
		}
		for(int i=0;i<n;i++) tgiac[i] = tang[i] + giam[i] - 1;
		cout<<*max_element(tgiac,tgiac+n)<<endl;
	}
}