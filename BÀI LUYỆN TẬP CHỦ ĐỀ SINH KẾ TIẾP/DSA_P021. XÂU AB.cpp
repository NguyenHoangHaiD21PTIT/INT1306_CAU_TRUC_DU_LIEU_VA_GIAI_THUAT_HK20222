#include<bits/stdc++.h>
using namespace std;

string s = ""; int n, ok;

void sinh(){
	int i = n -1;
	while(i >=0 && s[i] == 'B'){
		s[i] = 'A';
		i--;
	}
	if(i == -1) ok = 0;
	else s[i] = 'B';
}

int main(){
	int t; cin >> t;
	while(t--){
		cin >> n; s = string (n, 'A'); ok = 1;
		vector<string>v;
		while(ok == 1){
			v.push_back(s);
			sinh();
		}
		for(int i = 0;i < v.size() - 1;i++) cout << v[i] << ",";
		cout << v[v.size() - 1] << endl;
	}
}
