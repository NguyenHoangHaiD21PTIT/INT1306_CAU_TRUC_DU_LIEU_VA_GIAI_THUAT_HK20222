#include<bits/stdc++.h>
using namespace std;

int n, ok; //ok: co duong di den dich
int a[1000][1000];
string tmp="DLRU";
string s="";

int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};

void Try(int i, int j){
	if(i==n-1&j==n-1){
		ok = 1;
		cout<<s<<" ";
	}
	for(int k=0;k<4;k++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1>=0&&i1<=n-1&&j1>=0&&j1<=n-1&&a[i1][j1]==1){
			s = s + tmp[k];//nuoc di tuong ung
			a[i1][j1] = 0;
			Try(i1,j1);
			//Ham nao xong thi phai tra trang thai cho o do
			s.pop_back();
			a[i1][j1] = 1;
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) cin>>a[i][j];
		}
		ok = 0;
		if(a[n-1][n-1]==1){
			a[0][0] = 0;
			Try(0,0);
			if(ok==0) cout<<-1;
		} else {
			cout<<-1;
		}
		cout<<endl;
	}
}