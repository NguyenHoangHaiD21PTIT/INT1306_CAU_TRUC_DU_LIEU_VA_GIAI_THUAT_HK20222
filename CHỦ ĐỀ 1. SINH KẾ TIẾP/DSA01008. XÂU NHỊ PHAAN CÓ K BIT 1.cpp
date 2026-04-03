#include<bits/stdc++.h>
using namespace std;
int n, k, a[100], ok;

void sinh(){
	int i = n - 1;
	while(i >= 0 && a[i] == 1){
		a[i] = 0;
		i--;
	}
	if(i == -1) ok = 0;
	else a[i] = 1;
}

int check(){
    int cnt = 0;
    for(int i = 0; i < n; i++) cnt += a[i];
    return cnt == k;
}

int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> k; ok = 1;
		for(int i = 0; i < n; i++) a[i] = 0; 
		while(ok){
			if(check()){
				for(int i = 0; i < n; i++) cout << a[i] << " ";
				cout << endl;
			}
			sinh();
		}
	}
}
