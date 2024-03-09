#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack<string>st;
		for(int i = s.size()-1;i>=0;i--){
			if(isalpha(s[i])){ //Gap toan hang thi push
				string tmp = "";
				tmp+=s[i];
				st.push(tmp);
			} else { //Gap toan tu thi loi 2 toan hang dau stack, noi lai --> toan hang to hon --> push
				string s1 = st.top(); st.pop();
				string s2 = st.top(); st.pop();
				string s3 = s1 + s2 + s[i];
				st.push(s3);
			}
		}
		cout<<st.top()<<endl;
	}
}
/*
2
*+AB-CD 
*-A/BC-/AKL   */