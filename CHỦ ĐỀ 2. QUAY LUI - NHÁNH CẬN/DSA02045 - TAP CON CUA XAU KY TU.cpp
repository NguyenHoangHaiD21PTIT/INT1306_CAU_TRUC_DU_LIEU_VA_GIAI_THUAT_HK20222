#include<bits/stdc++.h>
using namespace std;

//SINH XAU NHI PHAN NGUOC
int n, a[100], ok, b[100];//Mang a: Mang nhi phan, mang b: Mang so

void kt(){
	for(int i=0;i<n;i++){
		a[i] = 1;
	}
}

void sinh(){
	int i = n -1;
	while(i>=0&&a[i]==0){
		a[i] = 1;
		i--;
	}
	if(i==-1){
		ok = 0;
	} else {
		a[i] = 0;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin.ignore();
		cin>>n;
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		kt();
		ok=1;
		vector<string>v;
		while(ok==1){
			string tmp="";
			for(int i=0;i<n;i++){
				if(a[i]==1)  tmp=tmp+s[i];
			}
			if(tmp!="") v.push_back(tmp);
			sinh();
		}
		sort(v.begin(),v.end());
		for(auto i: v) cout<<i<<" ";
		cout<<endl;
	}
}