#include<bits/stdc++.h>
using namespace std;

int f[105][105]={};

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(f, 0, sizeof(f));
		string s1, s2;
		cin>>s1>>s2;
		int n1 = s1.size(), n2 = s2.size();
		for(int i = 0;i<=n1;i++) f[i][0] = i;
		for(int i = 0;i<=n2;i++) f[0][i] = i;
		for(int i=1;i<=n1;i++){
			for(int j=1;j<=n2;j++){
				if(s1[i-1]==s2[j-1]) f[i][j] = f[i-1][j-1];
				else f[i][j] = min(f[i-1][j],min(f[i][j-1], f[i-1][j-1]))  + 1;
			}
		}
		cout<<f[n1][n2]<<endl;
	}
}