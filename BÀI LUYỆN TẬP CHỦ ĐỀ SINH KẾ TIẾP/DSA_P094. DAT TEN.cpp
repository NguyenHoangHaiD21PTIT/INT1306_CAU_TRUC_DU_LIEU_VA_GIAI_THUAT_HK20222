#include<bits/stdc++.h>
using namespace std;

int n, k, a[100], ok;

void kt(){ 
	for(int i=0;i<k;i++) a[i] = i+1;
}

void sinh(){
	int i = k-1;
	while(i>=0&&a[i]==n - k + (i+1)) i--;
	if(i==-1) ok = 0;
	else {
		a[i]++;
		for(int j = i+1;j<k;j++) a[j] = a[j-1] + 1;
	}
}

int main(){
	int n1; cin>>n1>>k;
	set<string>ss;
	vector<string>v;
	while(n1--){
		string s;
		cin>>s;
		ss.insert(s);
	}
	for(auto i: ss) v.push_back(i);
 	n = ss.size();
	kt();
	ok=1;
	while(ok==1){
		for(int i=0;i<k;i++){
			int pos = a[i] - 1;
			cout<<v[pos]<<" ";
		}
		cout<<endl;
		sinh();
	}
}
