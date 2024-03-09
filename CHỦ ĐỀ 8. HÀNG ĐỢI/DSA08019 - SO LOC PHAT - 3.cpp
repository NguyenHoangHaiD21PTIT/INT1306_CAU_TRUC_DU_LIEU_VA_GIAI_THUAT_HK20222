#include<bits/stdc++.h>
using namespace std;

int n, ok;//ok: con sinh duoc hay khong
string s;

void kht(){
	s = string(n,'8');
}
 
void sinh(){
	int i=n-1;//xet tu bit cuoi cung
	while(i>=0&&s[i]=='6'){
		s[i]='8';
		i--;
	}
	if(i==-1){//da den xau cuoi
	    ok=0;//
	} else {
		s[i]='6';
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		vector<string>v;
		int n1;
		cin>>n1;
		n = n1;
		while(n>=1){
			kht();
			ok=1;
			while(ok==1){
				v.push_back(s);
				sinh();
			}
			n--;
		}
		cout<<v.size()<<endl;
		for(auto i: v) cout<<i<<" ";
		cout<<endl;
	}
}
		