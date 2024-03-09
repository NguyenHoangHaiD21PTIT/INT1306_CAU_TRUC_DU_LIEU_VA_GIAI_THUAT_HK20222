#include<bits/stdc++.h>
using namespace std;
int n, k, a[100], ok;

void kt(){
	for(int i=1;i<=k;i++){
		a[i]=i;
	}
}

void sinh(){
	int i=k;
	while(i>=1&&a[i]==n-k+i){
		i--;
	}
	if(i==0){
		ok=0;
	} else {
		a[i]++;
		for(int j=i+1;j<=k;j++){
			a[j]=a[j-1]+1;
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		kt();
		ok=1;
		vector<string>v;
		while(ok==1){
			string s="";
			for(int i=1;i<=k;i++) s = s+to_string(a[i]) + " ";
			v.push_back(s);
			sinh();
		}
		for(int i = v.size()-1;i>=0;i--){
			cout<<v[i]<<endl;
		}
	}
}


