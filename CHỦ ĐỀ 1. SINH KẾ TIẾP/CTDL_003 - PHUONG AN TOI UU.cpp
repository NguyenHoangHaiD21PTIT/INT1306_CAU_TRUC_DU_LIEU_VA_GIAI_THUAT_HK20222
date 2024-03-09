#include<bits/stdc++.h>
using namespace std;

int n, a[100], ok;//Mang a: Mang nhi phan, mang b: Mang so

void kt(){
	for(int i=0;i<n;i++){
		a[i] = 0;
	}
}

void sinh(){
	int i = n -1;
	while(i>=0&&a[i]==1){
		a[i] = 0;
		i--;
	}
	if(i==-1){
		ok = 0;
	} else {
		a[i] = 1;
	}
}

int main(){
	cin>>n;
	int b;//khoi luong tui
	cin>>b;
	kt();
	ok=1;
	int val[n], wei[n];
	for(int i=0;i<n;i++) cin>>val[i];
	for(int i=0;i<n;i++) cin>>wei[i];
	int ans = 0;
	vector<int>v;
	while(ok==1){
		int res_val = 0, res_wei = 0;
		for(int i=0;i<n;i++){
			if(a[i]==1){
				res_val+= val[i];
				res_wei+= wei[i];
			}
		}
		if(res_val>ans&&res_wei<=b){
			v.clear();
			ans = max(ans,res_val);
			for(int i=0;i<n;i++) v.push_back(a[i]);
		}
		sinh();
	}
	cout<<ans<<endl;
	for(auto i: v) cout<<i<<" ";
}