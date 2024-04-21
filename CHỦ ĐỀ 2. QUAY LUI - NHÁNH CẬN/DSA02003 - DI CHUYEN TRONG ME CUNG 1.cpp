#include<bits/stdc++.h>
using namespace std;

int a[1005][1005];
int n, ok;//co the den dich
string s="";

int dx[2] = {1,0};
int dy[2] = {0,1};
string tmp="DR";


void Try(int i, int j){
	if(i==n-1&&j==n-1){
		ok =1;
		cout<<s<<" ";
	} 
		for(int k=0;k<2;k++){
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			if(i1>=0&&i1<=n-1&&j1>=0&&j1<=n-1&&a[i1][j1]==1){
				s=s+tmp[k];
				a[i1][j1] = 0;//o da xet tren duong di
				Try(i1,j1);
				//Backtrack lai try truoc do. Try nao thuc hien xong thi tra lai trang thai
				a[i1][j1] =1 ;
				s.pop_back();	
			}
		}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ok = 0;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j = 0;j<n;j++){
				cin>>a[i][j];
			}
		}
		if(a[n-1][n-1]==1&&a[0][0]){
			a[0][0] = 0;
			Try(0,0);
			if(ok==0) cout<<-1;
		} else {
			cout<<-1;
		}
		cout<<endl;
	}	
}
