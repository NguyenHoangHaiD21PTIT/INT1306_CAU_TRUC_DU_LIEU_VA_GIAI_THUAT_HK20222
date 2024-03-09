#include<bits/stdc++.h>
using namespace std;
bool cmp(string a, string b){
	if(a.size()!=b.size()){
		return a.size()<b.size();
	}
	return a<b;
}
int main(){
	int t;
	cin>>t;
	cin.ignore();
	vector<string>v;
	while(t--){
		string s;
		cin>>s;
		s=s+"%";
		string c = "";
		for(int i=0;i<s.size();i++){
			if(isdigit(s[i])){
				c = c+s[i];
			} else {
				if(c!=""){
					v.push_back(c);
				}
				c="";
			}
		}
	}
	for(int i=0;i<v.size();i++){
		while(v[i].size()>1&&v[i][0]=='0'){
			v[i].erase(0,1);
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(auto i: v){
    	cout<<i<<endl;
	}
}