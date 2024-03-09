#include<bits/stdc++.h>
using namespace std;

int n, a[100], ok;

//Sinh chinh hop lap chap n cua 3. 
void kt(){
	for(int i=0;i<n;i++) a[i] = 1;
}

void sinh(){
	int i = n-1;
	while(i>=0&&a[i]==3) i--;
	if(i==-1){
		ok = 0;
	} else {
		a[i]++;
		for(int j=i+1;j<n;j++) a[j] = 1;
	}
}

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

int main(){
	int n1;
	cin>>n1;
	n = 3;
	string s="ABC";
	cout<<s<<endl;
	while(next_permutation(s.begin(),s.end())!=false) cout<<s<<endl;
	n = 4;
	while(n<=n1){
		kt();
		ok=1;
		while(ok==1){
			string tmp="";
			for(int i = 0;i<n;i++){
				int val = a[i] - 1;
				tmp = tmp + s[val];
			}
			if(check(tmp)) cout<<tmp<<endl;
			sinh();
		}
		n++;
	}
}