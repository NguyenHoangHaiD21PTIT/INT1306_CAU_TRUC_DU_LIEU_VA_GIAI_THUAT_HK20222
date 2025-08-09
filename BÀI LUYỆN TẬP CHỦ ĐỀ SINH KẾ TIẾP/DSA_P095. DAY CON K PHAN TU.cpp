#include<bits/stdc++.h>
using namespace std;
int n, k, a[100], ok, b[100];
void kt(){
	for(int i = 1; i <= k; i++) a[i] = i;
}
void sinh(){
	int i = k;
	while(i >= 1 && a[i] == n - k + i) i--;
	if(i == 0) ok = 0;
	else {
		a[i]++;
		for(int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
	}
}
int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> b[i];
	sort(b + 1, b + n + 1);
	kt(); ok = 1;
	int ans = 0;
	vector <string> v;
	while(ok == 1){
		string s = "";
		for(int i = 1; i <= k;i++) s += to_string(b[a[i]]) + " ";
		v.push_back(s);
		sinh();
	}
	sort(v.begin(), v.end());
	for(auto i: v) cout << i << endl;
}
