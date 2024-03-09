#include<bits/stdc++.h>
using namespace std;

string s;
int n, ok;
char c;

void kt(){
	s = string(n,'O');
}

void sinh(){
	int i = n-1;
	while(i>=0&&s[i]=='X'){
		s[i] = 'O';
		i--;
	}
	if(i==-1){
		ok = 0;
	} else {
		s[i] = 'X';
	}
}

int check(){
	int maxx=0,maxo=0;
	int cntx=0, cnto=0;
	s = s + "%";
	for(int i=0;i<s.size();i++){
		if(s[i]=='O'){
			cnto++;
			maxx=max(maxx,cntx);
			cntx=0;
		} else if (s[i]=='X'){
			cntx++;
			maxo=max(maxo,cnto);
			cnto=0;
		} else {
			maxx=max(maxx,cntx);
			maxo=max(maxo,cnto);
		}
	}
	s.pop_back();
	if(c=='X'){
		if(maxx>maxo&&maxx>=5){
			return 1;
		} else {
			return 0;
		}
	} else {
		if(maxo>maxx&&maxo>=5){
			return 1;
		} else {
			return 0;
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>c;
		kt();
		ok=1;
		while(ok==1){
			if(check()) cout<<s<<endl;
			sinh();
		}
	}
}