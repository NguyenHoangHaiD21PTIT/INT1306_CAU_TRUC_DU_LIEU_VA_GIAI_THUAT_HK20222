#include<bits/stdc++.h>
using namespace std;

int main(){
	stack<int>st;
	string s;
	int n;
	while(cin>>s){
		if(s=="push"){
			cin>>n;
			st.push(n);
		} else if (s=="pop") {
			if(st.size()!=0) st.pop();
		} else if (s=="show"){
			vector<int>v;
			if(st.size()==0){
				cout<<"empty"<<endl;
			} else {
				stack<int>copy = st;
				while(copy.size()!=0){
					int x = copy.top();
					copy.pop();
					v.push_back(x);
				}
				reverse(v.begin(),v.end());
				for(auto i: v) cout<<i<<" ";
				cout<<endl;
			}
		}
	}
}