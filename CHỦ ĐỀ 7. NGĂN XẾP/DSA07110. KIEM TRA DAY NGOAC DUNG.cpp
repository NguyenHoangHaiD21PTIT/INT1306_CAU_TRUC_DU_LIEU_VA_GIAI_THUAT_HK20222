#include<bits/stdc++.h>
using namespace std;

bool valid(char a, char b){ //Cap dong mo tuong ung
	if((a=='('&&b==')')||(a=='['&&b==']') ||(a=='{'&&b=='}')) return true;
	return false;
}

bool check(string s){
	stack<char>st;
	for(char i: s){
		if(i=='('||i=='['||i=='{'){
			st.push(i);
		} else { //Gap dau mo ngoac
			if(st.empty()) return false;//Khong co dau dong
			if(valid(st.top(),i)) st.pop(); //Cung loai --> Cho ra ngoai
			else return false; //Co dau dong nhung khong cung loai
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
		if(check(s)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
/*
2
[()]{}{[()()]()}
[(]) */