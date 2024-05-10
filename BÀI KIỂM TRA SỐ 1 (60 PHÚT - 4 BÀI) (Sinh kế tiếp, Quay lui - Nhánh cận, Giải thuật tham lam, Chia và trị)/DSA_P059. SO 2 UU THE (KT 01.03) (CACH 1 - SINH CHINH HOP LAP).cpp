#include<bits/stdc++.h>
using namespace std;

string s;
int k, ok;

void kt(){
	s = string(k,'0');
}

void sinh(){
	int i = k - 1;
	while(i>=0&&s[i]=='2') i--;
	if(i==-1){
		ok = 0;
	} else {
		s[i]++;
		for(int j=i+1;j<k;j++) s[j] = '0';
	}
}

int checks(){
	if(s[0]=='0') return 0;
	int cnt = 0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='2') cnt++;
	}
	int p = s.size()/2;
	if(cnt>p) return 1;
	else return 0;
}

int main(){
	int x;
	cin>>x;
	int cnt = 0;
	int check = 0;
	k = 1;
	while(1){
		kt();
		ok=1;
		while(ok==1){
			if(checks()){
				cout<<s<<" ";
				cnt++;
				if(cnt==x){
					check = 1;
					break;
				}
			}
			sinh();
		}
		if(check==1) break;
		k++;
	}
}

