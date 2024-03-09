#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		set<int>s;
		while(n--){
			int x, y;
			char c;
			cin>>x>>y>>c;
			s.insert(x);
			s.insert(y);
		}
		for(auto i: s) cout<<i<<" ";
		cout<<endl;
	}
}