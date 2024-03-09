#include<bits/stdc++.h>
using namespace std;

int n, a[100], ok;

//Sinh chinh hop lap chap n cua 4. Xet tat cac cac cach dien 1234 vao x1x2x3x4x5
void kt(){
	for(int i=0;i<n;i++) a[i] = 1;
}

void sinh(){
	int i = n-1;
	while(i>=0&&a[i]==4) i--;
	if(i==-1){
		ok = 0;
	} else {
		a[i]++;
		for(int j=i+1;j<n;j++) a[j] = 1;
	}
}

int check(string s){
	if(s.back()=='2') return 0;
	set<char>sc;
	for(auto i: s) sc.insert(i);
	if(sc.size()==4) return 1;
	else return 0;
}

int main(){
	int n1;
	cin>>n1;
	n = 4;
	string s="2357";
	cout<<s<<endl;
	while(next_permutation(s.begin(),s.end())!=false){
		if(s.back()!='2') cout<<s<<endl;
	}
	n = 5;
	while(n<=n1){
		kt();
		ok=1;
		while(ok==1){
			string tmp="";
			for(int i = 0;i<n;i++){
				int val = a[i] - 1;
				tmp = tmp + s[val];
			}
			if(check(tmp))cout<<tmp<<endl;
			sinh();                          
		}
		n++;
	}
}