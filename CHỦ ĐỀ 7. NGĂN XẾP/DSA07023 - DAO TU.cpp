#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		stringstream ss(s);
		string token;
		vector<string>v;
		while(ss>>token){
			v.push_back(token);
		}
		for(int i = v.size()-1;i>=0;i--){
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
}