#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long a[n];
		vector<long long>v;
		for(long long i=0;i<n;i++){
			cin>>a[i];
			v.push_back(a[i]*a[i]);
		}
		sort(v.begin(),v.end());
		int check = 0;
		for(long long i=n-1;i>=2;i--){
			int check1 = 0;//ton tai cap so co tong = v[i]
			//Kiem tra xem co cap so tong  = v[i]?
			int l = 0, r = i - 1;
			while(l<r){
				if(v[l]+v[r]==v[i]) {
					check1 = 1;
					break;
				}
				if(v[l]+v[r]<v[i]) l++;
				if(v[l]+v[r]>v[i]) r--;
			}
			if(check1==1){
				check=1;
				break;
			}
		}
		if(check==1){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
}