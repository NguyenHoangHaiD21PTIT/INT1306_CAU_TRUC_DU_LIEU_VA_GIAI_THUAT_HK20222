#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		multiset<int>ms;
		for(int i=0;i<k;i++){
			ms.insert(a[i]);
		}
		cout<<*ms.rbegin()<<" ";
		for(int i=k;i<n;i++){
			ms.erase(ms.find(a[i-k]));
			ms.insert(a[i]);
			cout<<*ms.rbegin()<<" ";
		}
		cout<<endl;
	}
}
