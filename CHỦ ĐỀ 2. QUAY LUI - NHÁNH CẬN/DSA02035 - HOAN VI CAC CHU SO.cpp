#include<bits/stdc++.h>
using namespace std;

int n, a[100];

void kt(){
	for(int i=0;i<n;i++) a[i] = i+1;
}

int main(){
	int k, n1;//k: so xau, n1: do dai xau
	cin>>k>>n1;
	n = n1;
	kt();
	vector<string>v;
	while(k--){
		string s;
		cin>>s;
		v.push_back(s);
	}
	
	//Tinh chenh lech cua day ban dau
	string to = *max_element(v.begin(),v.end());
	int x1 = stoi(to);
	string be = *min_element(v.begin(),v.end());
	int x2 = stoi(be);
	int ans = x1 - x2;
	
	//Sinh hoan vi
	vector<string>v2;
	while(next_permutation(a,a+n)!=false){
		//Xet tung cau hinh
		v2.clear();
		
		//Hoan vi tung xau
		for(int k=0;k<v.size();k++){
			string sp="";
			for(int i=0;i<n;i++){
				int pos = a[i] - 1;
				sp = sp + v[k][pos];
			}
			v2.push_back(sp);
		}
		
		//Tim max, min trong tap xau moi
		string lon = *max_element(v2.begin(),v2.end());
		int x3 = stoi(lon);
		string be = *min_element(v2.begin(),v2.end());
		int x4 = stoi(be);
		int res = x3 - x4;
		ans = min(ans, res);
	}
	cout<<ans;
}
/*6 4
5237
2753
7523
5723
5327
2537 */