#include<bits/stdc++.h>
using namespace std;

int n, a[100], ok;

void sinh(){
	int i = n - 1;
	while(i >= 0 && a[i] == 8){
		a[i] = 6;
		i--;
	}
	if(i == -1) ok = 0;
	else a[i] = 8;
}

int main(){
	int t; cin >> t;
	while(t--){
		cin >> n; ok = 1;
		for(int i = 0; i < n; i++) a[i] = 6;
		cout << pow(2, n) << endl;
		while(ok){
			for(int i = 0; i < n; i++) cout << a[i];
			cout << " "; sinh();
		}
		cout << endl;
	} 
}

