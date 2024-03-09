#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		vector<int>v[n];//v[0] la hang thu 0
		for(int i=0;i<n;i++){
			cin>>a[i];
			v[0].push_back(a[i]);
		}
		
		//In hang dau tien
		cout<<"[";
		for(int i=0;i<n-1;i++){
			cout<<a[i]<<" ";
		}
		cout<<a[n-1]<<"]";
		cout<<endl;
		
		for(int i=1;i<n;i++){
			
			//Tao hang thu i tu hang thu i - 1 bang cach lay tong doi mot
			for(int j=0;j<v[i-1].size()-1;j++){
				v[i].push_back(v[i-1][j]+v[i-1][j+1]);
			}
			
			//In hang thu i
			cout<<"[";
			for(int j = 0;j<v[i].size()-1;j++){
				cout<<v[i][j]<<" ";
			}
			cout<<v[i][v[i].size()-1]<<"]";
			cout<<endl;
		}
	}
}