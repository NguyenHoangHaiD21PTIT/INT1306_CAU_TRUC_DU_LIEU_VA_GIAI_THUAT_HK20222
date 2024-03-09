#include<bits/stdc++.h>
using namespace std;

int n, a[100], ok;

void kt(){
	for(int i=1;i<=n;i++) a[i] = 1;
}

void sinh(){
	int i = n;
	while(i>=1&&a[i]==n) i--;
	if(i==0){
		ok = 0;
	} else {
		a[i]++;
		for(int j=i+1;j<=n;j++) a[j] = 1;
	}
}

int main(){
	cin>>n;
	//Hinh thanh xau
	char c='A';
	string s1="A";
	for(int i=1;i<n;i++){
		c++;
		s1=s1+c;
	}
	//Sinh hoan vi xau chu
	vector<string>v1;
	v1.push_back(s1);
	while(next_permutation(s1.begin(),s1.end())!=false){
		v1.push_back(s1);
	}
	//Sinh chinh hop lap so
	kt();
	ok=1;
	vector<string>v2;
	while(ok==1){
		string s2 = "";
		for(int i=1;i<=n;i++) s2 = s2 + to_string(a[i]);
		v2.push_back(s2);
		sinh();
	}
	for(auto i: v1){
		for(auto j: v2){
			cout<<i<<j<<endl;
		}
	} 
}