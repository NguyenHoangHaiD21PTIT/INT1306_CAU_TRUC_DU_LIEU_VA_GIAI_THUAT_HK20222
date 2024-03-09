#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int>ans;
	for(int i=0;i<n;i++){
		auto x = lower_bound(ans.begin(),ans.end(), a[i]);
		if(x==ans.end()) ans.push_back(a[i]); 
		else *x = a[i];
	}
	cout<<ans.size();
}