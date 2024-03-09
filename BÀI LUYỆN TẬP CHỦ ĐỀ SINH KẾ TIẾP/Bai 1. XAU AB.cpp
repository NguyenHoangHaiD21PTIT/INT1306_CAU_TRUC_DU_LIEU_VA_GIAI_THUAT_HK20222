#include<bits/stdc++.h>
using namespace std;

//SINH XAU NHI PHAN XUOI
int n, a[100], ok, b[100], k;//Mang a: Mang nhi phan, mang b: Mang so

void kt(){
	for(int i=0;i<n;i++){
		a[i] = 0;
	}
}

void sinh(){
	int i = n -1;
	while(i>=0&&a[i]==1){
		a[i] = 0;
		i--;
	}
	if(i==-1){
		ok = 0;
	} else {
		a[i] = 1;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		kt();
		ok=1;
		vector<string>v;
		while(ok==1){
			string s = "";
			for(int i=0;i<n;i++){
				if(a[i]==0){
					s = s+"A";
				} else {
					s = s+"B";
				}
			}
			v.push_back(s);
			sinh();
		}
		for(int i=0;i<v.size()-1;i++){
			cout<<v[i]<<",";
		}
		cout<<v[v.size()-1]<<endl;
	}
}
