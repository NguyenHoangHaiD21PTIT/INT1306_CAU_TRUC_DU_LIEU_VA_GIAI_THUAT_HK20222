#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		int cnt = 1;
		stack<int>st;
		for(int i = 0;i<s.size();i++){
			if(s[i] == '('){
				st.push(cnt);
				cout<<cnt<<" ";
				cnt++;
			} else if (s[i] == ')'){
				cout<<st.top()<<" ";
				st.pop();
			}
		}
		cout<<endl;
	}
}
