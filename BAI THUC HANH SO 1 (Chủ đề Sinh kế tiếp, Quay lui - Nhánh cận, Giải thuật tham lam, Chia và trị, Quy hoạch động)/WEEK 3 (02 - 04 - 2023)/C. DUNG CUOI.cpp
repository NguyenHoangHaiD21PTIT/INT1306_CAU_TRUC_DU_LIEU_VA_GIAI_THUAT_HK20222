#include<bits/stdc++.h>
using namespace std;

int main(){
	int n1;//so xau ban dau
	cin>>n1;
	set<string>st; // luu tap xau ban dau
	while(n1--){
		string s;
		cin>>s;
		st.insert(s);
	}
	string s2;
	cin>>s2;
	vector<string>v; //luu cac tu khac s2
	for(auto i: st){
		if(i!=s2) v.push_back(i);
	}
	for(auto i: v) cout<<i<<" ";
	cout<<s2<<endl;
	while(next_permutation(v.begin(),v.end())!=false){
		for(auto i: v) cout<<i<<" ";
		cout<<s2<<endl;
	}
}