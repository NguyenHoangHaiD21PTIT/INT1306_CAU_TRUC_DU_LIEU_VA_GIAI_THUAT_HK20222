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
			if(isalpha(s[i])){ //Gap toan tu thi push
				string tmp = "";
				tmp+=s[i];
				st.push(tmp);
			} else { //Gap toan hang thi tinh toan cho 2 phan tu dau stack --> Toan hang to hon --> push tro lai
				string s1 = st.top();st.pop();
				string s2 = st.top();st.pop();
				string s3 = '(' + s1 + s[i] + s2 + ')';
				st.push(s3);
			}
		}
		cout<<st.top()<<endl;
	}
}
/*
2
*+AB-CD 
*-A/BC-/AKL */