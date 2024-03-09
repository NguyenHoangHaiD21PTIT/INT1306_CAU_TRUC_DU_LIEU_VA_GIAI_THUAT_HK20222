#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];

int main(){
	int t;
	cin>>t;
	while(t--){
		int dinh, canh;
		cin>>dinh>>canh;
		for(int i = 1;i<=dinh;i++){
			ke[i].clear();
		}
		while(canh--){
			int dau, cuoi;
			cin>>dau>>cuoi;
			ke[dau].push_back(cuoi);
			ke[cuoi].push_back(dau);
		}
		for(int i=1;i<=dinh;i++){
			sort(ke[i].begin(),ke[i].end());
		}
		for(int i = 1;i<=dinh;i++){
			cout<<i<<": ";
			for(int j: ke[i]){
				cout<<j<<" ";
			}
			cout<<endl;
		}
	}
	
}