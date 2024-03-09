#include<bits/stdc++.h>
using namespace std;

string to(string &s){
	for(int i=0;i<s.size();i++){
		if(s[i]=='5'){
			s[i]='6';
		}
	}
	return s;
}

string be(string &s){
	for(int i=0;i<s.size();i++){
		if(s[i]=='6'){
			s[i]='5';
		}
	}
	return s;
}

int main(){
	string s1, s2;
	cin>>s1>>s2;
	long long max1 = stol(to(s1));
	long long max2 = stol(to(s2));
	long long min1 = stol(be(s1));
	long long min2 = stol(be(s2));
	long long tongto = max1 + max2;
	long long tongbe = min1 + min2;
	cout<<tongbe<<" "<<tongto;
}