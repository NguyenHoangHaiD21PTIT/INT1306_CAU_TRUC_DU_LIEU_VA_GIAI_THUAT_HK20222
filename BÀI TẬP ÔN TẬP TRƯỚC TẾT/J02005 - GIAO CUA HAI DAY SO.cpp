#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin>>n>>m;
	set<int>s1;
	set<int>s2;
	while(n--){
		int x;
		cin>>x;
		s1.insert(x);
	}
	while(m--){
		int x;
		cin>>x;
		s2.insert(x);
	}
	for(auto i: s1){
		if(s2.find(i)!=s2.end()){
			cout<<i<<" ";
		}
	}
}