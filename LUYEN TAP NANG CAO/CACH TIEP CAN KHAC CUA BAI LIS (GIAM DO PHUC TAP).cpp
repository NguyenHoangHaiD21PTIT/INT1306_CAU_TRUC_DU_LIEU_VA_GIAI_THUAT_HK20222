#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		vector<int>res; 
		//res[i] luu phan tu nho nhat trong so cac phan tu lon nhat cua cac day con do dai lai i + 1
		for(int i=0;i<n;i++){
			auto x = upper_bound(res.begin(),res.end(),a[i]);
			//Tim trong res phan tu nho nhat >= a[i]
			if(x==res.end()){ //Khong co
				res.push_back(a[i]);
			} else {
				*x = a[i];
			}
		}
		int p = res.size();
		int ans = n - p;
		cout<<ans<<endl;
	}
}
