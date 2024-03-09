#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		set<char>sc;
		while(n--){
			string s;
			cin>>s;
			for(int i = 0;i<s.size();i++){
				sc.insert(s[i]);
			}
		}
		for(auto i: sc){
			cout<<i<<" ";
		}
		cout<<endl;
	}
}