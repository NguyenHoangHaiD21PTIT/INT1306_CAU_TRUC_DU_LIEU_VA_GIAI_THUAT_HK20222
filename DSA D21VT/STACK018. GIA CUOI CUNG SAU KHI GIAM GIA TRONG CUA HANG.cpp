#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		for(int i = 0;i<s.size();i++){
			if(s[i]==',') s[i]=' ';
		}
		stringstream ss(s);
		string token;
		vector<int>v;
		stack<int>st;
		while(ss>>token) v.push_back(stoi(token));
		int n = v.size();
		int l[n];
		for(int i = n - 1;i>=0;i--){
			while(!st.empty()&&v[i]<v[st.top()]) st.pop();
			if(st.empty()) l[i] = -1;
			else l[i] = v[st.top()];
			st.push(i);
		}
		for(int i = 0;i<n - 1;i++){
			if(l[i]==-1) cout<<v[i]<<",";
			else cout<<v[i] - l[i]<<",";
		}
		cout<<v[n-1]<<endl;
	}
}