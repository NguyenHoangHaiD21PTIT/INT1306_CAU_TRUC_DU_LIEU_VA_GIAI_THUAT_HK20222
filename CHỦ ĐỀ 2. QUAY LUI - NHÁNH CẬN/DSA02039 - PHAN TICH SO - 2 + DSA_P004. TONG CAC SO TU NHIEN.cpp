#include<bits/stdc++.h>
using namespace std;

int n, a[100], ok, cnt;

void kt(){
	cnt = 1;
	a[1] = n;
}

void sinh(){
	int i = cnt;
	while(i>=1&&a[i] == 1) i--;
	if(i==0){
		ok =0;
	} else {
		a[i] --;
		int bu = cnt - i +1;
		cnt = i;
		int thuong = bu/a[i];
		int du = bu%a[i];
		if(thuong>0){
			while(thuong--){
				cnt++;
				a[cnt] = a[i];
			}
		}
		if(du>0){
			cnt++;
			a[cnt] = du;
		}
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
			string s="(";
			for(int i=1;i<=cnt-1;i++) s=s+to_string(a[i])+" ";
			s = s + to_string(a[cnt])+")";
			v.push_back(s);
			sinh();
		}
		cout<<v.size()<<endl;
		for(auto i: v) cout<<i<<" ";
		cout<<endl;
	}
}
