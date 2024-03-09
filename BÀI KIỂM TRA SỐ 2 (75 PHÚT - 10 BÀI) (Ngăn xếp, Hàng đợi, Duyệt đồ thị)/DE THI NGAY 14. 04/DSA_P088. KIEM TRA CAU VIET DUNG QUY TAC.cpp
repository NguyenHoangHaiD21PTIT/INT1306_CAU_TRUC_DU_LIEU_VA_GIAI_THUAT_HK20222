#include<bits/stdc++.h>
using namespace std;

bool valid(char a, char b){ 
	if((a=='('&&b==')')||(a=='['&&b==']') ||(a=='{'&&b=='}')) return true;
	return false;
}

bool check(string s){
	stack<char>st;
	for(char i: s){
		if(i=='('||i=='['||i=='{'){
			st.push(i);
		} else if (i==')'||i==']'||i=='}'){ 
			if(st.empty()) return false;
			if(valid(st.top(),i)) st.pop(); 
			else return false; 
		}
	}
	return st.empty();
}

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin,s);
		if(check(s)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
/*
3
[ graph ] ( binary tree ).
Dynamic programming )( devide and conquer.
([ (([( [ ] ) ( ) (( ))] )) ]). */