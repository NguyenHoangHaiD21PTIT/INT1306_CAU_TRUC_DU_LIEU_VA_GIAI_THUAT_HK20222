#include<bits/stdc++.h>
using namespace std;

//SINH XAU NHI PHAN NGUOC
int n, a[100], ok, b[100], k;//Mang a: Mang nhi phan, mang b: Mang so

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
		vector<int>v;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		sort(b,b+n);
		kt();
		ok=1;
		int ans = 0;
		while(ok==1){
			int tong = 0;
			v.clear();
			for(int i=0;i<n;i++){
				if(a[i]==1)  tong+=b[i];
			}
			if(tong==k){
				for(int i=0;i<n;i++){
					if(a[i]==1) v.push_back(b[i]);
				}
				cout<<"[";
				for(int i=0;i<v.size()-1;i++){
					cout<<v[i]<<" ";
				}
				cout<<v[v.size()-1]<<"] ";
				ans++;
			}
			sinh();
		}
		if(ans==0){
			cout<<-1;
		}
		cout<<endl;
	}
}