#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	vector<char>res;
	for(int i=0;i<s.size();i++){
		auto x = upper_bound(res.begin(), res.end(), s[i]);
		if(x==res.end()) res.push_back(s[i]);
		else *x = s[i];
	}
	cout<<res.size();
}