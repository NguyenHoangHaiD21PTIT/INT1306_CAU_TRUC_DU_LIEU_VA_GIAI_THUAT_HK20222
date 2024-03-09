#include<bits/stdc++.h>
using namespace std;

int uutien(char c){ //Muc do uu tien cua toan tu
	if(c=='+'||c=='-') return 1;
	if (c=='*'||c=='/') return 2;
	if (c=='^') return 3;
	return 0;	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack<char>st;// st nay luu dau mo ngoac va toan tu
		string res ="";
		for(int i=0;i<s.size();i++){
			if(isalpha(s[i])){ //Gap toan hang --> Them vao ket qua
				res+=s[i];
			} else if (s[i]=='('){ //Gap mo ngoac thi push
				st.push(s[i]);
			} else if (s[i]==')') {
				//Gap dong ngoac thi pop het ra den khi gap mo ngoac Toan tu thi noi vao xau ket qua
				//Vut dau mo ngoac sau cung
				while(!st.empty()&&st.top()!='('){
					res+=st.top();
					st.pop();
				}
				st.pop();//xoa not dau mo ngoac cuoi cung
			} else { //Gap toan tu
				while(!st.empty()&&uutien(st.top())>=uutien(s[i])){
					res+=st.top();
					st.pop();
				}
				st.push(s[i]);
			}
		}
		while(!st.empty()){
			if(st.top()!='(') res+=st.top();
			st.pop();
		}
		cout<<res<<endl;
	}
}
/*
2
(A+(B+C)
((A*B)+C) */