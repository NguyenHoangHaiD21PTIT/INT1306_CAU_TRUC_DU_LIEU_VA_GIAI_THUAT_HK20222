#include<bits/stdc++.h>
using namespace std;

int n, k, a[100], ok, b[100];

void kt(){
	for(int i=0;i<k;i++){
		a[i] = i+1;
	}
}

void sinh(){
	int i = k-1;
	while(i>=0&&a[i]==n - k + (i+1)){
		i--;
	}
	if(i==-1){
		ok = 0;
	} else {
		a[i]++;
		for(int j = i+1;j<k;j++){
			a[j] = a[j-1] + 1;
		}
	}
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	sort(b,b+n);
	kt();
	ok=1;
	int ans = 0;
	vector<string>v;
	while(ok==1){
		string s="";
		for(int i=0;i<k;i++){
			int pos = a[i] - 1;
			s = s + to_string(b[pos]) + " ";
		}
		v.push_back(s);
		sinh();
	}
	sort(v.begin(),v.end());
	for(auto i: v) cout<<i<<endl;
}
