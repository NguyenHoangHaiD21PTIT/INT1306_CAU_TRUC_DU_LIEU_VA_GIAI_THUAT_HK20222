#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int a[1005][1005];

int main(){
	int dinh;
	cin>>dinh;
	for(int i=0;i<dinh;i++){
		for(int j = 0;j<dinh;j++){
			cin>>a[i][j];
			if(a[i][j]==1){
				ke[i+1].push_back(j+1);
			}
		}
	}
	for(int i =1;i<=dinh;i++){
		for(int j: ke[i]){
			cout<<j<<" ";
		}
		cout<<endl;
	}
}