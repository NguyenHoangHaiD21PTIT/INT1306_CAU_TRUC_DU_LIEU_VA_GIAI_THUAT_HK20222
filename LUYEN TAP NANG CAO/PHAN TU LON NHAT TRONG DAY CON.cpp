#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		vector<int>v;
		for(int i = 0;i<s.size();i++){
			if(s[i]==',') s[i]=' ';
		}
		stringstream ss(s);
		string token;
		while(ss>>token) v.push_back(stoi(token));
		int k = v[v.size()-1];
		multiset<int>ms;
		for(int i = 0;i<k;i++) ms.insert(v[i]);
		for(int i = k;i<v.size() - 1;i++){ 
			cout<<*ms.rbegin()<<",";
			ms.erase(ms.find(v[i - k]));
			ms.insert(v[i]);
		}
		cout<<*ms.rbegin()<<endl;
	}
}