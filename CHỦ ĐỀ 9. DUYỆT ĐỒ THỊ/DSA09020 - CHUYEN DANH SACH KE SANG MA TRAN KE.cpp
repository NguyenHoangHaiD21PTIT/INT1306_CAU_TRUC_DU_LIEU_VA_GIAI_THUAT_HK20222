#include<bits/stdc++.h>
using namespace std;

int a[1005][1005]={};

int main(){
	int dinh;
	cin>>dinh;
	cin.ignore();
	for(int i = 1;i<=dinh;i++){
		string s;
		getline(cin, s);
		stringstream ss(s);
		string token;
		while(ss>>token){
			int x = stoi (token);
			a[x-1][i-1]=a[i-1][x-1]=1;
		}
	}
	for(int i=0;i<dinh;i++){
		for(int j = 0;j<dinh;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}