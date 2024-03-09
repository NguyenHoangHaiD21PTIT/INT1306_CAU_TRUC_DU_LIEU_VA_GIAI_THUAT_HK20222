#include<bits/stdc++.h>
using namespace std;

string s;
int n, k, ok;

void kt(){
	s = string(n,'A');
}

void sinh(){
	int i = n-1;
	while(i>=0&&s[i]=='B'){
		s[i] = 'A';
		i--;
	}
	if(i==-1){
		ok = 0;
	} else {
		s[i] = 'B';
	}
}

int check(){
	int cnta=0, cntb=0;
	vector<int>v;
	s = s + "@";
	for(int i=0;i<s.size();i++){
		if(s[i]=='A'){
			cnta++;
			cntb=0;
		} else {
			cntb++;
			if(cnta==k) v.push_back(cnta);
			cnta=0;
		}
	}
	s.pop_back();
	if(v.size()==1) return 1;
	else return 0;
}

int main(){
	cin>>n>>k;
	kt();
	ok=1;
	vector<string>vs;
	while(ok==1){
		if(check()) vs.push_back(s);
		sinh();
	}
	cout<<vs.size()<<endl;
	for(auto i: vs) cout<<i<<endl;
}