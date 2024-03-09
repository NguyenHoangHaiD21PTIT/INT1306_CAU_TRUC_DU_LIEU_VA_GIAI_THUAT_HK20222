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
		} else { 
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
	while(t--){
		string s;
		cin>>s;
		if(check(s)) cout<<"true"<<endl;
		else cout<<"false"<<endl;
	}
}
/*
2
[()]{}{[()()]()}
[(]) */