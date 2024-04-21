#include<bits/stdc++.h>
using namespace std;

int n; string s = "ABC"; vector<string>v;

int check(string s){
	int cnta = 0, cntb = 0, cntc = 0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='A') cnta++;
		else if (s[i]=='B') cntb++;
		else if (s[i]=='C') cntc++;
	}
	if(cnta!=0&&cntb!=0&&cntc!=0&&cnta<=cntb&&cntb<=cntc) return 1;
	else return 0;
}

void gen(){
	queue<string>q;
	for(char i: s){
		string tmp = ""; tmp+=i;
		q.push(tmp);
	}
	while(1){
		string x = q.front();
		q.pop();
		if(x.size()==n) break;
		for(char i: s){
			string x1 = x + i;
			q.push(x1);
			if(check(x1)&&x1.size()>=3) v.push_back(x1);
		}
	}
}

int main(){
	cin>>n;
	gen();
	for(auto i: v) cout<<i<<endl;
}
