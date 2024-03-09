#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack<int>st; //stack luu vi tri cua dau mo ngoac
		st.push(-1); //phan tu co so
		int res = -1;
		for(int i = 0;i<s.size();i++){
			if(s[i]== '('){
				st.push(i);
			} else { //st.top la vi tri '('; i la vi tri ')'
				st.pop();//lui vi tri cua st.top()
				if(!st.empty()) res = max (res, i - st.top());
				else st.push(i);
			}
		}
		cout<<res<<endl;
	}
}
/*
3
((()
)()())
()(())))) */