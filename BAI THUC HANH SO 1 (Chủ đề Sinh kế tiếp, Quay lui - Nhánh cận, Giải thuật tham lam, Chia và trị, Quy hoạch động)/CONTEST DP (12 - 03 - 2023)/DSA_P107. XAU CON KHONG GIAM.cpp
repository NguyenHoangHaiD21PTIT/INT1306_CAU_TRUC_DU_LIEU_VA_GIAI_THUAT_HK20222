#include<bits/stdc++.h>
using namespace std;
int main(){
	string s; cin >> s;
	int n = s.size();
	int l[n];
	for(int i = 0; i < n; i++) l[i] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i - 1; j++){
			if(s[i] >= s[j]) l[i] = max(l[i], l[j] + 1);
		} 
	}
	cout << *max_element(l, l + n) << endl;
}
