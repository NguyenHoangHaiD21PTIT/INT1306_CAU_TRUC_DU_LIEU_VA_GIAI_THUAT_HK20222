#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin>>n>>k;
	int mt[110][110], a[110];
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++) cin>>mt[i][j];
	}
	//Thuc chat bai nay la sinh hoan vi, hang la i, cot la a[i] trong bai sinh hoan vi
	for(int i = 1;i<=n;i++) a[i] = i;
	vector<vector<int>>v;  vector<int>tmp; //v la mang cac vector thoa man, tmp la vector thoa man (luu chi so cot hang do)
	
	//Tinh toan cau hinh khoi tao
	int sum = 0;
	for(int i = 1;i<=n;i++) sum+=mt[i][a[i]];
	if(sum ==k){
		for(int i = 1;i<=n;i++) tmp.push_back(a[i]);
		v.push_back(tmp);
	}
	
	//Lap
	while(next_permutation(a+1, a+n+1)!=false){
		sum = 0; tmp.clear();
		for(int i = 1;i<=n;i++) sum+=mt[i][a[i]];
		if(sum ==k){
			for(int i = 1;i<=n;i++) tmp.push_back(a[i]);
			v.push_back(tmp);
		}
	}
	
	//Tra ket qua
	cout<<v.size()<<endl;
	for(int i = 0;i<v.size();i++){
		for(auto j: v[i]) cout<<j<<" ";
		cout<<endl;
	}

}