#include<bits/stdc++.h>

using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int>chan;
	vector<int>le;
	for(int i=0;i<n;i++){
		if(i%2==0){
			chan.push_back(a[i]);
		} else {
			le.push_back(a[i]);
		}		
	}
	sort(chan.begin(), chan.end());
	sort(le.begin(),le.end(), greater<int>());
	for(int i=0;i<n/2;i++){
		cout<<chan[i]<<" "<<le[i]<<" ";
	}
	if(n%2==1) cout<<chan[chan.size()-1];
}
