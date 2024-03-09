#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		cin>>s;
		vector<string>v;
		for(int i=0;i<s.size();i++){
			for(int j=i;j<s.size();j++){
				string tmp = s.substr(i,j-i+1);
				v.push_back(tmp);
			}
		}
		long long ans = 0;
		for(int i=0;i<v.size();i++){
			long long p = stoll(v[i]);
			ans+=p;
		} 
		cout<<ans<<endl;
	}
}