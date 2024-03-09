#include<bits/stdc++.h>
using namespace std;
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
		vector<int>ans;
		for(int i=0;i<n;i++){
			int check = 1;
			for(int j=i+1;j<n;j++){
				if(a[j]>=a[i]){
					check = 0;
					break;
				}
			}
			if(check==1){
				ans.push_back(a[i]);
			}
		}
		sort(ans.begin(), ans.end(), greater<int>());
		for(int i = 0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
}